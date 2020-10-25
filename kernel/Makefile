CFLAGS:=$(CFLAGS) -ffreestanding -Wall -Wextra
LDFLAGS=
LIBS=-nostdlib -lgcc

# Fixed architecture, only i386 is supported
ARCHDIR=arch/i386

include $(ARCHDIR)/make.config

OBJS=$(KERNEL_ARCH_OBJS) kernel/kernel.o
LINK_LIST=$(LDFLAGS) $(OBJS) $(LIBS)

.PHONY: all clean install install-headers
.SUFFIXES: .o .c .asm

all: x86-k2020.bin

x86-k2020.bin: $(OBJS) $(ARCHDIR)/linker.ld
	$(CC) -T $(ARCHDIR)/linker.ld -o $@ $(CFLAGS) $(LINK_LIST)

.c.o:
	$(CC) -MD -c $< -o $@ -std=c11 $(CFLAGS)

.asm.o:
	$(NASM) -felf32 $< -o $@

clean:
	rm -f x86-k2020.bin
	rm -f $(OBJS)
	rm -f $(OBJS:.o=.d)

install: install-headers install-kernel

# Copy system headers
install-headers:
	mkdir -p $(DESTDIR)$(INCLUDEDIR)
	cp -R include/* $(DESTDIR)$(INCLUDEDIR)

# Copy built kernel image
install-kernel: x86-k2020.bin
	mkdir -p $(DESTDIR)$(BOOTDIR)
	cp x86-k2020.bin $(DESTDIR)$(BOOTDIR)