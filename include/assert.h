
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
            (void) fputs(__FILE__, stderr);                 \
            (void) fputc(':',      stderr);                 \
            (void) fprintf(stderr, "%d", __LINE__);         \
            (void) fputs(": Assertion failed.\n", stderr);  \
            abort();                                        \
        }                                                   \
    }                                                       \
    while (0)
#endif
