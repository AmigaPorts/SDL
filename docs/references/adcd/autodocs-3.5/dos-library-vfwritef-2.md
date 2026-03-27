---
title: dos.library/VFWritef
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-vfwritef-2
functions: [FPutC, VFPrintf]
libraries: [dos.library]
---

# dos.library/VFWritef

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	VFWritef - write a BCPL formatted string to a file (buffered) (V36)

   SYNOPSIS
	count = VFWritef(fh, fmt, argv)
	D0               D1  D2    D3

	[LONG](autodocs-3.5/include-exec-types-h.md) VFWritef(BPTR, [STRPTR](autodocs-3.5/include-exec-types-h.md), [LONG](autodocs-3.5/include-exec-types-h.md) *)

	count = FWritef(fh, fmt, ...)

	[LONG](autodocs-3.5/include-exec-types-h.md) FWritef(BPTR, [STRPTR](autodocs-3.5/include-exec-types-h.md), ...)

   FUNCTION
	Writes the formatted string and values to the specified file.  This
	routine is assumed to handle all internal buffering so that the
	formatting string and resultant formatted values can be arbitrarily
	long.  The formats are in BCPL form.  This routine is buffered.

	Supported formats are:  (Note x is in base 36!)
		%S  - string (CSTR)
		%Tx - writes a left-justified string in a field at least
		      x bytes long.
		%C  - writes a single character
		%Ox - writes a number in octal, maximum x characters wide
		%Xx - writes a number in hex, maximum x characters wide
		%Ix - writes a number in decimal, maximum x characters wide
		%N  - writes a number in decimal, any length
		%Ux - writes an unsigned number, maximum x characters wide
		%$  - ignore parameter

	Note: 'x' above is actually the character value - '0'.

   INPUTS
	fh    - filehandle to write to
	fmt   - BCPL style formatting string
	argv  - Pointer to array of formatting values

   RESULT
	count - Number of bytes written or -1 for error

   BUGS
	As of V37, VFWritef() does NOT return a valid return value.  In
	order to reduce possible errors, the prototypes supplied for the
	system as of V37 have it typed as VOID.

   SEE ALSO
	[VFPrintf()](autodocs-3.5/dos-library-vfprintf-2.md), [VFPrintf()](autodocs-3.5/dos-library-vfprintf-2.md), [FPutC()](autodocs-3.5/dos-library-fputc-2.md)

---

## See Also

- [FPutC — dos.library](../autodocs/dos.library.md#fputc)
- [VFPrintf — dos.library](../autodocs/dos.library.md#vfprintf)
