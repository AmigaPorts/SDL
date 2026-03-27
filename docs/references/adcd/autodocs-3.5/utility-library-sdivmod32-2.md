---
title: utility.library/SDivMod32
manual: autodocs-3.5
chapter: autodocs-3.5
section: utility-library-sdivmod32-2
functions: []
libraries: []
---

# utility.library/SDivMod32

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SDivMod32 -- signed 32 by 32 bit division and modulus. (V36)

   SYNOPSIS
	quotient:remainder = SDivMod32(dividend,divisor);
	D0       D1                    D0       D1

	[LONG:LONG](autodocs-3.5/include-exec-types-h.md) SDivMod32(LONG,LONG);

   FUNCTION
	Divides the signed 32 bit dividend by the signed 32 bit divisor
	and returns a signed 32 bit quotient and remainder.

   INPUTS
	dividend - signed 32 bit dividend.
	divisor - signed 32 bit divisor.

   RESULTS
	quotient - signed 32 quotient of the division.
	remainder - signed 32 remainder of the division.

   NOTES
	Unlike other Amiga library function calls, the utility.library
	32 bit math routines do NOT require A6 to be loaded with a
	pointer to the library base. A6 can contain anything the application
	wishes. This is in order to avoid overhead in calling them.

	In addition, the utility.library math routines preserve all
	address registers including A0 and A1

   SEE ALSO
	[SMult32()](autodocs-3.5/utility-library-smult32-2.md), [UDivMod32()](autodocs-3.5/utility-library-udivmod32-2.md), [UMult32()](autodocs-3.5/utility-library-umult32-2.md), [SMult64()](autodocs-3.5/utility-library-smult64.md), [UMult64()](autodocs-3.5/utility-library-umult64.md)

