---
title: mathtrans.library/SPFieee
manual: autodocs-3.5
chapter: autodocs-3.5
section: mathtrans-library-spfieee-2
functions: []
libraries: []
---

# mathtrans.library/SPFieee

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

	SPFieee - convert single precision ieee to FFP number

SYNOPSIS

	fnum = SPFieee(ieeenum);
                       d0.l
	float fnum;
	float ieeenum;

FUNCTION

	Accepts a standard single precision format
	returns the same number, converted to Motorola
	fast floating point number

INPUTS

	ieeenum - IEEE Single Precision Floating Point

RESULT

	fnum - Motorola fast floating point number

BUGS

	None

SEE ALSO

	[SPTieee()](autodocs-3.5/mathtrans-library-sptieee-2.md)

