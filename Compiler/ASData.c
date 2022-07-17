#include "ASData.h"

// std
#include <stdio.h>
#include <string.h>

// AS
#include "ASAssert.h"

//? Should this program not abort after failed memory allocation?

// Data Block
typedef struct DataBlock {
  aschar *start;
  aschar *index;
  size_t size;
} DataBlock;

#define DATA_SIZE_INIT 64
#define DATA_SIZE_EXPANSION 64

static void *dataBlockAppendData(DataBlock *const data_block, const void *const data, const size_t data_size) {
#ifdef DEBUG
  // Error Checking
  ASSERT_RET(!data_block, "No data block was passed in!", NULL);
#endif
  // Determine Indexes
  const size_t end_index = data_block->size - sizeof(aschar);
  const size_t index_offs = data_block->index - data_block->start;
  const size_t new_index_offs = index_offs + data_size;
  // Allocate more memory
  if(new_index_offs > end_index) {
    // Allocate
    data_block->start = realloc(data_block->start, data_block->size += DATA_SIZE_EXPANSION);
    if(!data_block->start)
      abort();
    // Reposition Index
    data_block->index = data_block->start + index_offs;
  }
  // Initial Allocation
  else if(!data_block->start) {
    data_block->start = data_block->index = malloc(DATA_SIZE_INIT);
    data_block->size = DATA_SIZE_INIT;
  }
  // Copy Data
  void *ret_index = data_block->index;
  if(data) // Only copy data if ptr is not NULL - Most useful for reserving data
    memcpy(data_block->index, data, data_size);
  data_block->index = data_block->start + new_index_offs;
  return ret_index;
}

#undef DATA_SIZE_INIT
#undef DATA_SIZE_EXPANSION

// Author Script Object Bucket
// Holds Array of Variables
typedef struct ASObjBucket {
  size_t capacity; // Amount of allocated slots
  size_t consumed; // Amount of slots consumed
  ASVar *members;
} ASObjBucket;

// Add Member
#define SLOT_EXPANSION_AMOUNT 6

static ASVar *asObjBucketAppendMember(ASObjBucket *bucket, ASVar *var) {
#ifdef DEBUG
  // Error Checking
  ASSERT_RET(!bucket, "No bucket passed in!", NULL);
  ASSERT_RET(!var, "No variable passed in!", NULL);
#endif
  // Expand Memory
  if(bucket->consumed >= bucket->capacity) {
    fflush(stdout);
    bucket->members = realloc(bucket->members, sizeof(ASObjBucket) + (bucket->capacity += SLOT_EXPANSION_AMOUNT) * sizeof(ASVar));
    if(!bucket->members)
      abort();
  }
  // Append Variable
  bucket->members[bucket->consumed] = *var;
  return &bucket->members[bucket->consumed++];
}

#undef SLOT_EXPANSION_AMOUNT

// Helper Functions
static inline uint64_t rol64(uint64_t value, const uint8_t shift) {
  return (value << shift) | (value >> (sizeof(value) * 8 - shift));
}

static size_t hashCharStr(const aschar *const str, const size_t mod_by) {
  size_t hash = 0x5555555555555555; // Repeating 0101 bit pattern :3
  for(const char *index = str; *index; ++index) {
    hash ^= *index;
    hash = rol64(hash, 5);
  }
  return hash % mod_by;
}

// Author Script Object
typedef struct ASObj {
  DataBlock data_block;
  size_t bucket_count; // Do not alter after construction
  ASObjBucket buckets[];
} ASObj;
const size_t AS_OBJ_SIZE = sizeof(ASObj);

// Constructor
ASObj *asObjCreateAtMemory(void *memory, const size_t bucket_count) {
  ASObj *obj;
  if(!memory) { // Allocate memory if passed NULL
    obj = calloc(sizeof(ASObj) + (sizeof(ASObjBucket) * bucket_count), 1);
    if(!obj)
      abort();
  }
  else
    obj = memset(obj, 0, sizeof(ASObj));
  // Set members
  obj->bucket_count = bucket_count;
  return obj;
}

// Destructor
void asObjDestroy(ASObj *obj) {
  // Error Checking
  ASSERT(!obj, "Object was not passed in!");
  // Recursively Free Objects
  for(size_t i = 0; i < obj->bucket_count; i++)
    for(size_t j = 0; j < obj->buckets[i].consumed; j++) {
      ASVar *var = &obj->buckets[i].members[j];
      switch(var->type) {
        case AS_TYPE_OBJECT:
          asObjDestroy(var->data.obj);
          break;
        case AS_TYPE_FUNCTION:
          asFuncDestroy(var->data.func);
          break;
      }
    }
  // Free DataBlock
  free(obj->data_block.start);
  // Free Object
  free(obj);
}

// Add Member
ASVar *asObjSetVar(ASObj *obj, ASVar var) {
#ifdef DEBUG
  // Error Checking
  ASSERT_RET(!obj, "Object wasn't passed in!", NULL);
#endif
  // Hashing
  const size_t hash = hashCharStr(var.name, obj->bucket_count);
  ASObjBucket *bucket = &obj->buckets[hash];
  // Collision Checking
  for(size_t i = 0; i < bucket->consumed; ++i) {
    if(strcmp(bucket->members[i].name, var.name) == 0) { // If member is found, set it to argument var
      ASVar *member = &bucket->members[i];
      *member = var;
      return member;
    }
  }
  // Append Var to Bucket and return
  return asObjBucketAppendMember(bucket, &var);
}

// Find Member
ASVar *asObjFindVar(ASObj *obj, const aschar *name) {
#ifdef DEBUG
  // Error Checking
  ASSERT_RET(!obj, "Object wasn't passed in!", NULL);
#endif
  const size_t hash = hashCharStr(name, obj->bucket_count);
  ASObjBucket *bucket = &obj->buckets[hash];
  for(size_t i = 0; i < bucket->consumed; ++i) {
    if(strcmp(bucket->members[i].name, name) == 0)
      return &bucket->members[i];
  }
  return NULL;
}

// Add Data
void *asObjAddData(ASObj *obj, const void *data, const size_t data_size) {
#ifdef DEBUG
  // Error Checking
  ASSERT_RET(!obj, "No object passed in!", NULL);
#endif
  // Add String to String Block
  return dataBlockAppendData(&obj->data_block, data, data_size);
}
