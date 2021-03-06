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

    ;call setup_page_tables
    ;call enable_paging
    ;mov dword [0xB8000], 0x2F4B2F4F ; print OK

    ; Endless loop
    cli
.hang:
    hlt
    jmp .hang
.end:

; reference: https://wiki.osdev.org/Setting_Up_Paging
; This sets the following flags to the pages:
;   Supervisor (0): Only kernel-mode can access them
;   Write Enabled (1): It can be both read from and written to
;   Not Present (0): The page table is not present
setup_page_tables:
    xor ecx, ecx
    ; set the page directory flags of each entry
.clear_page_directory:
    mov [page_directory + ecx * 4], dword 0x00000002
    inc ecx
    cmp ecx, 1024
    jle .clear_page_directory

    ; fill the page table with addressed the MMU can map the memory to
    xor ecx, ecx
.fill_page_table:
    ; since the address is page aligned, 12 bits will allways be left zero for the page attributes
    mov eax, ecx
    mov ebx, 0x1000
    mul ebx
    ; attributes: supervisor level, read/write, present
    or eax, 3
    mov [page_table + ecx * 4], dword eax
    inc ecx
    cmp ecx, 1024
    jle .fill_page_table

    ; set the first entry of the page directory to the address of the newly created page table
    mov eax, dword page_table
    ; attributes: supervisor level, read/write, present
    or eax, 3
    mov [page_directory], eax
    ret

enable_paging:
    mov eax, page_directory
    mov cr3, eax ; cr3 points to the page directory
    
    mov eax, cr0
    or eax, 0x80000000 ; enable paging by setting the 32th bit of the CR0 register, the paging bit
    mov cr0, eax
    ret
    