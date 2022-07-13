#ifndef _ASASSERT_H_
#define _ASASSERT_H_

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

#endif // _ASASSERT_H_