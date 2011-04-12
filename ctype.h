
int isalnum(int c);
/* isalpha(c) or isdigit(c) */
int isalpha(int c);
/* isupper(c) or islower(c) */
int iscntrl(int c);
/* is control character.  In ASCII, control characters are 0x00 (NUL) to 0x1F (US), and 0x7F (DEL) */
int isdigit(int c);
/* is decimal digit */
int isgraph(int c);
/* is printing character other than space */
int islower(int c);
/* is lower-case letter */
int isprint(int c);
/* is printing character (including space).  In ASCII, printing characters are 0x20 (' ') to 0x7E ('~') */
int ispunct(int c);
/* is printing character other than space, letter, digit */
int isspace(int c);
/* is space, formfeed, newline, carriage return, tab, vertical tab */
int isupper(int c);
/* is upper-case letter */
int isxdigit(int c);
/* is hexadecimal digit */
int tolower(int c);
/* return lower-case equivalent */
int toupper(int c);
/* return upper-case equivalent */

