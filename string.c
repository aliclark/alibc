
#include <assert.h>
#include <limits.h>
#include <string.h>

#define __UNUSED(x) ((void) n)

typedef int __char_t;

#ifdef __cplusplus
typedef bool __bool_t;
#define __false false
#define __true  true
#else
typedef int __bool_t;
#define __false 0
#define __true  1
#endif

static size_t __str_spn (const char *s1, const char *s2, __bool_t chk)
{
    __bool_t table[CHAR_MAX] = { __false };
    size_t i = 0;
    char c;

    assert(s1 != NULL);
    assert(s2 != NULL);

    while (__true)
    {
        c = *s2++;

        if (c == '\0')
        {
            break;
        }
        table[(int) c] = __true;
    }

    while ((table[(int) s1[i]] == chk) && (s1[i] != '\0'))
    {
        ++i;
    }

    return i;
}

void* memchr (const void* cs, int c, size_t n)
{
    const char* csc = (const char*) cs;
    size_t i = 0;

    assert((n == 0) || (cs != NULL));

    for (; i != n; ++i)
    {
        if (csc[i] == c)
        {
            return (void*) (csc + i);
        }
    }

    return NULL;
}

int memcmp (const void* cs, const void* ct, size_t n)
{
    __char_t sc;
    const char* csc = (const char*) cs;
    const char* ctc = (const char*) ct;
    int diff;
    size_t i = 0;

    assert((n == 0) || (cs != NULL));
    assert((n == 0) || (ct != NULL));

    for (; i != n; ++i)
    {
        sc = csc[i];
        diff = sc - ctc[i];

        if (diff < 0)
        {
            return -1;
        }
        if (diff > 0)
        {
            return 1;
        }
    }

    return 0;
}

void* memcpy (void* __restrict s, const void* __restrict ct, size_t n)
{
    char* sc = (char*) s;
    const char* ctc = (const char*) ct;
    size_t i   = 0;

    assert((n == 0) || (s  != NULL));
    assert((n == 0) || (ct != NULL));

    for (; i != n; ++i)
    {
        sc[i] = ctc[i];
    }

    return s;
}

/* todo: fixme */
void* memmove (void* s, const void* ct, size_t n)
{
    char* sc = (char*) s;
    const char* ctc = (const char*) ct;
    size_t i   = 0;

    assert((n == 0) || (s  != NULL));
    assert((n == 0) || (ct != NULL));

    for (; i != n; ++i)
    {
        sc[i] = ctc[i];
    }

    return s;
}

void* memset (void* s, int c, size_t n)
{
    char*  sc = (char*) s;
    size_t i  = 0;

    assert((n == 0) || (s != NULL));

    for (; i != n; ++i)
    {
        sc[i] = c;
    }

    return s;
}

char* strcat (char* __restrict s, const char* __restrict ct)
{
    assert(s  != NULL);
    assert(ct != NULL);

    (void) strcpy(s + strlen(s), ct);

    return s;
}

char* strchr (const char* cs, int c)
{
    size_t i = 0;
    __char_t tmp;

    assert(cs != NULL);

    while (__true)
    {
        tmp = cs[i];

        if (tmp == c)
        {
            return (char*) cs + i;
        }

        if (tmp == '\0')
        {
            return NULL;
        }

        ++i;
    }
}

int strcmp (const char* cs, const char* ct)
{
    __char_t sc;
    int diff;

    assert(cs != NULL);
    assert(ct != NULL);

    do
    {
        sc = *cs++;
        diff = sc - *ct++;

        if (diff < 0)
        {
            return -1;
        }
        if (diff > 0)
        {
            return 1;
        }
    }
    while (sc != '\0');

    return 0;
}

int strcoll (const char* cs, const char* ct)
{
    return strcmp(cs, ct);
}

char* strcpy (char* __restrict s, const char* __restrict ct)
{
    char* sp = s;
    __char_t tmp;

    assert(s  != NULL);
    assert(ct != NULL);

    do
    {
        tmp = *ct++;
        *sp++ = tmp;
    }
    while (tmp != '\0');

    return s;
}

size_t strcspn (const char *s1, const char *s2)
{
    return __str_spn(s1, s2, __false);
}

char* strerror (int n)
{
    static const char* strerror_message = "I'm sorry about your problem.";
    __UNUSED(n);
    return (char*) strerror_message;
}

size_t strlen (const char* cs)
{
    assert(cs != NULL);

    return strchr(cs, '\0') - cs;
}

