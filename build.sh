#!/bin/bash

nasm -felf32 kernel/arch/i386/boot.asm -o boot.o
i686-elf-gcc -c kernel/kernel/kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra