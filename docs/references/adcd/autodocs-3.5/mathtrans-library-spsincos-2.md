---
title: mathtrans.library/SPSincos
manual: autodocs-3.5
chapter: autodocs-3.5
section: mathtrans-library-spsincos-2
functions: []
libraries: []
---

# mathtrans.library/SPSincos

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

	SPSincos - obtain the sine and cosine of a number

SYNOPSIS

	fnum3 = SPSincos(pfnum2, fnum1);
                         d1.l,   d0.l
	float *pfnum2;
	float fnum1;
	float fnum3;

FUNCTION

	Accepts a floating point number (fnum1) representing
	an angle in radians and a pointer to another floating
	point number (pfnum2). It computes the cosine and places it in
	*pfnum2. It computes the sine and returns it as a result.

INPUTS

	fnum1 - Motorola fast floating point number
	pfnum2 - pointer to Motorola fast floating point number

RESULT

	*pfnum2 - Motorola fast floating point number (cosine)
	fnum3 - Motorola fast floating point number (sine)

BUGS

	None

SEE ALSO

	[SPSin()](autodocs-3.5/mathtrans-library-spsin-2.md), [SPCos()](autodocs-3.5/mathtrans-library-spcos-2.md)

