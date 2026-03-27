---
title: mathieeedoubtrans.library/IEEEDPSincos
manual: autodocs-3.5
chapter: autodocs-3.5
section: mathieeedoubtrans-library-ieeedpsincos-2
functions: []
libraries: []
---

# mathieeedoubtrans.library/IEEEDPSincos

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	IEEEDPSincos -- compute the arc tangent of a floating point number

   SYNOPSIS
	  x   = IEEEDPSincos( z ,  y  );
	d0/d1		     a0  d0/d1

	double	x,y,*z;

   FUNCTION
	Compute sin and cosine of y in IEEE double precision.
	Store the cosine in *z. Return the sine of y.

   INPUTS
	y - IEEE double precision floating point value
	z - pointer to IEEE double precision floating point number

   RESULT
	x - IEEE double precision floating point value

   BUGS

   SEE ALSO
	[IEEEDPSin()](autodocs-3.5/mathieeedoubtrans-library-ieeedpsin-2.md), [IEEEDPCos()](autodocs-3.5/mathieeedoubtrans-library-ieeedpcos-2.md)