char* strncat (char* __restrict s, const char* __restrict ct, size_t n)
{
    size_t i = 0;
    char* sp;
    __char_t tmp;

    assert((n == 0) || (s  != NULL));
    assert((n == 0) || (ct != NULL));

    sp = s + strlen(s);

    while (__true)
    {
        if (i == n)
        {
            sp[i] = '\0';
            break;
        }

        tmp = ct[i];
        sp[i++] = tmp;

        if (tmp == '\0')
        {
            break;
        }
    }

    return s;
}

int strncmp (const char* cs, const char* ct, size_t n)
{
    __char_t sc;
    int diff;
    size_t i = 0;

    assert((n == 0) || (cs != NULL));
    assert((n == 0) || (ct != NULL));

    for (; i != n; ++i)
    {
        sc = cs[i];
        diff = sc - ct[i];

        if (diff < 0)
        {
            return -1;
        }
        if (diff > 0)
        {
            return 1;
        }

        if (sc == '\0')
        {
            break;
        }
    }

    return 0;
}

char* strncpy (char* __restrict s, const char* __restrict ct, size_t n)
{
    size_t i = 0;
    char* sp = s;
    __char_t tmp;

    assert((n == 0) || (s  != NULL));
    assert((n == 0) || (ct != NULL));

    while (__true)
    {
        if (i == n)
        {
            goto ret;
        }

        tmp = ct[i];
        sp[i++] = tmp;

        if (tmp == '\0')
        {
            break;
        }
    }

    while (i != n)
    {
        sp[i++] = '\0';
    }

ret:
    return s;
}

/* very similar to strspn */
char *strpbrk (const char* s1, const char* s2)
{
    __bool_t table[CHAR_MAX] = { __false };
    size_t i = 0;
    char c, b;

    assert(s1 != NULL);
    assert(s2 != NULL);

    while (__true)
    {
        c = *s2++;

        if (c == '\0')
        {
            break;
        }
        table[(int) c] = __true;
    }

    while (__true)
    {
        b = s1[i];

        if (table[(int) b] == __true)
        {
            return (char*) s1 + i;
        }

        if (b == '\0')
        {
            return NULL;
        }

        ++i;
    }
}

char* strrchr (const char* cs, int c)
{
    char* prev;
    char* rv;

    assert(cs != NULL);

    prev = strchr(cs, c);

    if ((prev == NULL) || (c == '\0'))
    {
        return prev;
    }

    do
    {
        rv = prev;
        prev = strchr(prev + 1, c);
    }
    while (prev != NULL);

    return rv;
}

size_t strspn (const char* s1, const char* s2)
{
    return __str_spn(s1, s2, __true);
}

char* strstr (const char* cs, const char* ct)
{
    size_t len;

    assert(cs != NULL);
    assert(ct != NULL);

    len = strlen(ct);

    if (len == 0)
    {
        return (char*) cs;
    }

    for (; *cs != '\0'; ++cs)
    {
        if (strncmp(cs, ct, len) == 0)
        {
            return (char*) cs;
        }
    }

    return NULL;
}

char *strtok (char* __restrict s1, const char* __restrict s2)
{
    static char* __restrict strtok_s1 = NULL;

    size_t sub;
    char* sb;
    char* tok;

    assert(s2 != NULL);

    if (s1 == NULL)
    {
        s1 = strtok_s1;

        if (s1 == NULL)
        {
            return NULL;
        }
    }

    sub = strspn(s1, s2);

    if (sub == 0)
    {
        return NULL;
    }

    tok = s1 + sub;
    sb = strpbrk(tok, s2);

    if (sb == NULL)
    {
        strtok_s1 = NULL;
        return tok;
    }
    else
    {
        *sb = '\0';
        strtok_s1 = sb + 1;
        return tok;
    }
}

size_t   strxfrm(char *__restrict, const char *__restrict, size_t);

#ifdef __CX
char    *stpcpy(char *__restrict, const char *__restrict);
char    *stpncpy(char *__restrict, const char *__restrict, size_t);
int      strcoll_l(const char *, const char *, locale_t);
char    *strdup(const char *);
char    *strerror_l(int, locale_t);
int      strerror_r(int, char *, size_t);
char    *strndup(const char *, size_t);
size_t   strnlen(const char *, size_t);
char    *strsignal(int);
char    *strtok_r(char *__restrict, const char *__restrict, char **__restrict);
size_t   strxfrm_l(char *__restrict, const char *__restrict,
                   size_t, locale_t);
#endif

#ifdef __XSI
void    *memccpy(void *__restrict, const void *__restrict, int, size_t);
#endif
