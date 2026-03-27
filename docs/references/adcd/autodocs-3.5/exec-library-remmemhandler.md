---
title: exec.library/RemMemHandler
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-remmemhandler
functions: []
libraries: []
---

# exec.library/RemMemHandler

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	RemMemHandler - [Remove](autodocs-3.5/exec-library-remove-2.md) low memory handler from exec              (V39)

   SYNOPSIS
	RemMemHandler(memHandler)
	              A1

	VOID RemMemHandler(struct [Interrupt](autodocs-3.5/include-exec-interrupts-h.md) *);

   FUNCTION
	This function removes the low memory handler from the system.
	This function can be called from within a handler.  If removing
	oneself, it is important that the handler returns MEM_ALL_DONE.

   NOTE
	When removing a handler, the handler may be called until this
	function returns.  Thus, the handler must still be valid until
	then.

   INPUTS
	memHandler - Pointer to a handler added with [AddMemHandler()](autodocs-3.5/exec-library-addmemhandler.md)

   SEE ALSO
	[AddMemHandler()](autodocs-3.5/exec-library-addmemhandler.md), exec/interrupts.i

