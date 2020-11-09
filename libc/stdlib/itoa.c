#include "stdlib.h"

char *reverseString(char *str, int len)
{
    for (int i = 0; i < len / 2; i++)
    {
        int backIdx = len - (i + 1);
        char tmp = str[backIdx];
        str[backIdx] = str[i];
        str[i] = tmp;
    }
    return str;
}

char *itoa(int num, char *str, int base)
{
    int i = 0;
    int isNegative = 0;

    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    // negative numbers are handled only with base 10. Otherwise numbers are considered unsigned.
    if (num < 0 && base == 10)
    {
        isNegative = 1;
        num = -num;
    }

    while (num)
    {
        int currentDigit = num % base;
        str[i++] = (currentDigit > 9) ? (currentDigit - 10) + 'a' : currentDigit + '0';
        num /= base;
    }

    if (isNegative)
        str[i] = '-';

    str = reverseString(str, i);
    str[++i] = '\0';
    return str;
}