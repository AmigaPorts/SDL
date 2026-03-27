---
title: General Compatibility Problem Areas
manual: amiga-mail
chapter: amiga-mail
section: general-compatibility-problem-areas
functions: [AvailFonts, CacheClearU]
libraries: [diskfont.library, exec.library]
---

# General Compatibility Problem Areas

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

One sure fire way to write incompatible software is to fail to follow the
Amiga programming guidelines listed in the beginning of your Amiga ROM
Kernel and Amiga Hardware manuals.  Please read the guidelines and follow
them!

The following improper Amiga programming practices are likely to fail on
new ROMs or hardware:

* Calling ROM code directly.

* Directly or indirectly reading or writing random memory addresses or
  low memory (especially location zero) due to improperly initialized
  pointers or structures.  Use Mungwall and Enforcer when writing and
  testing your code!

* Assuming addresses/location/amounts of RAM or system structures.

* Requiring all free RAM.

* Mishandling 32-bit addresses.  For example, using signed math or
  signed comparisons on addresses, or doing a BOOL or WORD test to
  determine if a pointer is non-zero.

* Overwriting memory allocations.  With 32-bit addresses, a 1-byte
  overwrite of a string array can wipe out the high byte of a pointer or
  stack return address.  This bug could go unnoticed on a 24-bit address
  machine (eg. A500,A2500, etc) but crash the system or cause other
  problems on an A3000.

* Shaving stack size too close.  System function stack usage changes
  with each OS release. o Improper flags or garbage in system structures.
  A bit that means nothing under one OS may drastically change the
  behavior of a function in a newer version of the OS.  Clear structures
  before using, and use correct flags.

* Passing garbage in previously unused upper bytes of function arguments
  (for example-the upper word of the ULONG AvailFonts() Flags parameter).

* Improper register or condition code handling.  Do not assume registers
  D0-D1/A0-A1 are preserved after system calls!  Some function calls
  happen to preserve some registers.  This can change in any revisions of
  the OS.  In some cases we have modifed the values returned in registers
  to keep certain applications from failing under 2.0.  We do not
  guarantee those modifications will remain in place.  Condition codes are
  also in an undefined state on the return from a system call.  Assembler
  code must test (TST,MOVE,CMP,etc.) D0 results before branching on
  condition codes.  Use Scratch by Bill Hawes (via the scratchall script)
  to catch scratch register misuse in assembler code.

* Misuse of function return values.  Use function prototypes and read
  the Autodocs for the functions you are using.  Some system functions
  return just success or failure, or nothing at all (void).  In such
  cases, the value which the function happens to return must not be used
  except as it is documented.

* Calling system library functions from assembler without placing the
  library base pointer in A6.  All system functions may assume that their
  library's base pointer is in A6.  A function's need to reference its
  library base can change in different OS revisions.

* Depending on unsupported side effects or undocumented behavior.  Be
  sure to read the RKM chapters, Autodocs, and include file comments.

* Poking/peeking system private structures.  Do not poke or peek any
  system structure unless told to do so in official Commodore
  documentation.

* Assuming current choices, configurations or initial values.  If the
  current possibilities are A, B, or C, do not assume C if it isn't A or
  B.  Check specifically for the choices currently implemented, and
  provide default behavior for unexpected values.

* Failure to properly allocate resources before using them.

* Failure to properly close/deallocate resources.

* Improper reading/writing of hardware registers.  You must mask out
  bits you are not interested in on reads, and write undefined bits as
  zero.

* Assuming initial values of hardware registers.  If you are going
  direct to the hardware, do not depend on the initial values of any
  hardware registers. The settings may not be the same on different
  versions of the OS or from boot to boot.  Always set up all of the
  hardware registers that affect your code. o Processor speed dependencies
  such as software delay loops.

* Processor instruction dependencies.  Do not use instructions which are
  privileged on any Motorola 68xxx family processor.  Do not use CLR on a
  hardware register which is triggered by any access (use MOVE #0
  instead). The 68000 CLR instruction performs two accesses (Read, then
  Write).  The 68020 and higher CLR instruction performs just one access.

* Depending on or failing to account for cache or prefetch effects.
  Self-modifying or trackdisk-loaded code requires cache flushes ( see the
  exec.library/CacheClearU() function ).

Amiga debugging tools such as Enforcer, Mungwall, and Scratch can find
many program bugs that may affect compatibility.  A program that is
Enforcer/Mungwall/Scratch clean stands a much better chance of working
well under current and future versions of the OS.  These tools are on the
Denver/Milano DevCon disks.  Enforcer and Mungwall are also on the
kickfile disks.

---

## See Also

- [AvailFonts — diskfont.library](../autodocs/diskfont.library.md#availfonts)
- [CacheClearU — exec.library](../autodocs/exec.library.md#cacheclearu)
