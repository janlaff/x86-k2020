#include <string.h>

size_t strlen(const char *string)
{
    int length = 0;
    while (string[length])
    {
        length++;
    }
    return length;
}