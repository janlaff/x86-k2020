#ifndef KERNEL_INTERRUPT_H
#define KERNEL_INTERRUPT_H

// TODO: implement pic driver
struct interrupt_frame {
    uint16_t ip;
    uint16_t cs;
    uint16_t flags;
    uint16_t sp;
    uint16_t ss;
};

#endif