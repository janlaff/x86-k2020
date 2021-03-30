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
    UT_init();

    UT_printLine("Initializing GDT Table...\n");
    gdt_init();
    UT_printLine("Initializing IDT Table...\n");
    idt_init();
    UT_printLine("Enabling paging...\n");
    paging_init();

    UT_printLine("System finished booting up.");

    while (true) {
        int key = getchar();
        UT_handleUserInput(key);
    }

}