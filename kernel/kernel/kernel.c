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
    terminal_writestring("Welcome to the matrix...");

    if(!strcmp("tim", "tim")) terminal_writestring("strings are equal");
    if(strcmp("hallo", "teststring")) terminal_writestring("strings aren't equal");

    const char* string = "untouched string";
    memset((void*)string, '-', 2);
    terminal_writestring(string);

}