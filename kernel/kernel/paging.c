#include <kernel/paging.h>
#include <stdint.h>

#define PAGE_DIRECTORY_SIZE 1024
#define PAGE_TABLE_SIZE 1024

uint32_t page_directory[PAGE_DIRECTORY_SIZE] __attribute__((aligned(4096)));
uint32_t page_table[PAGE_TABLE_SIZE] __attribute__((aligned(4096)));

extern void load_page_directory(uint32_t*);
extern void enable_paging();

void paging_init() {
    for (int i = 0; i < PAGE_DIRECTORY_SIZE; ++i) {
        page_directory[i] = 0x00000002; // supervisor level, read/write, not present
    }

    for (unsigned int i = 0; i < PAGE_TABLE_SIZE; ++i) {
        page_table[i] = (i * 0x1000) | 0x3; // supervisor level, read/write, present
    }

    page_directory[0] = ((unsigned int)page_table) | 3;

    paging_flush();
}