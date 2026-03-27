---
title: mathieeesingbas.library/IEEESPFlt
manual: autodocs-3.5
chapter: autodocs-3.5
section: mathieeesingbas-library-ieeespflt-2
functions: []
libraries: []
---

# mathieeesingbas.library/IEEESPFlt

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	IEEESPFlt -- convert integer to IEEE single precision number

   SYNOPSIS
	  x   = IEEESPFlt(  y  );
	 d0		   d0

	float	x;
	long	y;

   FUNCTION
	Convert a signed 32 bit value to a single precision IEEE value
	and return it in d0. No exceptions can occur with this
	function.

   INPUTS
	y -- 32 bit integer in d0

   RESULT
	x is a 32 bit single precision IEEE value

   BUGS

   SEE ALSO
	[IEEESPFix()](autodocs-3.5/mathieeesingbas-library-ieeespfix-2.md)

