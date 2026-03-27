---
title: amiga.lib/RemTOF
manual: autodocs-3.5
chapter: autodocs-3.5
section: amiga-lib-remtof-2
functions: []
libraries: []
---

# amiga.lib/RemTOF

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	RemTOF - remove a task from the VBlank interrupt server chain.

   SYNOPSIS
	RemTOF(i);

	VOID RemTOF(struct [Isrvstr](autodocs-3.5/include-graphics-graphint-h.md) *);

   FUNCTION
	Removes a task from the vertical-blanking interval interrupt server
	chain.

   INPUTS
	i - pointer to an [Isrvstr](autodocs-3.5/include-graphics-graphint-h.md) structure

   SEE ALSO
	[AddTOF()](autodocs-3.5/amiga-lib-addtof-2.md), [<graphics/graphint.h>](autodocs-3.5/include-graphics-graphint-h.md)

