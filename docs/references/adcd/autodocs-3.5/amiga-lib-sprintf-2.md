---
title: amiga.lib/sprintf
manual: autodocs-3.5
chapter: autodocs-3.5
section: amiga-lib-sprintf-2
functions: [RawDoFmt]
libraries: [exec.library]
---

# amiga.lib/sprintf

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	sprintf - format a C-like string into a string buffer.

   SYNOPSIS
	sprintf(destination formatstring [,value [, values] ] );

   FUNCTION
	Performs string formatting identical to [printf](autodocs-3.5/amiga-lib-printf-2.md), but directs the output
	into a specific destination in memory. This uses the ROM version
	of [printf](autodocs-3.5/amiga-lib-printf-2.md) [(exec.library/RawDoFmt()](autodocs-3.5/exec-library-rawdofmt-2.md)), so it is very small.

	Assembly programmers can call this by placing values on the
	stack, followed by a pointer to the formatstring, followed
	by a pointer to the destination string.

   INPUTS
	destination - the address of an area in memory into which the
		      formatted output is to be placed.
	formatstring - pointer to a null terminated string describing the
	               desired output formatting (see [printf()](autodocs-3.5/amiga-lib-printf-2.md) for a
		       description of this string).
	value(s) - numeric information to be formatted into the output
		   stream.

   SEE ALSO
	 [printf()](autodocs-3.5/amiga-lib-printf-2.md), [exec.library/RawDoFmt()](autodocs-3.5/exec-library-rawdofmt-2.md)

---

## See Also

- [RawDoFmt — exec.library](../autodocs/exec.library.md#rawdofmt)
