---
title: mathffp.library/SPFix
manual: autodocs-3.5
chapter: autodocs-3.5
section: mathffp-library-spfix-2
functions: []
libraries: []
---

# mathffp.library/SPFix

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME
	SPFix -- Convert fast floating point number to integer.

SYNOPSIS
	inum = SPFix(fnum)
	D0	     D0

	int SPFix(float fnum);

FUNCTION
	Accepts a floating point number and returns the truncated
	integer portion of said number.

INPUTS

	fnum 	- floating point number.

RESULT

	inum 	- signed integer number.

BUGS
	None.

SEE ALSO

