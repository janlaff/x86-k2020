CFLAGS:=$(CFLAGS) -ffreestanding -Wall -Wextra
LDFLAGS=
LIBS=-nostdlib -lgcc

OBJS = string/memcpy.o \
string/strlen.o \
string/strcmp.o \
string/memset.o \
string/memcmp.o \
stdlib/itoa.o \
stdio/printf.o \
stdio/putchar.o \
stdio/getchar.o \

.PHONY: all clean install install-headers
.SUFFIXES: .o .c

all: libk.a

libk.a: $(OBJS)
	$(AR) rcs $@ $(OBJS)

.c.o:
	$(CC) -MD -c $< -o $@ -std=c11 $(CFLAGS)

clean:
	rm -f libk.a
	rm -f $(OBJS)
	rm -f $(OBJS:.o=.d)

install: install-headers install-libs

# Copy system headers
install-headers:
	mkdir -p $(DESTDIR)$(INCLUDEDIR)
	cp -R include/* $(DESTDIR)$(INCLUDEDIR)

# Copy built kernel image
install-libs: libk.a
	mkdir -p $(DESTDIR)$(LIBDIR)
	cp libk.a $(DESTDIR)$(LIBDIR)