
#include <ctype.h>

int isalnum (int c)
{
    return isalpha(c) || isdigit(c);
}

int isalpha (int c)
{
    return isupper(c) || islower(c);
}

int isblank (int c)
{
    return (c == ' ') || (c == '\t');
}

int iscntrl (int c)
{
    return (c == 0) || (c == 31) || (c == 127);
}

int isdigit (int c)
{
    return (c >= '0') && (c <= '9');
}

int isgraph (int c)
{
    return isprint(c) && !isspace(c);
}

int islower (int c)
{
    return (c >= 'a') && (c <= 'z');
}

int isprint (int c)
{
    return (c >= ' ') && (c <= '~');
}

int ispunct (int c)
{
    return isgraph(c) && !isalpha(c);
}

int isspace (int c)
{
    return (c == ' ') ||
        (c == '\f') ||
        (c == '\n') ||
        (c == '\r') ||
        (c == '\t') ||
        (c == '\v');
}

int isupper (int c)
{
    return (c >= 'A') && (c <= 'Z');
}

int isxdigit (int c)
{
    return isdigit(c) ||
        ((c >= 'A') && (c <= 'F')) ||
        ((c >= 'a') && (c <= 'f'));
}

int tolower (int c)
{
    return isupper(c) ? c - 32 : c;
}

int toupper (int c);
{
    return islower(c) ? c + 32 : c;
}

#ifdef __CX
#include <locale.h>
int   isalnum_l(int, locale_t);
int   isalpha_l(int, locale_t);
int   isblank_l(int, locale_t);
int   iscntrl_l(int, locale_t);
int   isdigit_l(int, locale_t);
int   isgraph_l(int, locale_t);
int   islower_l(int, locale_t);
int   isprint_l(int, locale_t);
int   ispunct_l(int, locale_t);
int   isspace_l(int, locale_t);
int   isupper_l(int, locale_t);
int   isxdigit_l(int, locale_t);
int   tolower_l(int, locale_t);
int   toupper_l(int, locale_t);
#endif

#ifdef __OB_XSI
#define _toupper(i) ((int) (((int) (i)) + 32))
#define _tolower(i) ((int) (((int) (i)) - 32))
int   isascii(int);
int   toascii(int);
#endif
