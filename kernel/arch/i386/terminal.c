#include <kernel/terminal.h>
#include <string.h>

// Fixed constants for standard vga mode
static const size_t TERMINAL_WIDTH = 80;
static const size_t TERMINAL_HEIGHT = 25;
static uint16_t* const TERMINAL_MEMORY = (uint16_t*)0xB8000;

// terminal_init() must be called to initialize these values
static size_t terminal_row;
static size_t terminal_column;
static uint8_t terminal_color;
static uint16_t* terminal_buffer;

inline uint16_t create_entry(unsigned char c, uint8_t color) {
    return (uint16_t)c | (uint16_t)color << 8;
}

void terminal_init() {
    terminal_row = 0;
    terminal_column = 0;
    terminal_color = terminal_create_color(TERMINAL_COLOR_LIGHT_GREY, TERMINAL_COLOR_BLACK);
    terminal_buffer = TERMINAL_MEMORY;
    terminal_clear();
}

void terminal_setcolor(uint8_t color) {
    terminal_color = color;
}

void terminal_setentry(size_t x, size_t y, uint8_t color, unsigned char uc) {
    const size_t index = y * TERMINAL_WIDTH + x;
    terminal_buffer[index] = create_entry(uc, color);
}

void terminal_putchar(char c) {
    if (c == '\n') {
        terminal_row++;
        terminal_column = 0;
    }
    else {
        terminal_setentry(terminal_column++, terminal_row, terminal_color, (unsigned char)c);
    }
    if (terminal_column == TERMINAL_WIDTH) {
        terminal_column = 0;
        if (++terminal_row == TERMINAL_HEIGHT) {
            terminal_row = 0;
        }
    }
}

void terminal_write(const char* data, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        terminal_putchar(data[i]);
    }
}

void terminal_writestring(const char* data) {
    terminal_write(data, strlen(data));
}

void terminal_clear() {
    for (size_t y = 0; y < TERMINAL_HEIGHT; ++y) {
        for (size_t x = 0; x < TERMINAL_WIDTH; ++x) {
            const size_t index = y * TERMINAL_WIDTH + x;
            terminal_buffer[index] = create_entry(' ', terminal_color);
        }
    }
}

uint8_t terminal_create_color(enum terminal_color fg, enum terminal_color bg) {
    return fg | bg << 4;
}