---
title: A Appendix A: Linker Libraries / Amiga.lib
manual: libraries
chapter: libraries
section: a-appendix-a-linker-libraries-amiga-lib
functions: []
libraries: []
---

# A Appendix A: Linker Libraries / Amiga.lib

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This is the main Amiga scanned linker library, linked with most programs
for the Amiga.  The major components of amiga.lib are:

  * stubs        Functions for each Amiga ROM routine that copy

                 arguments from the stack to the CPU registers --
                 thereby enabling stack-based C compilers to call
                 register-based Amiga ROM routines.
  * offsets      The negative offset from the library base for each

```c
                 Amiga function. These are called Library Vector
                 Offsets (_LVO).
```
  * Exec         C functions which simplify many Exec procedures such

                 as the creation and deletion of tasks, ports, and I/O
                 request structures.
  * clib         C support functions including pseudo-random number

                 generation and a limited set of file and stdio
                 functions designed to work directly with AmigaDOS file
                 handles.
  * Math         C functions which provide some basic conversions to

```c
                 and from Fast Floating Point (FFP) format numbers.
```
  * Graphics     C support functions to add and remove tasks from the

                 vertical-blanking interval interrupt server chain.
  * ARexx        C support functions for ARexx variable handling and

```c
                 message checking.

    NOTE:
    -----
    The Timer, Commodities, and Intuition support functions listed below
    are valid only for use with Release 2.04 (V37) or a later version of
    the system software.
```
  * Timer        C support functions to do common timer device

                 operations.
  * Commodities  C functions which support the Commodities system.

                 Included are functions to deal with ToolTypes, and to
                 create various Commodities objects.
  * Intuition    Functions which provide support for Intuition's hook

                 and Boopsi sub-systems.
Most applications link with and use at least one function in amiga.lib.
The functions available are as follows.

 [Exec Support](libraries/a-amiga-lib-exec-support.md)      [Math](libraries/a-amiga-lib-math.md)          [Arexx](libraries/a-amiga-lib-arexx.md)      [Commodities](libraries/a-amiga-lib-commodities.md) 
 [Clib](libraries/a-amiga-lib-clib.md)              [Graphics](libraries/a-amiga-lib-graphics.md)      [Timer](libraries/a-amiga-lib-timer.md)      [Intuition](libraries/a-amiga-lib-intuition.md) 

