
#ifndef __ALIBC_STDDEF_H
#define __ALIBC_STDDEF_H

#include <stdint.h>

#ifdef __cplusplus
#define NULL 0
#else
#define NULL ((void*) 0)
#endif

#define offsetof(stype, m) FIXME_OFFSETOF

typedef unsigned int size_t;
typedef uint32_t ptrdiff_t;

#ifndef __cplusplus
typedef uint32_t wchar_t;
#endif

#endif
