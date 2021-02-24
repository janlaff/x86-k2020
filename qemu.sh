#!/bin/bash
set -e
source ./config.sh
qemu-system-i386 -kernel $SYSROOT$BOOTDIR/x86-k2020.bin -no-reboot -no-shutdown