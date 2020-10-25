#ifndef LIBC_STRING_H
#define LIBC_STRING_H

#include <stddef.h>

// copy the contents of src into the destination buffer
void* memcpy(void* dest, const void* src, size_t size);

#endif // LIBC_STRING_H
