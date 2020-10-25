#!/bin/bash

export PROJECTS="libc kernel"

export SYSROOT="$(pwd)/sysroot"
export INCLUDEDIR="/usr/include"
export BOOTDIR="/boot"
export LIBDIR="/usr/lib"

export MAKE="make"
export NASM="nasm"
export CC="i686-elf-gcc --sysroot=$SYSROOT -isystem=$INCLUDEDIR"
export AR="i686-elf-ar"
export CFLAGS="-std=c11 -O2"