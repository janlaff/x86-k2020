#if defined(__linux__)
#error "You need to use a cross-compiler!!"
#endif

#if !defined(__i386__)
#error "Target of this kernel must be i386!!"
#endif


#include "kernel.h"
#include <kernel/userTerminal.h>
#include <kernel/keyboard.h>
#include <kernel/gdt.h>
#include <kernel/idt.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Low level port input/output. Read/write ONE byte from/to a port
void outb(uint16_t port, uint8_t val)
{
    __asm__ volatile("outb %0, %1" : : "a"(val), "Nd"(port));
    /* There's an outb %al, $imm8  encoding, for compile-time constant port numbers that fit in 8b.  (N constraint).
     * Wider immediate constants would be truncated at assemble-time (e.g. "i" constraint).
     * The  outb  %al, %dx  encoding is the only option for all other cases.
     * %1 expands to %dx because  port  is a uint16_t.  %w1 could be used if we had the port number a wider C type */
}

uint8_t inb(uint16_t port)
{
    uint8_t ret;
    __asm__ volatile("inb %1, %0" : "=a"(ret) : "Nd"(port));
    return ret;
}

void kernel_main()
{
    gdt_init();
    idt_init();

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