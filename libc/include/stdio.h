#ifndef LIBC_STDIO_H
#define LIBC_STDIO_H

// prints a formatted string on stdout
int printf(const char *format, ...);

// prints a single char on stdout
int putchar(int c);

// get a single character from the keyboard
extern char getchar();

#endif