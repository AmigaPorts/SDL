---
title: mathieeesingtrans.library/IEEESPSincos
manual: autodocs-3.5
chapter: autodocs-3.5
section: mathieeesingtrans-library-ieeespsincos-2
functions: []
libraries: []
---

# mathieeesingtrans.library/IEEESPSincos

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	IEEESPSincos -- compute the arc tangent of a floating point number

   SYNOPSIS
	  x   = IEEESPSincos( z ,  y  );
	d0		     a0  d0

	float	x,y,*z;

   FUNCTION
	Compute sin and cosine of y in IEEE single precision.
	Store the cosine in *z. Return the sine of y.

   INPUTS
	y - IEEE single precision floating point value
	z - pointer to IEEE single precision floating point number

   RESULT
	x - IEEE single precision floating point value

   BUGS

   SEE ALSO
	[IEEESPSin()](autodocs-3.5/mathieeesingtrans-library-ieeespsin-2.md), [IEEESPCos()](autodocs-3.5/mathieeesingtrans-library-ieeespcos-2.md)

