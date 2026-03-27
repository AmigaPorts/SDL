---
title: dos.library/VFPrintf
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-vfprintf-2
functions: [FPrintf, FPutC, IoErr, RawDoFmt, VPrintf]
libraries: [dos.library, exec.library]
---

# dos.library/VFPrintf

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	VFPrintf -- format and print a string to a file (buffered) (V36)

   SYNOPSIS
	count = VFPrintf(fh, fmt, argv)
	D0               D1  D2    D3

	[LONG](autodocs-3.5/include-exec-types-h.md) VFPrintf(BPTR, [STRPTR](autodocs-3.5/include-exec-types-h.md), [LONG](autodocs-3.5/include-exec-types-h.md) *)

	count = FPrintf(fh, fmt, ...)

	[LONG](autodocs-3.5/include-exec-types-h.md) FPrintf(BPTR, [STRPTR](autodocs-3.5/include-exec-types-h.md), ...)

   FUNCTION
	Writes the formatted string and values to the given file.  This
	routine is assumed to handle all internal buffering so that the
	formatting string and resultant formatted values can be arbitrarily
	long.  Any secondary error code is returned in [IoErr()](autodocs-3.5/dos-library-ioerr-2.md).  This routine
	is buffered.

   INPUTS
	fh    - Filehandle to write to
	fmt   - [RawDoFmt()](autodocs-3.5/exec-library-rawdofmt-2.md) style formatting string
	argv  - Pointer to array of formatting values

   RESULT
	count - Number of bytes written or -1 (EOF) for an error

   BUGS
	The prototype for FPrintf() currently forces you to cast the first
	varargs parameter to [LONG](autodocs-3.5/include-exec-types-h.md) due to a deficiency in the program
	that generates fds, prototypes, and amiga.lib stubs.

   SEE ALSO
	[VPrintf()](autodocs-3.5/dos-library-vprintf-2.md), [VFWritef()](autodocs-3.5/dos-library-vfwritef-2.md), [RawDoFmt()](autodocs-3.5/exec-library-rawdofmt-2.md), [FPutC()](autodocs-3.5/dos-library-fputc-2.md)

---

## See Also

- [FPrintf — dos.library](../autodocs/dos.library.md#fprintf)
- [FPutC — dos.library](../autodocs/dos.library.md#fputc)
- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [RawDoFmt — exec.library](../autodocs/exec.library.md#rawdofmt)
- [VPrintf — dos.library](../autodocs/dos.library.md#vprintf)
