#include <stdio.h>
#include <kernel/userTerminal.h>

int putchar(int c)
{
    UT_putchar((char)c);
    return c;
}