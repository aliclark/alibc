
#ifndef __ALIBC_STRING_H
#define __ALIBC_STRING_H

#include <stddef.h>

#define __restrict /*restrict*/

#ifdef __cplusplus
extern "C" {
#endif

void    *memchr(const void *, int, size_t);
int      memcmp(const void *, const void *, size_t);
void    *memcpy(void *__restrict, const void *__restrict, size_t);
void    *memmove(void *, const void *, size_t);
void    *memset(void *, int, size_t);
char    *strcat(char *__restrict, const char *__restrict);
char    *strchr(const char *, int);
int      strcmp(const char *, const char *);
int      strcoll(const char *, const char *);
char    *strcpy(char *__restrict, const char *__restrict);
size_t   strcspn(const char *, const char *);
char    *strerror(int);
size_t   strlen(const char *);
char    *strncat(char *__restrict, const char *__restrict, size_t);
int      strncmp(const char *, const char *, size_t);
char    *strncpy(char *__restrict, const char *__restrict, size_t);
char    *strpbrk(const char *, const char *);
char    *strrchr(const char *, int);
size_t   strspn(const char *, const char *);
char    *strstr(const char *, const char *);
char    *strtok(char *__restrict, const char *__restrict);
size_t   strxfrm(char *__restrict, const char *__restrict, size_t);

#ifdef __CX
#include <locale.h>
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

#ifdef __cplusplus
}
#endif

#endif
