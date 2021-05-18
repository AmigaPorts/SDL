# Makefile to build the SDL 2 Library

CC      = ppc-morphos-gcc-10 -noixemul
INCLUDE = -I../../../../include -I../sdk
CFLAGS  = -mcpu=750 -mtune=7450 -O2 $(INCLUDE) -Wall -Wno-pointer-sign -fno-strict-aliasing -D_LARGEFILE64_SOURCE
AR	= ppc-morphos-ar

ECHE = echo -e
BOLD = \033[1m
NRML = \033[22m

COMPILING = @$(ECHE) "compiling $(BOLD)$@$(NRML)..."
LINKING = @$(ECHE) "linking $(BOLD)$@$(NRML)..."
STRIPPING = @$(ECHE) "stripping $(BOLD)$@$(NRML)..."
ARCHIVING = @$(ECHE) "archiving $(BOLD)$@$(NRML)..."

all: lib/libSDL2.a lib/libb32/libSDL2.a lib/libb32/libSDL2-nc.a

lib: all

install: all
install-iso: all

sdl-startup.o: sdl-startup.c sdl-stubs.c
	$(COMPILING)
	@$(CC) $(CFLAGS) -o $@ -c sdl-startup.c

SDL_amigagl_wrapper.o: ../../../video/amiga/SDL_amigagl_wrapper.c
	$(COMPILING)
	@$(CC) $(CFLAGS) -o $@ -c $<

sdl-startup-brel.o: sdl-startup.c sdl-stubs.c
	$(COMPILING)
	@$(CC) $(CFLAGS) -mresident32 -o $@ -c sdl-startup.c

SDL_amigagl_wrapper-brel.o: ../../../video/amiga/SDL_amigagl_wrapper.c
	$(COMPILING)
	@$(CC) $(CFLAGS) -mresident32 -o $@ -c $<

sdl-startup-brel-nc.o: sdl-startup.c sdl-stubs.c
	$(COMPILING)
	@$(CC) $(CFLAGS) -mresident32 -o $@ -c sdl-startup.c -D__NO_SDL_CONSTRUCTORS

SDL_amigagl_wrapper-nc.o: ../../../video/amiga/SDL_amigagl_wrapper.c
	$(COMPILING)
	@$(CC) $(CFLAGS) -mresident32 -o $@ -c $< -D__NO_SDL_CONSTRUCTORS

lib/libSDL2.a: sdl-startup.o SDL_amigagl_wrapper.o ../sdk/fd/sdl2_lib.fd
	$(ARCHIVING)
	@mkdir -p lib
	@-rm -f $@
	@cvinclude.pl --fd=../sdk/fd/sdl2_lib.fd --clib=../sdk/clib/sdl2_protos.h --gluelib=$@
	@$(AR) crus $@ sdl-startup.o SDL_amigagl_wrapper.o

lib/libb32/libSDL2.a: sdl-startup-brel.o SDL_amigagl_wrapper-brel.o ../sdk/fd/sdl2_lib.fd
	$(ARCHIVING)
	@mkdir -p lib/libb32
	@-rm -f $@
	@cvinclude.pl --fd=../sdk/fd/sdl2_lib.fd --clib=../sdk/clib/sdl2_protos.h --brelgluelib=$@
	@$(AR) crus $@ sdl-startup-brel.o SDL_amigagl_wrapper-brel.o

lib/libb32/libSDL2-nc.a: sdl-startup-brel-nc.o SDL_amigagl_wrapper-nc.o ../sdk/fd/sdl2_lib.fd
	$(ARCHIVING)
	@mkdir -p lib/libb32
	@-rm -f $@
	@cvinclude.pl --fd=../sdk/fd/sdl2_lib.fd --clib=../sdk/clib/sdl2_protos.h --brelgluelib=$@
	@$(AR) crus $@ sdl-startup-brel-nc.o SDL_amigagl_wrapper-nc.o

clean:
	@-rm -rf lib *.s *.o

dump:
	ppc-morphos-objdump --disassemble-all --reloc lib/libSDL2.a >lib/libSDL2.s
