---
title: mathffp.library/SPTst
manual: autodocs-3.5
chapter: autodocs-3.5
section: mathffp-library-sptst-2
functions: []
libraries: []
---

# mathffp.library/SPTst

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME
	SPTst - Compares a float against zero (0.0).

SYNOPSIS
	result = SPTst(fnum)
	D0	       D1

	int SPTst(float fnum);

FUNCTION
	Accepts a floating point number and returns the condition
	codes set to indicate the result of a comparison against
	the value of zero (0.0).  Additionally, the integer functional
	result is returned.

INPUTS
	fnum 	- floating point number.

RESULT
	Condition codes set to reflect the following branches:

		EQ - fnum =  0.0
		NE - fnum != 0.0
		PL - fnum >= 0.0
		MI - fnum <  0.0

	Integer functional result as:

		+1 => fnum > 0.0
		-1 => fnum < 0.0
		 0 => fnum = 0.0

BUGS
	None.

SEE ALSO

