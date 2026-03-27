---
title: 1 Introduction / About the Examples
manual: hardware
chapter: hardware
section: 1-introduction-about-the-examples
functions: []
libraries: []
---

# 1 Introduction / About the Examples

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The examples in this book all demonstrate direct manipulation of the Amiga
hardware.  However, as a general rule, it is not permissible to directly
access the hardware in the Amiga unless your software either has full
control of the system, or has arbitrated via the OS for exclusive access
to the particular parts of the hardware you wish to control.

Almost all of the hardware discussed in this manual, most notably the
Blitter, Copper, playfield, sprite, CIA, trackdisk, and system control
hardware, are in either exclusive or arbitrated use by portions of the
Amiga OS in any running Amiga system.  Additional hardware, such as the
audio, parallel, and serial hardware, may be in use by applications which
have allocated their use through the system software.

Before attempting to directly manipulate any part of the hardware in the
Amiga's multitasking environment, your application must first be granted
exclusive access to that hardware by the operating system library, device,
or resource which arbitrates its ownership.  The operating system
functions for requesting and receiving control of parts of the Amiga
hardware are varied and are not within the scope of this manual.
Generally such functions, when available, will be found in the library,
device, or resource which manages that portion of the Amiga hardware in
the multitasking environment.  The following list will help you to find
the appropriate operating system functions or mechanisms which may exist
for arbitrated access to the hardware discussed in this manual.


   Hardware component            Amiga system module that controls it
   ------------------            ------------------------------------
   Copper, Playfield, Sprite, Blitter................graphics.library
   Audio.................................................audio.device
   Trackdisk..........................trackdisk.device, disk.resource
   Serial................................serial.device, misc.resource
   Parallel..............parallel.device, cia.resource, misc.resource
   Gameport.............input.device, gameport.device, potgo.resource
   Keyboard.............................input.device, keyboard.device
   System Control.........graphics.library, exec.library (interrupts)


Most of the examples in this book use the hw_examples.i file (see
 [Appendix I](hardware/hard-examples-hw-examples-i.md) ) to define the chip register names.  Hw_examples.i
uses the system include file hardware/custom.i to define the chip
structures and relative addresses. The values defined in hardware/custom.i
and hw_examples.i are offsets from the base of the chip register address
space. In general, this base value is defined as _custom and is resolved
during linking with the linker library amiga.lib.  (_ciaa and _ciab are
also resolved in this way.)

Normally, the base address is loaded into an address register and the
offsets given by hardware/custom.i and hw_examples.i are then used to
access the correct register.  (One exception to this rule is the Copper
which uses only the offset access the registers.)

For example, in assembler:



```c
        INCLUDE "exec/types.i"
        INCLUDE "hardware/custom.i"

        XREF    _custom                 ; External reference...
```
Start:  lea     _custom,a0              ; Use a0 as base register and


```c
        move.w  #$7FFF,intena(a0)       ; use the name intena as an offset
                                        ; to disable all interrupts
```
In C, you would use the structure definitions in hardware/custom.h For
example:


  #include        "exec/types.h"
  #include        "hardware/custom.h"

  extern  struct  Custom  custom;

  /* You may need to define the above external as
  **  extern struct Custom far custom;
  **  Check you compiler manual.
  */

  main()
  {
```c
      custom.intena = 0x7FFF;         /* Disable all interrupts */
```
  }


The Amiga hardware include files are generally supplied with your compiler
or assembler.  Listings of the hardware include files may also be found in
the Amiga ROM Kernel Manual: Includes and Autodocs. Generally, the include
file label names are very similar to the equivalent hardware register list
names with the following typical differences.

*  Address registers which have low word and high word components are
   generally listed as two word sized registers in the hardware register
   list, with each register name containing either a suffix or embedded
   "L" or "H" for low and high.  The include file label for the same
   register will generally treat the whole register as a longword (32 bit)
   register, and therefore will not contain the "L" or "H" distinction.

*  Related sequential registers which are given individual names with
   number suffixes in the hardware register list, are generally referenced
   from a single base register definition in the include files.  For
   example, the color registers in the hardware list (COLOR00, COLOR01,
   etc.) would be referenced from the "color" label defined in
   hardware/custom.i (color+0, color+2, etc.).

*  Examples of how to define the correct register offset can be found in
   the hw_examples.i file listed in  [Appendix I](hardware/hard-examples-hw-examples-i.md) .

Except as noted, 68000 assembly language examples have been assembled
under the Innovatronics CAPE assembler V2.x, the HiSoft Devpac assembler
V1.2, and the Lake Forest Logic ADAPT assembler 1.0.  No substantial
changes should be required to switch between assemblers.

