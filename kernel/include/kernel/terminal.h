#ifndef KERNEL_TERMINAL_H
#define KERNEL_TERMINAL_H

#include <stdint.h>
#include <stddef.h>

#define TERMINAL_WIDTH 80
#define TERMINAL_HEIGHT 25

extern size_t terminal_row;
extern size_t terminal_column;
extern uint8_t terminal_color;

enum terminal_color {
	TERMINAL_COLOR_BLACK = 0,
	TERMINAL_COLOR_BLUE = 1,
	TERMINAL_COLOR_GREEN = 2,
	TERMINAL_COLOR_CYAN = 3,
	TERMINAL_COLOR_RED = 4,
	TERMINAL_COLOR_MAGENTA = 5,
	TERMINAL_COLOR_BROWN = 6,
	TERMINAL_COLOR_LIGHT_GREY = 7,
	TERMINAL_COLOR_DARK_GREY = 8,
	TERMINAL_COLOR_LIGHT_BLUE = 9,
	TERMINAL_COLOR_LIGHT_GREEN = 10,
	TERMINAL_COLOR_LIGHT_CYAN = 11,
	TERMINAL_COLOR_LIGHT_RED = 12,
	TERMINAL_COLOR_LIGHT_MAGENTA = 13,
	TERMINAL_COLOR_LIGHT_BROWN = 14,
	TERMINAL_COLOR_WHITE = 15,
};

void terminal_init();
void terminal_setcolor(uint8_t color);
void terminal_setentry(size_t x, size_t y, uint8_t color, unsigned char uc);
void terminal_putchar(char c);
void terminal_write(const char* data, size_t size);
void terminal_writestring(const char* data);
void terminal_clear();
void terminal_move_cursor(size_t x, size_t y);
uint8_t terminal_create_color(enum terminal_color fg, enum terminal_color bg);

#endif // KERNEL_TERMINAL_H