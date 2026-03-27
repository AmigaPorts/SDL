---
title: XIII-15: A1200 CPU Card Expansion RAM
manual: amiga-mail
chapter: amiga-mail
section: xiii-15-a1200-cpu-card-expansion-ram
functions: [AddMemList, TypeOfMem]
libraries: [exec.library]
---

# XIII-15: A1200 CPU Card Expansion RAM

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A1200 CPU Card Expansion RAM


by Michael Sinz




When the Amiga OS boots, it automatically notices and utilizes
expansion hardware (such as RAM).  Prior to the A3000, the only CPU
native to any Amiga was the MC68000, which could only address a
24-bit wide address space.  As a result, the address space that was
available to these machines was only 24 bits wide.  CPU expansion
products for the MC68000-based Amigas (like the A2630 for the A2000)
can utilize address space beyond the 24-bit limit, but the CPU board
cannot use the AutoConfig process to add expansion RAM in the address
space beyond the 24-bit limit.

Like the MC68000 based Amigas, the Amiga 1200 also has a CPU that
only addresses a 24-bit wide address space, the MC68EC020.  Also like
most of the MC68000 based Amigas, it is possible to add a CPU
expansion device.  One way the A1200 differs from its 24-bit siblings
is the A1200 has set aside a 128 Megabyte range of address space
($0800 0000 through $0FFF FFFF) specifically for such a device (just
like the A3000).  Any expansion RAM on the A1200's CPU card should
appear in this range.

The Release 3 OS in the current A1200 is not smart enough to
recognize a 32-bit CPU expansion device vs. a 24-bit expansion
device.  As a result, the system assumes that the expansion device is
a 24-bit expansion device.  If a user expands their A1200 with a
32-bit CPU card that has 32-bit expansion memory on it, the OS cannot
automatically add the CPU card's expansion memory during the
autoconfig process.  The CPU card's ROM has to add the memory to the
system.

The code to make the A1200 smart enough to recognize a 32-bit CPU
card will be in a future ROM revision.  This change will allow the OS
to automatically notice and add the CPU card's expansion RAM.  This
makes it possible for the system to add this 32-bit memory to the
A1200's system memory relatively early in the boot process.  Because
the memory is available earlier in the boot process, Exec has the
opportunity to use the 32-bit memory for system purposes (this can
include the supervisor stack, ExecBase, and most other library bases).

This change presents a minor problem for an A1200 CPU card that adds
its own memory.  Before the CPU card can add its memory to the system
memory list, it must make sure the OS has not already added that
memory.  The CPU card can use the following code to test if the A1200
has already added the CPU card's expansion memory.  This code queries
the system about the type of memory located at the low end of the
coprocessor slot expansion address range.  If the system has already
added memory at this location, TypeOfMem() returns the
characteristics of that memory.  If no memory is at that location,
TypeOfMem() returns zero.


	/*
	 * Note that we check the memory 16K from the start as the
	 * first few bytes may have been used by the OS when doing
	 * the automatic testing...
	 */
	if (!TypeOfMem(0x08001000))
	{
		/*
		 * If TypeOfMem() returned 0, the memory does not
		 * exist.  At this point, you can do whatever
		 * memory tests that may be needed and then
		 * AddMemList() the memory as needed.
		 *
		 * **NOTE**  Do *NOT* do the memory test if the memory
		 * has already been added as it may be in use by some
		 * very important things, including interrupt vectors
		 * and/or code.
		 */
		AddMemList(size,MEMF_FAST|MEMF_PUBLIC,pri,0x08000000,"CPU RAM");
	}


More About the New A1200 Code

The code to make the A1200 detect 32-bit CPU cards will also notice
``natural wrapping'' in the board's memory.  If a board has only a
limited amount of memory, it is possible to design the board so that
the physical memory is accessible at many addresses at regular
address intervals.  For example, if the board has four megabytes of
memory, that memory could be accessed at four megabyte intervals
(address $0800 0000, $0840 0000, $0880 0000, and so on).

Because the OS notices the wrap, CPU cards can use a more economical
design because they don't have to be as complex.  It also cuts down
on the need for jumpers or switch settings.  The code requires that
the A1200 CPU board's memory sizes be in multiples of 1 megabyte
(512K is not supported).

---

## See Also

- [AddMemList — exec.library](../autodocs/exec.library.md#addmemlist)
- [TypeOfMem — exec.library](../autodocs/exec.library.md#typeofmem)
