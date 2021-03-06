#include <kernel/idt.h>
#include <stdint.h>
#include <string.h>

struct idt_entry {
    uint16_t base_low;
    uint16_t selector;
    uint8_t always0;
    uint8_t flags;
    uint16_t base_high;
} __attribute__((packed));

struct idt_ptr {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed));

struct idt_entry idt[256];
struct idt_ptr idtp;

extern void gdt_flush();

void idt_set_gate(int num, uint32_t base, uint16_t selector, uint8_t flags);

void idt_init() {
    idtp.limit = (sizeof(struct idt_entry) * 256) - 1;
    idtp.base = (uint32_t)&idt;

    memset(&idt, 0, sizeof(idt));

    // TODO: add interrupt handlers
    // idt_set_gate ...

    idt_flush();
}

void idt_set_gate(int num, uint32_t base, uint16_t selector, uint8_t flags) {
    idt[num].base_low = base & 0xFFFF;
    idt[num].base_high = (base >> 32) & 0xFFFF;
    idt[num].selector = selector;
    idt[num].flags = flags;
    idt[num].always0 = 0;
}