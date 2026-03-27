---
title: mathieeedoubbas.library/IEEEDPFloor
manual: autodocs-3.5
chapter: autodocs-3.5
section: mathieeedoubbas-library-ieeedpfloor-2
functions: [IEEEDPCeil]
libraries: [mathieeedoubbas.library]
---

# mathieeedoubbas.library/IEEEDPFloor

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	IEEEDPFloor -- compute Floor function of IEEE double precision number

   SYNOPSIS
	  x   = IEEEDPFloor(  y  );
	d0/d1		    d0/d1

	double	x,y;

   FUNCTION
	Calculate the largest integer less than or equal to x and return it.
	This value may have more than 32 bits of significance.

   INPUTS
	y -- IEEE double precision floating point value

   RESULT
	x -- IEEE double precision floating point value

   BUGS

   SEE ALSO
	[IEEEDPCeil()](autodocs-3.5/mathieeedoubbas-library-ieeedpceil-2.md)

---

## See Also

- [IEEEDPCeil — mathieeedoubbas.library](../autodocs/mathieeedoubbas.library.md#ieeedpceil)
