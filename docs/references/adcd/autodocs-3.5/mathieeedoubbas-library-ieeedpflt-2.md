---
title: mathieeedoubbas.library/IEEEDPFlt
manual: autodocs-3.5
chapter: autodocs-3.5
section: mathieeedoubbas-library-ieeedpflt-2
functions: [IEEEDPFix]
libraries: [mathieeedoubbas.library]
---

# mathieeedoubbas.library/IEEEDPFlt

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	IEEEDPFlt -- convert integer to IEEE double precision number

   SYNOPSIS
	  x   = IEEEDPFlt(  y  );
	d0/d1		   d0

	double	x;
	long	y;

   FUNCTION
	Convert a signed 32 bit value to a double precision IEEE value
	and return it in d0/d1. No exceptions can occur with this
	function.

   INPUTS
	y -- 32 bit integer in d0

   RESULT
	x is a 64 bit double precision IEEE value

   BUGS

   SEE ALSO
	[IEEEDPFix()](autodocs-3.5/mathieeedoubbas-library-ieeedpfix-2.md)

---

## See Also

- [IEEEDPFix — mathieeedoubbas.library](../autodocs/mathieeedoubbas.library.md#ieeedpfix)
