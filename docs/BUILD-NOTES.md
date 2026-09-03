# Building an AmigaOS 3 shared library — the actual recipe

Sourced from working references, not inferred. The first attempt at
`sdl2.library` was assembled from header files and `nm` output and was
wrong in most of its mechanics; this file exists so that never has to be
re-derived.

## References

- `alexalkis/library` — complete working skeleton: asm library, `.fd`,
  `.sfd`, Makefile, and testers in both asm and C.
- `alfishe/amiga-bootcamp` `04_linking_and_libraries/fd_files.md` — FD
  file format and LVO derivation.

## The build

```
alkislibrary.asm --vasmm68k_mot--> alkislibrary.o  \
                                                    >-- vlink --> alkis.library
libfunc.c        --m68k-amigaos-gcc -c--> libfunc.o /

alkis_lib.sfd    --sfdc --mode=macros--> inline.h   (caller side)
```

Exact commands:

    vasmm68k_mot -I<gcc>/m68k-amigaos/ndk-include/ -esc -Fhunk -quiet \
        alkislibrary.asm -o alkislibrary.o
    m68k-amigaos-gcc -Wall -O3 -fomit-frame-pointer -c libfunc.c -o libfunc.o
    vlink -s -o alkis.library alkislibrary.o libfunc.o
    sfdc --mode=macros alkis_lib.sfd > inline.h

## Things this corrected

- **The skeleton is ASSEMBLY, not C.** ROMTag, init table and
  Open/Close/Expunge live in `alkislibrary.asm`. Trying to write them in
  C means fighting the C startup, which is what made the first attempt
  hang inside `SDL_Init`.
- **`vlink` links the library, not `m68k-amigaos-gcc`.** It links raw
  objects, so there is no startup file to suppress and no `-nostartfiles`
  battle, and no need to define `SysBase` or `exit` by hand.
- **No stub link library is needed.** `sfdc --mode=macros` emits inline
  macros that do the register marshalling at the call site; the C tester
  just includes the generated header and links normally with `-noixemul`.
- **Library functions take REGISTER arguments** (`Func(a,b)(D0,A0)` in
  the FD), not stack arguments. Registers available: D0-D7, A0-A3.
  A6 implicitly holds the library base.
- **LVO = -(bias + n * 6)**, `##bias 30`, n counting from the first
  public function.

## Tool availability in amigadev/crosstools:m68k-amigaos

    vasmm68k_mot   present
    sfdc           present
    fd2pragma      present
    m68k-amigaos-gcc present
    vlink          MISSING  <-- the only gap

`vlink` is required by this recipe and is now SOLVED without building
it: a native Windows binary ships in vbcc, extracted to

    third_party/vbcc/vbcc/bin/vlink.exe      (V0.17a, 2022)
    third_party/vbcc/vbcc/vlink.pdf          (the manual -- read it,
                                              do not guess flags)

It runs on the HOST, not in the container. That is fine and needs no
restructuring: objects are compiled inside Docker and the link step runs
natively afterwards, which build.sh already straddles.

The from-source attempt in `third_party/vlink` is abandoned and can be
deleted; it failed on `dir.c` with `DIR` undeclared and was not worth
diagnosing once a working binary existed.

## Open question, unrelated to the above

SDL2's own functions take stack arguments, so exposing them through a
register-argument FD needs a thin marshalling wrapper per export. SDL2
ships as a DLL/.so on every other platform, so the shared-library shape
itself is not in doubt; what AmigaOS does not do for us is the C runtime
initialisation a modern loader performs automatically. That is the
skeleton's job and is the piece to get right.

## Suggested first build

One export only — `SDL_Init` — with its wrapper, `.sfd` entry and
generated header, plus a tester that opens the library and calls it.
That proves the skeleton, the link, the FD, the generated header and the
runtime init end to end through the real interface. The other 45
functions are then repetition, and nothing built for the one-function
version is thrown away.

