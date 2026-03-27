---
title: lib_examples/easy.asm
manual: libraries
chapter: libraries
section: lib-examples-easy-asm
functions: [CloseLibrary, DisplayBeep, OpenLibrary]
libraries: [exec.library, intuition.library]
---

# lib_examples/easy.asm

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

**********************************************************************
* A complete ready-to-assemble example of how to open an Amiga function
* library in 68000 assembler.  In this case the Intuition function library
* is opened and one of its functions, DisplayBeep() is called.
*
* When calling an Amiga function, the library base pointer *must* be in
* A6 (the library is free to depend on this).  Registers D0, D1, A0
* and A1 may be destroyed by the library, all others will be preserved.
*
_AbsExecBase EQU  4          ;System pointer to Exec's library base


```c
        XREF    _LVOOpenLibrary       ;Offset from Exec base for OpenLibrary()
        XREF    _LVOCloseLibrary      ;Offset from Exec base for CloseLibrary()
        XREF    _LVODisplayBeep       ;Offset from Intuition base for DisplayBeep()

        move.l  _AbsExecBase,a6       ;Move exec.library base to a6
        lea.l   IntuiName(pc),a1      ;Pointer to "intuition.library" string
        moveq   #33,d0                ;Version of library needed
        jsr     _LVOOpenLibrary(a6)   ;Call Exec's OpenLibrary() and
        tst.l   d0                    ;check to see if it succeeded
        bne.s   open_ok
        moveq   #20,d0                ;Set failure code
        rts                           ;Failed exit
```
open_ok move.l  d0,a6                 ;Put IntuitionBase in a6.

```c
        suba.l  a0,a0                 ;Load zero into a0
        jsr     _LVODisplayBeep(a6)   ;Call Intuition's DisplayBeep()

        move.l  a6,a1                 ;Put IntuitionBase into a1
        move.l  _AbsExecBase,a6
        jsr     _LVOCloseLibrary(a6)  ;Call Exec's CloseLibrary()
        moveq   #0,d0                 ;Set return code
        rts
```
IntuiName:      dc.b 'intuition.library',0

        END

---

## See Also

- [CloseLibrary — exec.library](../autodocs/exec.library.md#closelibrary)
- [DisplayBeep — intuition.library](../autodocs/intuition.library.md#displaybeep)
- [OpenLibrary — exec.library](../autodocs/exec.library.md#openlibrary)
