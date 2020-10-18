#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#if defined(__linux__)
#error "You need to use an cross-compiler!!"
#endif

#if !defined(__i386__)
#error "Target of this kernel must be i386!!"
#endif

void kernel_main() {
    // TODO: VGA terminal driver
}