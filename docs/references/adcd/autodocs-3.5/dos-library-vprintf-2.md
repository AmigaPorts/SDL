---
title: dos.library/VPrintf
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-vprintf-2
functions: [FPutC, IoErr, Output, Printf, RawDoFmt, VFPrintf]
libraries: [dos.library, exec.library]
---

# dos.library/VPrintf

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	VPrintf -- format and print string (buffered) (V36)

   SYNOPSIS
	count = VPrintf(fmt, argv)
	  D0            D1   D2

	[LONG](autodocs-3.5/include-exec-types-h.md) VPrintf(STRPTR, [LONG](autodocs-3.5/include-exec-types-h.md) *)

	count = Printf(fmt, ...)

	[LONG](autodocs-3.5/include-exec-types-h.md) Printf(STRPTR, ...)

   FUNCTION
	Writes the formatted string and values to [Output()](autodocs-3.5/dos-library-output-2.md).  This routine is
	assumed to handle all internal buffering so that the formatting string
	and resultant formatted values can be arbitrarily long.  Any secondary
	error code is returned in [IoErr()](autodocs-3.5/dos-library-ioerr-2.md).  This routine is buffered.

	Note: [RawDoFmt](autodocs-3.5/exec-library-rawdofmt-2.md) assumes 16 bit ints, so you will usually need 'l's in
	your formats (ex: %ld versus %d).

   INPUTS
	fmt   - exec.library [RawDoFmt()](autodocs-3.5/exec-library-rawdofmt-2.md) style formatting string
	argv  - Pointer to array of formatting values

   RESULT
	count - Number of bytes written or -1 (EOF) for an error

   BUGS
	The prototype for Printf() currently forces you to cast the first
	varargs parameter to [LONG](autodocs-3.5/include-exec-types-h.md) due to a deficiency in the program
	that generates fds, prototypes, and amiga.lib stubs.

   SEE ALSO
	[VFPrintf()](autodocs-3.5/dos-library-vfprintf-2.md), [VFWritef()](autodocs-3.5/dos-library-vfwritef-2.md), [RawDoFmt()](autodocs-3.5/exec-library-rawdofmt-2.md), [FPutC()](autodocs-3.5/dos-library-fputc-2.md)

---

## See Also

- [FPutC — dos.library](../autodocs/dos.library.md#fputc)
- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [Output — dos.library](../autodocs/dos.library.md#output)
- [Printf — dos.library](../autodocs/dos.library.md#printf)
- [RawDoFmt — exec.library](../autodocs/exec.library.md#rawdofmt)
- [VFPrintf — dos.library](../autodocs/dos.library.md#vfprintf)
