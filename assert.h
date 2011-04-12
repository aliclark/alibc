
#include <stdio.h>
#include <stdlib.h>

#ifdef NDEBUG
#define assert(ignore)((void) 0)
#else
#define assert(expression)                             \
    do                                                 \
    {                                                  \
        if ((expression) == 0)                         \
        {                                              \
            fprintf(stderr,                            \
                    "%s:%d: Assertion failed.\n",      \
                    __FILE__,                          \
                    __LINE__);                         \
            abort();                                   \
        }                                              \
    }                                                  \
    while (0)
#endif


// void assert(int expression);
/* Macro used for internal error detection.
(Ignored if NDEBUG is defined where &lt;assert.h&gt;
is included.)  If expression equals zero, message printed on
<a href="#stderr">stderr</a> and <a href="#abort">abort</a>
called to terminate execution. Source filename and line number in message are
from preprocessor macros __FILE__ and __LINE__. */
