---
title: amiga.lib/arnd
manual: autodocs-3.5
chapter: autodocs-3.5
section: amiga-lib-arnd-2
functions: []
libraries: []
---

# amiga.lib/arnd

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

  NAME
	arnd - ASCII round of the provided floating point string

   SYNOPSIS
	arnd(place, exp, &string[0]);

   FUNCTION
	Accepts an ASCII string representing an FFP floating point
	number, the binary representation of the exponent of said
	floating point number and the number of places to round to.
	A rounding process is initiated, either to the left or right
	of the decimal place and the result placed back at the
	input address defined by &string[0].

   INPUTS
	place - integer representing number of decimal places to round to
	exp - integer representing exponent value of the ASCII string
	&string[0] - address where rounded ASCII string is to be placed
		     (16 bytes)

   RESULT
	&string[0] - rounded ASCII string

   BUGS
	None

