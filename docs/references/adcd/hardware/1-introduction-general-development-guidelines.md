---
title: 1 Introduction / General Development Guidelines
manual: hardware
chapter: hardware
section: 1-introduction-general-development-guidelines
functions: [AllocMem, Delay, WaitTOF]
libraries: [dos.library, exec.library, graphics.library]
---

# 1 Introduction / General Development Guidelines

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Amiga is available in a variety of models and configurations, and is
further diversified by a wealth of add-on expansion peripherals and
processor replacements.  In addition, even standard Amiga hardware such as
the keyboard and floppy disks, are supplied by a number of different
manufacturers and may vary subtly in both their timing and in their
ability to perform outside of their specified capabilities.

The Amiga operating system is designed to operate the Amiga hardware
within spec, adapt to different hardware and RAM configurations, and
generally provide upward compatibility with any future hardware upgrades
or "add ons" envisioned by the designers. For maximum upward
compatibility, it is strongly suggested that programmers deal with the
hardware through the commands and functions provided by the Amiga
operating system.

If you find it necessary to program the hardware directly, then it is your
responsibility to write code which will work properly on various models and
configurations.  Be sure to properly request and gain control of the
hardware you are manipulating, and be especially careful in the following
areas:

*  The environment of the Amiga computer is quite different than that of
   many other systems.  The Amiga is a multitasking platform, which
   means multiple programs can run on a single machine simultaneously.
   However, for multitasking to work correctly, care must be taken to
   ensure that programs do not interfere with one another.  It also
   means that certain guidelines must be followed during programming.

*  Remember that memory, peripheral configurations, and ROMs differ
   between models and between individual systems.  Do not make
   assumptions about memory address ranges, storage device names, or the
   locations of system structures or code.  Never call ROM routines
   directly.  Beware of any example code you find that calls routines at
   addresses in the $F0 0000 - $FF FFFF range.  These are ROM routines
   and they will move with every OS release.  The only supported
   interface to system ROM code is through the library, device, and
   resource calls.

*  Never assume library bases or structures will exist at any particular
   memory location.  The only absolute address in the system is $0000
   0004, which contains a pointer to the exec.library base. Do not modify
   or depend on the format of private system structures. This includes the
   poking of copper lists, memory lists, and library bases.

*  Never assume that programs can access hardware resources directly. Most
   hardware is controlled by system software that will not respond well to
   interference from other programs.  Shared hardware requires programs to
   use the proper sharing protocols.  Use the defined interface; it is the
   best way to ensure that your software will continue to operate on
   future models of the Amiga.

*  Never access shared data structures directly without the proper mutual
   exclusion (locking).  Remember that other tasks may be accessing the
   same structures.

*  All data for the custom chips must reside in Chip memory (type
   MEMF_CHIP).  This includes bitplanes, sound samples, trackdisk buffers,
   and images for sprites, bobs, pointers, and gadgets.  The AllocMem()
   call takes a flag for specifying the type of memory. A program that
   specifies the wrong type of memory may appear to run correctly because
   many Amigas have only Chip memory.  (On all models of the Amiga, the
   first 512K of memory is Chip memory and in some later models, Chip
   memory may occupy the first one or two megabytes).

   However, once expansion memory has been added to an Amiga (type
   MEMF_FAST), any memory allocations will be made in the expansion memory
   area by default.  Hence, a program can run correctly on an unexpanded
   Amiga which has only Chip memory while crashing on an Amiga which has
   expanded memory.  A developer with only Chip memory may fail to notice
   that memory was incorrectly specified.

   Most compilers have options to mark specific data structures or object
   modules so that they will load into Chip RAM.  Some older compilers
   provide the Atom utility for marking object modules.  If this method is
   unacceptable, use the AllocMem() call to dynamically allocate Chip
   memory, and copy your data there.

   When making allocations that do not require Chip memory, do not
   explicitly ask for Fast memory.  Instead ask for memory type
   MEMF_PUBLIC or 0L as appropriate.  If Fast memory is available, you
   will get it.

*  Never use software delay loops!  Under the multitasking operating
   system, the time spent in a loop can be better used by other tasks.
   Even ignoring the effect it has on multitasking, timing loops are
   inaccurate and will wait different amounts of time depending on the
   specific model of Amiga computer.  The timer.device provides
   precision timing for use under the multitasking system and it works
   the same on all models of the Amiga.  The AmigaDOS Delay() function
   or the graphics.library/WaitTOF() function provide a simple interface
   for longer delays.  The 8520 I/O chips provide timers for developers
   who are bypassing the operating system (see the Amiga Hardware
   Reference Manual for more information).


 [68010/020/030/040 Compatibility](hardware/1-general-development-guidelines-68010-020-030-040-2.md) 
 [Hardware Programming Guidelines](hardware/1-general-development-guidelines-hardware-programming-2.md) 
 [Additional Assembler Guidelines](hardware/1-general-development-guidelines-additional-assembler.md) 

---

## See Also

- [AllocMem — exec.library](../autodocs/exec.library.md#allocmem)
- [Delay — dos.library](../autodocs/dos.library.md#delay)
- [WaitTOF — graphics.library](../autodocs/graphics.library.md#waittof)
