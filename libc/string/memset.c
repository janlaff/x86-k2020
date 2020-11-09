#include <string.h>

void *memset(void *data, int value, size_t count)
{
    unsigned char *buffer = (unsigned char *)data;
    while (count--)
    {
        *buffer++ = value;
    }
    return data;
}