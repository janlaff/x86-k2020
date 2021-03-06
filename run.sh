#!/bin/bash
set -e

./build.sh
./qemu.sh
./clean.sh
