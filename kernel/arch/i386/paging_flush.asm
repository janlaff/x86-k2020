section .text
global paging_flush
extern page_directory
paging_flush:
    mov eax, page_directory
    mov cr3, eax ; cr3 points to the page directory
    
    mov eax, cr0
    or eax, 0x80000000 ; enable paging by setting the 32th bit of the CR0 register, the paging bit
    mov cr0, eax
    ret