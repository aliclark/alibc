
#define __restrict restrict

typedef int __char_t;

typedef int __bool_t;
#define __false 0
#define __true  1

#define NULL 0

typedef unsigned int size_t;
/* Type for objects declared to store result of sizeof operator. */

char* strcpy(char* s, const char* ct);
/* Copies ct to s including terminating NUL and returns s. */
char* strncpy(char* s, const char* ct, <a href="#string.size_t">size_t</a> n);
/* Copies at most n characters of ct to s.  Pads with NUL characters if ct is of length less than n.  <strong>Note that this may leave s without NUL-termination.</strong>  Return s. */
char* strcat(char* s, const char* ct);
/* Concatenate ct to s and return s. */
char* strncat(char* s, const char* ct, <a href="#string.size_t">size_t</a> n);
/* Concatenate at most n characters of ct to s.  NUL-terminates s and return it. */
int strcmp(const char* cs, const char* ct);
/* Compares cs with ct, returning negative value if cs&lt;ct, zero if cs==ct, positive value if cs&gt;ct. */
int strncmp(const char* cs, const char* ct, <a href="#string.size_t">size_t</a> n);
/* Compares at most (the first) n characters of cs and ct, returning negative value if cs&lt;ct, zero if cs==ct, positive value if cs&gt;ct. */
int strcoll(const char* cs, const char* ct);
/* Compares cs with ct according to locale, returning negative value if cs&lt;ct, zero if cs==ct, positive value if cs&gt;ct. */
char* strchr(const char* cs, int c);
/* Returns pointer to first occurrence of c in cs, or <a href="#string.NULL">NULL</a> if not found. */
char* strrchr(const char* cs, int c);
/* Returns pointer to last occurrence of c in cs, or <a href="#string.NULL">NULL</a> if not found. */
<a href="#string.size_t">size_t</a> strspn(const char* cs, const char* ct);
/* Returns length of prefix of cs which consists of characters which are in ct. */
<a href="#string.size_t">size_t</a> strcspn(const char* cs, const char* ct);
/* Returns length of prefix of cs which consists of characters which are not in ct. */
char* strpbrk(const char* cs, const char* ct);
/* Returns pointer to first occurrence in cs of any character of ct, or <a href="#string.NULL">NULL</a> if none is found. */
char* strstr(const char* cs, const char* ct);
/* Returns pointer to first occurrence of ct within cs, or <a href="#string.NULL">NULL</a> if none is found. */
<a href="#string.size_t">size_t</a> strlen(const char* cs);
/* Returns length of cs. */
// <a name="strerror">char* strerror(int n);</a>
/* Returns pointer to implementation-defined message string corresponding with error n. */
char* strtok(char* s, const char* t);
/* Searches s for next token delimited by any character from ct.  Non-<a href="#string.NULL">NULL</a> s indicates the first call of a sequence.  If a token is found, it is NUL-terminated and returned, otherwise <a href="#string.NULL">NULL</a> is returned.  ct need not be identical for each call in a sequence. */
<a href="#string.size_t">size_t</a> strxfrm(char* s, const char* ct, <a href="#string.size_t">size_t</a> n);
/* Stores in s no more than n characters (including terminating NUL) of a string produced from ct according to a locale-specific transformation.  Returns length of entire transformed string. */
void* // <a name="memcpy">memcpy</a>(void* s, const void* ct, <a href="#string.size_t">size_t</a> n);
/* Copies n characters from ct to s and returns s.  <strong>s may be corrupted if objects overlap.</strong> */
void* memmove(void* s, const void* ct, <a href="#string.size_t">size_t</a> n);
/* Copies n characters from ct to s and returns s.  <strong>s will not be corrupted if objects overlap.</strong> */
int memcmp(const void* cs, const void* ct, <a href="#string.size_t">size_t</a> n);
/* Compares at most (the first) n characters of cs and ct, returning negative value if cs&lt;ct, zero if cs==ct, positive value if cs&gt;ct. */
void* memchr(const void* cs, int c, <a href="#string.size_t">size_t</a> n);
/* Returns pointer to first occurrence of c in first n characters of cs, or <a href="#string.NULL">NULL</a> if not found. */
void* memset(void* s, int c, <a href="#string.size_t">size_t</a> n);
/* Replaces each of the first n characters of s by c and returns s. */
