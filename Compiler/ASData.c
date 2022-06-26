#include "ASData.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

//? Should this program not abort after failed memory allocation?

#define ERROR_MSG(msg)                                                                                                                 \
  fprintf(stderr, "%s Error: \"%s\"\n", __func__, msg);                                                                                \
  fflush(stderr);

#define ASSERT(condition, msg)                                                                                                         \
  if(condition) {                                                                                                                      \
    ERROR_MSG(msg);                                                                                                                    \
    return;                                                                                                                            \
  }

#define ASSERT_RET(condition, msg, default_return)                                                                                     \
  if(condition) {                                                                                                                      \
    ERROR_MSG(msg);                                                                                                                    \
    return default_return;                                                                                                             \
  }

// String Block
typedef struct StringBlock { //* All associated functions will need reworks if aschar changes underlying type
  aschar *start;
  aschar *index;
  size_t size;
} StringBlock;

// Append String - Returns NULL if a String Couldn't be Appended
#define STR_SIZE_INIT 64
#define STR_SIZE_EXPANSION 64

static aschar *strBlockAppendString(StringBlock *const str_block, const aschar *const str_to_app) {
#ifdef DEBUG
  // Error Checking
  ASSERT_RET(!str_block, "No string block was passed in!", NULL);
  ASSERT_RET(!str_to_app, "No string was passed in!", NULL);
  ASSERT_RET(str_to_app[0] == 0, "Passed in string was not viable for appending!", NULL);
#endif
  // Determine Indexes
  const size_t str_to_app_length = strlen(str_to_app);                     // Length of string to append
  size_t end_index = str_block->size - sizeof(aschar);                     // The last allocated character's index
  size_t index_offs = str_block->index - str_block->start;                 // Index before appending
  size_t new_index_offs = index_offs + str_to_app_length + sizeof(aschar); // Index after appending
  // Allocate More Memory
  if(new_index_offs > end_index) {
    // Allocate
    str_block->start = realloc(str_block->start, str_block->size += STR_SIZE_EXPANSION);
    if(!str_block->start)
      abort();
    // Reposition Index
    str_block->index = str_block->start + index_offs;
  }
  // Initial Allocation
  else if(!str_block->start) {
    str_block->start = str_block->index = malloc(STR_SIZE_INIT);
    str_block->size = STR_SIZE_INIT;
  }
  // Copy String
  aschar *ret_index = str_block->index;
  strcpy(str_block->index, str_to_app);
  str_block->index = str_block->start + new_index_offs;
  return ret_index;
}

#undef STR_SIZE_INIT
#undef STR_SIZE_EXPANSION

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

// Author Script Object
typedef struct ASObj {
  StringBlock str_block;
  size_t bucket_count; // Do not alter after construction
  ASObjBucket buckets[];
} ASObj;

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

// Constructor
ASObj *asObjCreate(const size_t bucket_count) {
  ASObj *obj = calloc(sizeof(ASObj) + (sizeof(ASObjBucket) * bucket_count), 1);
  if(!obj)
    abort();
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
      if(var->type == AS_TYPE_OBJECT)
        asObjDestroy(var->data.obj);
    }
  // Free String Block
  free(obj->str_block.start);
  // Free Object
  free(obj);
}

// Add Member
ASVar *asObjSetVar(ASObj *obj, ASVar var) {
  // Error Checking
  ASSERT_RET(!obj, "Object wasn't passed in!", NULL);
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
  const size_t hash = hashCharStr(name, obj->bucket_count);
  ASObjBucket *bucket = &obj->buckets[hash];
  for(size_t i = 0; i < bucket->consumed; ++i) {
    if(strcmp(bucket->members[i].name, name) == 0)
      return &bucket->members[i];
  }
  return NULL;
}

// Add String
aschar *asObjAddString(ASObj *obj, const aschar *str) {
  // Error Checking
  ASSERT_RET(!obj, "No object passed in!", NULL);
  ASSERT_RET(!str, "No string passed in!", NULL);
  ASSERT_RET(str[0] == 0, "Not a viable string to add!", NULL);
  // Add String to String Block
  return strBlockAppendString(&obj->str_block, str);
}