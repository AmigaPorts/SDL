---
title: utility.library/SMult32
manual: autodocs-3.5
chapter: autodocs-3.5
section: utility-library-smult32-2
functions: []
libraries: []
---

# utility.library/SMult32

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SMult32 -- signed 32 by 32 bit multiply with 32 bit result. (V36)

   SYNOPSIS
	result = SMult32(arg1,arg2);
	D0               D0   D1

	[LONG](autodocs-3.5/include-exec-types-h.md) SMult32(LONG,LONG);

   FUNCTION
	Returns the signed 32 bit result of multiplying arg1 by arg2.

   INPUTS
	arg1, arg2 - numbers to multiply

   RESULTS
	result - the signed 32 bit result of multiplying arg1 by arg2.

   NOTES
	Unlike other Amiga library function calls, the utility.library
	32 bit math routines do NOT require A6 to be loaded with a
	pointer to the library base. A6 can contain anything the application
	wishes. This is in order to avoid overhead in calling them.

	In addition, the utility.library math routines preserve all
	address registers including A0 and A1

   SEE ALSO
	[SDivMod32()](autodocs-3.5/utility-library-sdivmod32-2.md), [UDivMod32()](autodocs-3.5/utility-library-udivmod32-2.md), [UMult32()](autodocs-3.5/utility-library-umult32-2.md), [SMult64()](autodocs-3.5/utility-library-smult64.md), [UMult64()](autodocs-3.5/utility-library-umult64.md)

