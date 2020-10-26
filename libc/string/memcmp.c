#include <string.h>

int memcmp(const void* p1, const void* p2, int size)
{
    const unsigned char* data1 = (const unsigned char*)p1;
    const unsigned char* data2 = (const unsigned char*)p2;
    while (size--)
    {
        if (*data1++ != *data2++)
            return *--data1 - *--data2;
    }
    return 0;
}