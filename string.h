
#define __UNUSED(x) (void) n

#define __restrict /*restrict*/

typedef int __char_t;

typedef int __bool_t;
#define __false 0
#define __true  1

#define NULL 0

typedef unsigned int size_t;

char* strncpy (char* __restrict s, const char* __restrict ct, size_t n);
char* strcpy (char* __restrict s, const char* __restrict ct);
char* strncat (char* __restrict s, const char* __restrict ct, size_t n);
char* strcat (char* __restrict s, const char* __restrict ct);
int strcmp (const char* cs, const char* ct);
int strncmp (const char* cs, const char* ct, size_t n);
int strcoll (const char* cs, const char* ct);
char* strchr (const char* cs, int c);
char* strrchr (const char* cs, int c);
size_t strspn (const char* cs, const char* ct);
size_t strcspn (const char* cs, const char* ct);
char* strpbrk (const char* cs, const char* ct);
char* strstr (const char* cs, const char* ct);
size_t strlen (const char* cs);
char* strerror (int n);
char* strtok (char* s, const char* t);
size_t strxfrm (char* s, const char* ct, size_t n);
void* memcpy (void* __restrict s, const void* __restrict ct, size_t n);
void* memmove (void* s, const void* ct, size_t n);
int memcmp (const void* cs, const void* ct, size_t n);
void* memchr (const void* cs, int c, size_t n);
void* memset (void* s, int c, size_t n);
