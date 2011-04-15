
#ifndef __ALIBC_STDLIB_H
#define __ALIBC_STDLIB_H

#include <stddef.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define RAND_MAX     32767

#define MB_CUR_MAX   ((size_t) 1)

#define __restrict /*restrict*/

typedef void* div_t;
typedef void* ldiv_t;
typedef void* lldiv_t;

#ifdef __cplusplus
extern "C" {
#endif

void          _Exit(int);
void          abort(void);
int           abs(int);
int           atexit(void (*)(void));
double        atof(const char *);
int           atoi(const char *);
long          atol(const char *);
long long     atoll(const char *);
void         *bsearch(const void *, const void *, size_t, size_t,
                      int (*)(const void *, const void *));
void         *calloc(size_t, size_t);
div_t         div(int, int);
void          exit(int);
void          free(void *);
char         *getenv(const char *);
int           getsubopt(char **, char *const *, char **);
long          labs(long);
ldiv_t        ldiv(long, long);
long long     llabs(long long);
lldiv_t       lldiv(long long, long long);
void         *malloc(size_t);
int           mblen(const char *, size_t);
size_t        mbstowcs(wchar_t *__restrict, const char *__restrict, size_t);
int           mbtowc(wchar_t *__restrict, const char *__restrict, size_t);
void          qsort(void *, size_t, size_t, int (*)(const void *,
                                                    const void *));
int           rand(void);
void         *realloc(void *, size_t);
void          srand(unsigned);
double        strtod(const char *__restrict, char **__restrict);
float         strtof(const char *__restrict, char **__restrict);
long          strtol(const char *__restrict, char **__restrict, int);
long double   strtold(const char *__restrict, char **__restrict);
long long     strtoll(const char *__restrict, char **__restrict, int);
unsigned long strtoul(const char *__restrict, char **__restrict, int);
unsigned long long
strtoull(const char *__restrict, char **__restrict, int);
int           system(const char *);
size_t        wcstombs(char *__restrict, const wchar_t *__restrict, size_t);
int           wctomb(char *, wchar_t);

#ifdef __CX
#include <sys/wait.h>
char         *mkdtemp(char *);
int           mkstemp(char *);
int           setenv(const char *, const char *, int);
int           unsetenv(const char *);
#endif

#ifdef __XSI
long          a64l(const char *);
double        drand48(void);
double        erand48(unsigned short [3]);
int           grantpt(int);
char         *initstate(unsigned, char *, size_t);
long          jrand48(unsigned short [3]);
char         *l64a(long);
void          lcong48(unsigned short [7]);
long          lrand48(void);
long          mrand48(void);
long          nrand48(unsigned short [3]);
int           posix_openpt(int);
char         *ptsname(int);
int           putenv(char *);
long          random(void);
char         *realpath(const char *__restrict, char *__restrict);
unsigned short *seed48(unsigned short [3]);
void          setkey(const char *);
char         *setstate(char *);
void          srand48(long);
void          srandom(unsigned);
int           unlockpt(int);
#endif

#ifdef __ADV
int           posix_memalign(void **, size_t, size_t);
#endif

#ifdef __OB_CX
int           rand_r(unsigned *);
#endif

#ifdef __cplusplus
}
#endif

#endif