## The skeleton, from alkislibrary.asm

    Start:  MOVEQ #-1,d0        ; running it as a program must fail
            rts                 ; MUST be the first code in the segment

    RomTag: DC.W RTC_MATCHWORD
            DC.L RomTag         ; rt_MatchTag, points at itself
            DC.L EndCode        ; rt_EndSkip
            DC.B RTF_AUTOINIT
            DC.B VERSION
            DC.B NT_LIBRARY
            DC.B MYPRI
            DC.L LibName
            DC.L IDString
            DC.L InitTable      ; because RTF_AUTOINIT

    InitTable:
            DC.L AlkisBase_SIZEOF
            DC.L funcTable
            DC.L dataTable
            DC.L initRoutine

    funcTable:
            dc.l Open, Close, Expunge, Null     ; the mandatory four
            dc.l Double, AddThese, Fib, _Triple ; exports, in ABI order
            dc.l -1                             ; terminator

Open increments LIB_OPENCNT, clears LIBF_DELEXP, returns the base in D0.
Close decrements and expunges if zero and DELEXP is set. Expunge removes
from the system list, frees memory, returns the seglist in D0.

## How C functions are exported -- THE KEY POINT

`_Triple` in that table is a C function from libfunc.c, referenced with
its leading underscore and placed in the table directly. So exports do
NOT need assembly wrappers: a C function can be a library function
provided it declares its arguments in REGISTERS, e.g.

    int Triple(register int x __asm("d0"))

That is the marshalling answer for SDL2. Each export becomes a small C
wrapper in our libfunc.c equivalent, declaring register arguments to
match the .fd, and calling the real stack-argument SDL2 function:

    int SDL2_Init(register unsigned long flags __asm("d0"))
    { return SDL_Init(flags); }

The wrapper is what goes in funcTable; SDL2's own function is untouched.

## Remaining unknowns before writing anything

- initRoutine's exact register convention (D0=base, A0=seglist, A6=SysBase
  is the usual autoinit contract, but CONFIRM from the file rather than
  assume -- this is what went wrong last time).
- dataTable contents for a library with no initialised library-base data.
- vlink invocation: the reference uses `vlink -s -o alkis.library *.o`
  with no explicit target; confirm whether -bamigahunk is needed when
  vlink runs on Windows rather than Linux.

## Linking with vlink: the fix chain (worked through, not finished)

Each of these was a distinct error with a distinct cause.

1. `Fatal error 18: ... unsupported type 0` on a symbol in libSDL2.a.
   CAUSE: GCC emits LOCAL symbols (nm shows `t`) in its hunk objects and
   vlink's reader rejects that definition type.
   FIX: strip local symbols from the archive first --
       m68k-amigaos-strip -x libSDL2.a
   This works. Keep a stripped copy rather than mutating the original.

2. `Error 19: Global symbol X already defined` for libm.a and libnix4.a.
   CAUSE: libSDL2.a already carries the libgcc soft-float routines
   (___adddf3 etc.), and libnix4.a duplicates libnix.a wholesale.
   FIX: link libnix.a ONLY -- no libm.a, no libnix4.a.

3. `INTERNAL ERROR: aoutstd_relocs() ... Reloc type ... not supported`
   on libamiga.a.
   CAUSE: /opt/.../lib/libamiga.a is a.out format; vlink cannot handle
   that reloc type. UNRESOLVED.
   LIKELY FIX: use the NDK's amiga.lib instead, which is hunk format --
   look under .../m68k-amigaos/ndk/lib/. Needed for _BeginIO,
   _CreatePort, _DeletePort.

4. Remaining undefined symbols after the above:
       ___CTOR_LIST__  ___DTOR_LIST__  ___LIB_LIST__
       ____filelist  ____stdin  ___daylight  _DOSBase
   CAUSE: these are the C runtime scaffolding a startup object normally
   provides, and a library has no startup. This is the SAME gap that
   made the first (C-based) attempt hang inside SDL_Init.
   IMPLICATION: the asm skeleton alone is not enough for a libc-dependent
   library. libnix's libinit.o exists precisely to supply this, so the
   likely correct build is asm skeleton + libinit.o together, or the
   reference skeleton extended with libnix's init data. RESOLVE THIS
   FROM DOCUMENTATION BEFORE WRITING MORE.

