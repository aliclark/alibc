
int isprint(int c)
{
    return (c >= ' ') && (c <= '~');
}

int islower(int c)
{
    return (c >= 'a') && (c <= 'z');
}

int isupper(int c)
{
    return (c >= 'A') && (c <= 'Z');
}

int isdigit(int c)
{
    return (c >= '0') && (c <= '9');
}

int isspace(int c)
{
    return (c == ' ') ||
        (c == '\f') ||
        (c == '\n') ||
        (c == '\r') ||
        (c == '\t') ||
        (c == '\v');
}

int iscntrl(int c)
{
    return (c == 0) || (c == 31) || (c == 127);
}

int isxdigit(int c)
{
    return isdigit(c) ||
        ((c >= 'A') && (c <= 'F')) ||
        ((c >= 'a') && (c <= 'f'));
}

int isalpha(int c)
{
    return isupper(c) || islower(c);
}

int isalnum(int c)
{
    return isalpha(c) || isdigit(c);
}

int isgraph(int c)
{
    return isprint(c) && !isspace(c);
}

int ispunct(int c)
{
    return isgraph(c) && !isalpha(c);
}

int tolower(int c)
{
    return isupper(c) ? c - 32 : c;
}

int toupper(int c);
{
    return islower(c) ? c + 32 : c;
}
