#!/bin/bash

# TODO: add libc
export PROJECTS="kernel"

export SYSROOT="$(pwd)/sysroot"
export INCLUDEDIR="/usr/include"
export BOOTDIR="/boot"

export MAKE="make"
export NASM="nasm"
export CC="i686-elf-gcc --sysroot=$SYSROOT -isystem=$INCLUDEDIR"
export CFLAGS="-std=c11 -O2"