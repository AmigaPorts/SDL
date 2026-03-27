---
title: lib_examples/sample_lvos.asm
manual: libraries
chapter: libraries
section: lib-examples-sample-lvos-asm
functions: []
libraries: []
---

# lib_examples/sample_lvos.asm

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

***************************************************************************
* sample_lvos.asm   _LVO definitions
*
*  This is the .fd file for our sample library:
*
* Note - the slash in (D0/D1) means that a stub-maker can use MOVEM.L to
* load these registers from the stack, rather than using a separate MOVE
* instruction for each register. Alternately, something like  (A0,D2) would
* show that a separate MOVE instruction is needed for each load.
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
***************************************************************************

   INCLUDE  "exec/types.i"
   INCLUDE  "exec/libraries.i"


          SECTION data
*----- LIBINIT initializes an LVO value to -30 to skip the first four
*----- 6-byte required library vectors (Open, Expunge, etc)


             LIBINIT
*----- LIBDEF assigns the current LVO value to a label, and then
*----- bumps the LVO value by -6 in preparation for next LVO label

*----- This assigns the value -30 to our first _LVO label


```c
             LIBDEF      _LVODouble     ;-30
             XDEF        _LVODouble
```
*----- The value -30-6 is asigned to our second _LVO label


```c
             LIBDEF      _LVOAddThese   ;-36
             XDEF        _LVOAddThese

             END
```
