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
    terminal_init();

    printf("Initializing GDT Table...\n");
    gdt_init();
    printf("Initializing IDT Table...\n");
    idt_init();
    printf("Enabling paging...\n");
    paging_init();
    printf("Starting shell...\n");

    UT_init();

    if (KB_initialize() != 0)
    {
        printf("Keyboard controller initialization suceeded\n");
    }

    while (true) {
        int key = getchar();
        UT_handleUserInput(key);
    }
}