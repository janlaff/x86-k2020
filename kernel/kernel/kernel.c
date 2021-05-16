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
#include <kernel/commandInterpreter.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

int kernelActive = true;

void kernel_main()
{
    terminal_init();

    terminal_writestring("Initializing GDT Table...\n");
    gdt_init();
    terminal_writestring("Initializing IDT Table...\n");
    idt_init();
    terminal_writestring("Enabling paging...\n");
    paging_init();
    terminal_writestring("Starting shell...\n");
    if (KB_initialize() != 0)
        terminal_writestring("Keyboard controller initialization suceeded\n");
    else {
        terminal_writestring("Keyboard controller initialization failed\n");
        return;
    }

    UT_init();

    // Doesnt work
    /*__asm__ volatile("sti");
    __asm__ volatile("mov 10, %ax");
    __asm__ volatile("divb 0");*/

    while (kernelActive) {
        int key = getchar();
        UT_handleUserInput(key);
    }
}