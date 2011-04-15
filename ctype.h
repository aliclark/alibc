
#ifndef __ALIBC_CTYPE_H
#define __ALIBC_CTYPE_H

#ifdef __cplusplus
extern "C" {
#endif

int   isalnum(int);
int   isalpha(int);
int   isblank(int);
int   iscntrl(int);
int   isdigit(int);
int   isgraph(int);
int   islower(int);
int   isprint(int);
int   ispunct(int);
int   isspace(int);
int   isupper(int);
int   isxdigit(int);
int   tolower(int);
int   toupper(int);

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

#ifdef __cplusplus
}
#endif

#endif
