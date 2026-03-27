---
title: amiga.lib/AddTOF
manual: autodocs-3.5
chapter: autodocs-3.5
section: amiga-lib-addtof-2
functions: []
libraries: []
---

# amiga.lib/AddTOF

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AddTOF - add a task to the VBlank interrupt server chain.

   SYNOPSIS
	AddTOF(i,p,a);

	VOID AddTOF(struct [Isrvstr](autodocs-3.5/include-graphics-graphint-h.md) *, [APTR](autodocs-3.5/include-exec-types-h.md), APTR);

   FUNCTION
	Adds a task to the vertical-blanking interval interrupt server
	chain. This prevents C programmers from needing to write an
	assembly language stub to do this function.

   INPUTS
	i - pointer to an initialized [Isrvstr](autodocs-3.5/include-graphics-graphint-h.md) structure
	p - pointer to the C-code routine that this server is to call each
	    time TOF happens
	a - pointer to the first longword in an array of longwords that
	    is to be used as the arguments passed to your routine
	    pointed to by p.

   SEE ALSO
	[RemTOF()](autodocs-3.5/amiga-lib-remtof-2.md), [<graphics/graphint.h>](autodocs-3.5/include-graphics-graphint-h.md)

