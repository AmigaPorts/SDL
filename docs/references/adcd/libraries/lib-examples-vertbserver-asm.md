---
title: lib_examples/vertbserver.asm
manual: libraries
chapter: libraries
section: lib-examples-vertbserver-asm
functions: []
libraries: []
---

# lib_examples/vertbserver.asm

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

* vertbserver.asm. Example simple interrupt server for vertical blank
*
* Assembled with Howesoft Adapt 680x0 Macro Assembler Rel. 1.0
* hx68 from: vertbserver.asm to vertbserver.o INCDIR include:
* blink from lib:c.o vertb.o vertbserver.o to vertb lib lib:lc.lib lib:amiga.lib
*

    INCLUDE "exec/types.i"
    INCLUDE "hardware/custom.i"
    INCLUDE "hardware/intbits.i"

        XDEF    _VertBServer
* Entered with:       A0 == scratch (execpt for highest pri vertb server)
*  D0 == scratch      A1 == is_Data
*  D1 == scratch      A5 == vector to interrupt code (scratch)
*                     A6 == scratch
*

    section code
_VertBServer:

```c
        ADDI.L  #1,(a1)           ; increments counter is_Data points to
        MOVEQ.L #0,d0             ; set Z flag to continue to process other vb-servers
        RTS                       ;return to exec
        END
```
