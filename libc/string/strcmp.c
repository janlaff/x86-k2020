#include <string.h>

int strcmp(const char *str1, const char *str2)
{
    return strlcmp(str1, str2, strlen(str1));
}

int strlcmp(const char *str1, const char *str2, int n)
{
    int i = 0;
    while (*str1 && (*str1++ == *str2++) && i++ < n);
    return i - n;
}