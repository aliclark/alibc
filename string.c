
#include <assert.h>
#include "string.h"

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

char* strcat (char* __restrict s, const char* __restrict ct)
{
    assert(s  != NULL);
    assert(ct != NULL);

    (void) strcpy(s + strlen(s), ct);

    return s;
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

int strcoll (const char* cs, const char* ct)
{
    return strcmp(cs, ct);
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

/* Returns length of prefix of cs which consists of characters which are in ct. */
size_t strspn(const char* cs, const char* ct);

/* Returns length of prefix of cs which consists of characters which are not in ct. */
size_t strcspn(const char* cs, const char* ct);

/* Returns pointer to first occurrence in cs of any character of ct, or <a href="#string.NULL">NULL</a> if none is found. */
char* strpbrk (const char* cs, const char* ct);

/* Returns pointer to first occurrence of ct within cs, or <a href="#string.NULL">NULL</a> if none is found. */
char* strstr (const char* cs, const char* ct);

size_t strlen (const char* cs)
{
    assert(cs != NULL);

    return strchr(cs, '\0') - cs;
}

/* Returns pointer to implementation-defined message string corresponding with error n. */
char* strerror(int n);

/* Searches s for next token delimited by any character from ct.  Non-<a href="#string.NULL">NULL</a> s indicates the first call of a sequence.  If a token is found, it is NUL-terminated and returned, otherwise <a href="#string.NULL">NULL</a> is returned.  ct need not be identical for each call in a sequence. */
char* strtok (char* s, const char* t);

/* Stores in s no more than n characters (including terminating NUL) of a string produced from ct according to a locale-specific transformation.  Returns length of entire transformed string. */
size_t strxfrm(char* s, const char* ct, size_t n);

void* memcpy (void* __restrict s, const void* __restrict ct, size_t n)
{
    char* sc = s;
    const char* ctc = ct;
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
    char* sc = s;
    const char* ctc = ct;
    size_t i   = 0;

    assert((n == 0) || (s  != NULL));
    assert((n == 0) || (ct != NULL));

    for (; i != n; ++i)
    {
        sc[i] = ctc[i];
    }

    return s;
}

int memcmp (const void* cs, const void* ct, size_t n);
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
    }

    return 0;
}

void* memchr (const void* cs, int c, size_t n)
{
    const char* csc = cs;
    size_t i = 0;

    assert((n == 0) || (cs != NULL));

    for (; i != n; ++i)
    {
        if (csc[i] == c)
        {
            return (void*) csc + i;
        }
    }

    return NULL;
}

void* memset (void* s, int c, size_t n)
{
    char*  sc = s;
    size_t i  = 0;

    assert((n == 0) || (s != NULL));

    for (; i != n; ++i)
    {
        sc[i] = c;
    }

    return s;
}
