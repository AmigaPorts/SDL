---
title: mathieeedoubbas.library/IEEEDPFix
manual: autodocs-3.5
chapter: autodocs-3.5
section: mathieeedoubbas-library-ieeedpfix-2
functions: [IEEEDPFlt]
libraries: [mathieeedoubbas.library]
---

# mathieeedoubbas.library/IEEEDPFix

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	IEEEDPFix -- convert IEEE double float to integer

   SYNOPSIS
	x   = IEEEDPFix(  y  );
	d0		d0/d1

	long	x;
	double	y;

   FUNCTION
	Convert IEEE double precision argument to a 32 bit signed integer
	and return result.

   INPUTS
	y -- IEEE double precision floating point value

   RESULT
	if no overflow occured then return
		x -- 32 bit signed integer
	if overflow return largest +- integer
		For round to zero

   BUGS

   SEE ALSO
	[IEEEDPFlt()](autodocs-3.5/mathieeedoubbas-library-ieeedpflt-2.md)

---

## See Also

- [IEEEDPFlt — mathieeedoubbas.library](../autodocs/mathieeedoubbas.library.md#ieeedpflt)
