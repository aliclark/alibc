
#ifdef NDEBUG
#define assert(ignore) ((void) 0)
#else
#include <stdlib.h>
#include <stdio.h>
#define assert(expression)                                  \
    do                                                      \
    {                                                       \
        if (!(expression))                                  \
        {                                                   \
            (void) fprintf(stderr,                          \
                           "%s:%d: Assertion failed.\n",    \
                           __FILE__,                        \
                           __LINE__);                       \
            abort();                                        \
        }                                                   \
    }                                                       \
    while (0)
#endif
