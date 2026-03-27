---
title: mathieeedoubbas.library/IEEEDPCeil
manual: autodocs-3.5
chapter: autodocs-3.5
section: mathieeedoubbas-library-ieeedpceil-2
functions: [IEEEDPFloor]
libraries: [mathieeedoubbas.library]
---

# mathieeedoubbas.library/IEEEDPCeil

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	IEEEDPCeil -- compute Ceil function of IEEE double precision number

   SYNOPSIS
	  x   = IEEEDPCeil(  y  );
	d0/d1		   d0/d1

	double	x,y;

   FUNCTION
	Calculate the least integer greater than or equal to x and return it.
	This value may have more than 32 bits of significance.
	This identity is true.  Ceil(x) = -Floor(-x).

   INPUTS
	y -- IEEE double precision floating point value

   RESULT
	x -- IEEE double precision floating point value

   BUGS

   SEE ALSO
	[IEEEDPFloor()](autodocs-3.5/mathieeedoubbas-library-ieeedpfloor-2.md)

---

## See Also

- [IEEEDPFloor — mathieeedoubbas.library](../autodocs/mathieeedoubbas.library.md#ieeedpfloor)