Note the reference project links only its own small .o files and no C
library at all, which is why none of 1-4 arise there. Wrapping a large
libc-dependent codebase is a materially harder case than the example.

## State of the build

Working: sdl2library.asm assembles (vasmm68k_mot), sdl2funcs.c compiles
(14 register-arg wrappers), sdl2_lib.fd + clib/sdl2_protos.h generate
sdl2.h via `fd2pragma --special 43`, sdl2test.c written and links nothing
of SDL2, vlink.exe runs.

Not working: the final link, blocked on items 3 and 4 above.

## RESOLVED from the libnix manual (libnix.texi, diegocr/libnix)

libinit.o IS the shared-library startup. The manual lists:

    libinit.o    shared library startup, ONE data segment for all callers
    libinitr.o   ... a NEW data segment for each task that opens it

so it is libinit.o that supplies the C runtime scaffolding a library
otherwise has none of -- the __CTOR_LIST__/__DTOR_LIST__/stdio/DOSBase
symbols that item 4 above is missing. The hand-written asm skeleton
cannot link because it REPLACED the component whose job that was.

User must supply (exact spellings from the manual):

    const BYTE LibName[]     = "simple.library";
    const BYTE LibIdString[] = "version 1.0";
    const UWORD LibVersion   = 1;
    const UWORD LibRevision  = 0;
    int  __UserLibInit(struct Library *myLib);
    void __UserLibCleanUp(void);      <-- capital U in "Up"

NOTE: the earlier C attempt wrote __UserLibCleanup (lowercase u), which
would never have been called.

### What this means for the rebuild

The FIRST approach (libinit.o) had the right component and the wrong
build: it was linked with m68k-amigaos-gcc, which meant fighting
-nostartfiles and hand-defining SysBase and exit. Those workarounds are
the likely cause of the SDL_Init hang, not libinit.o itself.

The correct combination is almost certainly:

    libinit.o + our exports + libSDL2.a (locals stripped) + libnix.a
    linked with VLINK, not gcc

with NO hand-written ROMTag, NO hand-defined SysBase, and NO exit stub --
libinit.o provides all of it. sdl2library.asm should then be deleted;
its funcTable is replaced by libinit's __FuncTable__ + ADD2LIST, and
sdl2funcs.c's register-argument wrappers are kept as-is.

The manual says "look into the examples directory for more details" but
that directory is NOT in diegocr/libnix. Finding libnix's own library
example is the one remaining lookup.

## VERSION WARNING -- read this before trusting the section above

The libnix.texi quoted above is diegocr/libnix. THAT IS NOT THE VERSION
IN OUR DOCKER IMAGE, and its signatures differ. Verified by nm and by
the image's own libinit.h:

                        diegocr manual        amigadev/crosstools image
    cleanup symbol      __UserLibCleanUp      __UserLibCleanup  (lower u)
    cleanup signature   void (void)           takes REG(a4,APTR)
    init signature      int (struct Library*) plus REG(a4,APTR)
    libinitb.o          not mentioned         present

Authoritative for THIS project:

    /opt/m68k-amigaos/m68k-amigaos/libnix/include/libinit.h
    m68k-amigaos-nm .../libnix/lib/libinit.o

    extern LONG __stdargs __UserLibInit(struct Library *,REG(a4,APTR));
    extern VOID __stdargs __UserLibCleanup(REG(a4,APTR));

The manual is still useful for CONCEPTS -- that libinit.o is the shared
library startup and libinitr.o gives per-task data -- but every symbol
name and signature must come from the image, not the manual. Several
libnix versions exist (SourceForge, Aminet 2.1-cross, adtools,
AmigaPorts, diegocr, Bebbo) and they are not interchangeable.
