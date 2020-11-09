#include <string.h>

void *memcpy(void *dest, const void *src, size_t size)
{
    unsigned char *destination = (unsigned char *)dest;
    const unsigned char *source = (const unsigned char *)src;

    // copy src buffer into destination and return the destbuffer
    for (size_t i = 0; i < size; i++)
    {
        destination[i] = source[i];
    }
    return dest;
}