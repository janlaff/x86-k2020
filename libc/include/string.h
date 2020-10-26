#ifndef LIBC_STRING_H
#define LIBC_STRING_H

#include <stddef.h>

// copy the contents of src into the destination buffer
void* memcpy(void* dest, const void* src, size_t size);

// returns the length of a null terminated string
size_t strlen(const char* string);

// compares two strings and returns 0 if they are equal
int strcmp(const char* str1, const char* str2);

// sets the first n bytes of a pointer to the specified value
void* memset(void* data, int value, size_t count);

#endif // LIBC_STRING_H
