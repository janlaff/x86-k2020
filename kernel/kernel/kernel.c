#if defined(__linux__)
#error "You need to use a cross-compiler!!"
#endif

#if !defined(__i386__)
#error "Target of this kernel must be i386!!"
#endif

#include <kernel/userTerminal.h>
#include <kernel/keyboard.h>
#include <kernel/gdt.h>
#include <kernel/idt.h>
#include <kernel/paging.h>
#include <kernel/io.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

void kernel_main()
{
    gdt_init();
    idt_init();
    paging_init();

    KB_initialize();
    UT_init();

    UT_printLine("Welcome to the matrix...\n");

    if (!strcmp("tim", "tim"))
        UT_printLine("strings are equal\n");
    if (strcmp("hallo", "teststring"))
        UT_printLine("strings aren't equal\n");

    const char *string = "untouched string\n";
    memset((void *)string, '-', 2);
    UT_printLine(string);

    char buf[129];
    itoa(129, buf, 10);
    UT_printLine(buf);
    UT_printLine("\n");

    const char *buffer1 = "ttt";
    const char *buffer2 = "ttr";
    if (!memcmp(buffer1, buffer2, 2))
        UT_printLine("first two characters are equal\n");


    while (true) {
        int key = getchar();
        UT_handleUserInput(key);
    }

}