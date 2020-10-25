#ifndef TERMINAL_H
#define TERMINAL_H

#include <stdint.h>
#include <stddef.h>

void terminal_init();
void terminal_color(uint8_t color);
void terminal_setentry(size_t x, size_t y, uint8_t color, unsigned char c);
void terminal_putchar(char c);
void terminal_write(const char* data, size_t size);
void terminal_writestring(const char* data);

#endif // TERMINAL_H