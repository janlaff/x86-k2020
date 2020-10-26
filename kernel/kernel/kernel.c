#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#if defined(__linux__)
#error "You need to use a cross-compiler!!"
#endif

#if !defined(__i386__)
#error "Target of this kernel must be i386!!"
#endif

#include <kernel/terminal.h>

void kernel_main() {
    terminal_init();
    uint8_t cool_greeting_colors = terminal_create_color(TERMINAL_COLOR_GREEN, TERMINAL_COLOR_BLACK);
    terminal_setcolor(cool_greeting_colors);
    terminal_writestring("Welcome to the matrix...\n");

    if(!strcmp("tim", "tim")) terminal_writestring("strings are equal\n");
    if(strcmp("hallo", "teststring")) terminal_writestring("strings aren't equal\n");

    const char* string = "untouched string\n";
    memset((void*)string, '-', 2);
    terminal_writestring(string);


    const char* buffer1 = "ttt";
    const char* buffer2 = "ttr";
    if(!memcmp(buffer1, buffer2, 2)) terminal_writestring("first two characters are equal\n");
}