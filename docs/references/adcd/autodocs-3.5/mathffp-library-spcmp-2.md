---
title: mathffp.library/SPCmp
manual: autodocs-3.5
chapter: autodocs-3.5
section: mathffp-library-spcmp-2
functions: []
libraries: []
---

# mathffp.library/SPCmp

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME
	SPCmp -- Compares two floating point numbers.

SYNOPSIS
	result = SPCmp(fnum1, fnum2)
	D0               D0     D1

	int SPCmp(float fnum1, float fnum2);

FUNCTION

	Accepts two floating point numbers and returns the condition
	codes set to indicate the result of said comparison.  Additionally,
	the integer functional result is returned to indicate the result
	of said comparison.

INPUTS
	fnum1 	- floating point number.
	fnum2 	- floating point number.

RESULT
	Condition codes set to reflect the following branches:

		GT - fnum2 >  fnum1
		GE - fnum2 >= fnum1
		EQ - fnum2 =  fnum1
		NE - fnum2 != fnum1
		LT - fnum2 <  fnum1
		LE - fnum2 <= fnum1

	Integer functional result as:

		+1 => fnum1 > fnum2
		-1 => fnum1 < fnum2
		 0 => fnum1 = fnum2

BUGS
	None.

SEE ALSO

