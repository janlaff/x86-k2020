; Various constants needed for the multiboot header
MBALIGN  equ 1 << 0
MEMINFO  equ 1 << 1
FLAGS    equ MBALIGN | MEMINFO
MAGIC    equ 0x1BADB002
CHECKSUM equ -(MAGIC + FLAGS)

; The first bytes of the kernel are the ones of the multiboot section
; They allow the bootloader to identify the boot options of the kernel
section .multiboot
align 4
    dd MAGIC
    dd FLAGS
    dd CHECKSUM

; The kernel stack (16 KiB) is allocated in this section
section .bss
align 4096      ; page size 4KB
page_directory:
    resb 4096
page_table:
    resb 4096
stack_bottom:
    resb 16386
stack_top:

section .text
global kernelActive
global _start:function (_start.end - _start)
_start:
    ; Disable interrupts
    cli
    ; Initialize the esp register with the stack starting address
    mov esp, stack_top

    ; Define C starting point
    extern kernel_main
    ; Call into the c code
    call kernel_main

    ; Endless loop
    cli
.hang:
    
    jmp .hang
.end: