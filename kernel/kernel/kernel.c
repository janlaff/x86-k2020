#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#if defined(__linux__)
#error "You need to use an cross-compiler!!"
#endif

#if !defined(__i386__)
#error "Target of this kernel must be i386!!"
#endif

// TODO: correct kernel include paths
#include <kernel/terminal.h>

void kernel_main() {
    /*terminal_init();
    terminal_writestring("Booting X86-K2020 Kernel...");*/
}