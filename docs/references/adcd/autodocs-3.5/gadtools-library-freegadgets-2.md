---
title: gadtools.library/FreeGadgets
manual: autodocs-3.5
chapter: autodocs-3.5
section: gadtools-library-freegadgets-2
functions: [CreateGadgetA]
libraries: [gadtools.library]
---

# gadtools.library/FreeGadgets

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FreeGadgets -- free a linked list of gadgets. (V36)

   SYNOPSIS
	FreeGadgets(glist)
	            A0

	VOID FreeGadgets(struct [Gadget](autodocs-3.5/include-intuition-intuition-h.md) *glist);
	                 A0

   FUNCTION
	Frees any GadTools gadgets found on the linked list of gadgets
	beginning with the specified one.  Frees all the memory that was
	allocated by [CreateGadgetA()](autodocs-3.5/gadtools-library-creategadgeta-2.md).  This function will return safely
	with no action if it receives a NULL parameter.

   INPUTS
	glist - pointer to first gadget in list to be freed.

   SEE ALSO
	[CreateGadgetA()](autodocs-3.5/gadtools-library-creategadgeta-2.md)

---

## See Also

- [CreateGadgetA — gadtools.library](../autodocs/gadtools.library.md#creategadgeta)
