---
title: mathieeesingbas.library/IEEESPCeil
manual: autodocs-3.5
chapter: autodocs-3.5
section: mathieeesingbas-library-ieeespceil-2
functions: []
libraries: []
---

# mathieeesingbas.library/IEEESPCeil

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	IEEESPCeil -- compute Ceil function of IEEE single precision number

   SYNOPSIS
	  x   = IEEESPCeil(  y  );
	 d0		     d0

	float	x,y;

   FUNCTION
	Calculate the least integer greater than or equal to x and return it.
	This identity is true.  Ceil(x) = -Floor(-x).

   INPUTS
	y -- IEEE single precision floating point value

   RESULT
	x -- IEEE single precision floating point value

   BUGS

   SEE ALSO
	[IEEESPFloor()](autodocs-3.5/mathieeesingbas-library-ieeespfloor-2.md)

