---
title: lib_examples/sample_stubs.asm
manual: libraries
chapter: libraries
section: lib-examples-sample-stubs-asm
functions: []
libraries: []
---

# lib_examples/sample_stubs.asm

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

*******************************************************************************************
* sample_stubs.asm
*
* Stubs match this .fd file:
*
*       ##base _SampleBase
*       ##bias 30
*       ##public
*       Double(n1)(D0)
*       AddThese(n1,n2)(D0/D1)
*       ##end
*
* After assembling,
*   JOIN sample_stubs.o sample_lvos.o AS sample.lib
*
* Apps LINK with LIBRARY sample.lib when calling sample.library functions
*
* If you put all of your stubs in one file, as shown here, then ALL of the stubs will be
* linked into an application that references one stub.  For larger libraries, you should
* place each stub in a separate assembler file, assemble them each separately, then join
* all of the .o's together. That will allow each stub to be independently pulled into the
* application that links with the .lib.
*******************************************************************************************
   INCLUDE  "exec/types.i"
   INCLUDE  "exec/libraries.i"


          section code
*------ Caller declares and initializes SampleBase in their C code


            XREF        _SampleBase
*------ Must externally reference the _LVO labels defined in samplelib_lvos


            XREF        _LVODouble
            XREF        _LVOAddThese
*------ Make C function stubs available to caller


            XDEF        _Double
            XDEF        _AddThese
*------- These stubs move C args from stack to appropriate registers,
*------- call the library function, and return result in d0

_Double:

```c
            MOVE.L      A6,-(SP)           ;Save register(s)
            MOVE.L      8(SP),D0           ;Copy param to register
            MOVE.L      _SampleBase,A6     ;Library base to A6
            JSR         _LVODouble(A6)     ;Go to real routine
            MOVE.L      (SP)+,A6           ;Restore register(s)
            RTS
```
_AddThese:

```c
            MOVE.L      A6,-(SP)           ;Save register(s)
            MOVEM.L     8(SP),D0/D1        ;Copy params to registers
                                           ;8(SP)  goes into D0
                                           ;12(SP) goes into D1
            MOVE.L      _SampleBase,A6     ;Library base to A6
            JSR         _LVOAddThese(A6)   ;Go to real routine
            MOVE.L      (SP)+,A6           ;Restore register(s)
            RTS

          END
```
