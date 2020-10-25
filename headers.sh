#!/bin/bash

set -e
source ./config.sh

mkdir -p "$SYSROOT"

# Copy system headers in sysroot directory
for PROJECT in $PROJECTS; do
    (cd $PROJECT && DESTDIR="$SYSROOT" $MAKE install-headers)
done