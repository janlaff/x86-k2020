#!/bin/bash

nasm -felf32 kernel/arch/i386/boot.asm -o boot.o
i686-elf-gcc -c kernel/kernel/kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -T kernel/arch/i386/linker.ld -o x86-k2020.bin -ffreestanding -O2 -nostdlib boot.o kernel.o -lgcc