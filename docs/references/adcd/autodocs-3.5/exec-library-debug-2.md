---
title: exec.library/Debug
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-debug-2
functions: [SetFunction]
libraries: [exec.library]
---

# exec.library/Debug

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	Debug -- run the system debugger

   SYNOPSIS
	Debug(flags)
	      D0

	void Debug(ULONG);

   FUNCTION
	This function calls the system debugger.  By default this debugger
	is "SAD" in >= V39 and "ROM-WACK" in < V39.  Other debuggers are
	encouraged to take over this entry point (via [SetFunction()](autodocs-3.5/exec-library-setfunction-2.md)) so
	that when an application calls Debug(), the alternative debugger
	will get control.  Currently a zero is passed to allow future
	expansion.

   NOTE
	The Debug() call may be made when the system is in a questionable
	state; if you have a [SetFunction()](autodocs-3.5/exec-library-setfunction-2.md) patch, make few assumptions, be
	prepared for [Supervisor](autodocs-3.5/exec-library-supervisor-2.md) mode, and be aware of differences in the
	Motorola stack frames on the 68000,'10,'20,'30,'40 (etc.)

   BUGS
	In ROMWack, calling this function in SUPERVISOR state would have
	caused the a5 register to be trashed and the user stack pointer to
	be trashed.  As of V39 (and the instroduction of SAD) this is no
	longer the case.  However, calling this function in [Supervisor](autodocs-3.5/exec-library-supervisor-2.md)
	state is a bit "tricky" at best...

	Note that due to a bug, pre-V40 SAD had the command
	codes wrong.  See the SAD autodoc for more details.

   SEE ALSO
	[SetFunction()](autodocs-3.5/exec-library-setfunction-2.md)
	your favorite debugger's manual...
	the SAD autodocs...
	the ROM-WACK chapter of the ROM Kernel Manual... (pre-V39)

---

## See Also

- [SetFunction — exec.library](../autodocs/exec.library.md#setfunction)
