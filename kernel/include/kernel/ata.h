#ifndef KERNEL_ATA_H
#define KERNEL_ATA_H

#include <stdint.h>

void ata_read_sectors(uint32_t address, uint8_t count, uint8_t* buffer);
void ata_write_sectors(uint32_t address, uint8_t count, uint8_t* buffer);

#endif