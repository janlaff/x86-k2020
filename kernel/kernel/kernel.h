#ifndef KERNEL_H
#define KERNEL_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

//Low level port input/output. Read/write ONE byte from/to a port
extern void outb(uint16_t port, uint8_t val);
extern uint8_t inb(uint16_t port);


#endif