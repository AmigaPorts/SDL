---
title: amiga.lib/FastRand
manual: autodocs-3.5
chapter: autodocs-3.5
section: amiga-lib-fastrand-2
functions: []
libraries: []
---

# amiga.lib/FastRand

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FastRand - quickly generate a somewhat random integer

   SYNOPSIS
	number = FastRand(seed);

	ULONG FastRand(ULONG);

   FUNCTION
	Seed value is taken from stack, shifted left one position,
	exclusive-or'ed with hex value $1D872B41 and returned.

   INPUTS
	seed - a 32-bit integer

   RESULT
	number - new random seed, a 32-bit value

   SEE ALSO
	[RangeRand()](autodocs-3.5/amiga-lib-rangerand-2.md)

