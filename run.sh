#!/bin/bash
set -e

./clean.sh
./build.sh
./qemu.sh