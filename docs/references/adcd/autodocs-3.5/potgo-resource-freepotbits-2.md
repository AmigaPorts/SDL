---
title: potgo.resource/FreePotBits
manual: autodocs-3.5
chapter: autodocs-3.5
section: potgo-resource-freepotbits-2
functions: []
libraries: []
---

# potgo.resource/FreePotBits

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FreePotBits -- Free allocated bits in the potgo register.

   SYNOPSIS
	FreePotBits(allocated)
	            D0

	void FreePotBits( [UWORD](autodocs-3.5/include-exec-types-h.md) );

   FUNCTION
	The FreePotBits routine frees previously allocated bits in the
	hardware potgo register that the application had allocated via
	[AllocPotBits](autodocs-3.5/potgo-resource-allocpotbits-2.md) and no longer wishes to use.  It accepts the
	return value from [AllocPotBits](autodocs-3.5/potgo-resource-allocpotbits-2.md) as its argument.

