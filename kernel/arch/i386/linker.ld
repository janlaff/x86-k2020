/* Tells the bootloader where the code execution should start */
ENTRY(_start)

SECTIONS
{
    /* The kernel will be loaded at address 1 MiB by the bootloader */
    . = 1M;

    /* Multiboot + Code section */
    .text BLOCK(4K) : ALIGN(4K)
    {
        *(.multiboot)
        *(.text)
    }

    /* Read only data section */
    .rodata BLOCK(4K) : ALIGN(4K)
    {
        *(.rodata)
    }

    /* Normal data section */
    .data BLOCK(4K) : ALIGN(4K)
    {
        *(.data)
    }

    /* Uninitialized memory (stack) and others section */
    .bss BLOCK(4K) : ALIGN(4K)
    {
        *(COMMON)
        *(.bss)
    }
}