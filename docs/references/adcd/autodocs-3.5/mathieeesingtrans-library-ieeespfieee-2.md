---
title: mathieeesingtrans.library/IEEESPFieee
manual: autodocs-3.5
chapter: autodocs-3.5
section: mathieeesingtrans-library-ieeespfieee-2
functions: []
libraries: []
---

# mathieeesingtrans.library/IEEESPFieee

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	IEEESPFieee -- convert IEEE single to IEEE single

   SYNOPSIS
	  x   = IEEESPFieee(  y  );
	d0	              d0

	float	y;
	float  x;

   FUNCTION
	Convert IEEE single precision number to IEEE single precision.
	These are included for completeness although they just
	return the input parameter. A good way to remember how these
	functions work is: They convert to and from the local format
	to Single Precision IEEE. The local format for this library
	happens to also be Single Precision IEEE.

   INPUTS
	y - IEEE single precision floating point value

   RESULT
	x - IEEE single precision floating point value

   BUGS

   SEE ALSO
	[IEEESPTieee()](autodocs-3.5/mathieeesingtrans-library-ieeesptieee-2.md)

