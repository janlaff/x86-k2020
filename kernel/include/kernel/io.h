#ifndef KERNEL_IO_H
#define KERNEL_IO_H

#include <stdint.h>

void outb(uint16_t port, uint8_t val);
uint8_t inb(uint16_t port);

#endif