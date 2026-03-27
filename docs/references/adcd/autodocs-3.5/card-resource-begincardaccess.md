---
title: card.resource/BeginCardAccess
manual: autodocs-3.5
chapter: autodocs-3.5
section: card-resource-begincardaccess
functions: []
libraries: []
---

# card.resource/BeginCardAccess

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	BeginCardAccess -- Called before you begin credit-card memory access

   SYNOPSIS
	result=BeginCardAccess( handle )
	d0			a1

	[BOOL](autodocs-3.5/include-exec-types-h.md) BeginCardAccess( struct [CardHandle](autodocs-3.5/include-resources-card-h.md) * );

   FUNCTION
	This function should be called before you begin access
	to credit-card memory.

	Its effect will depend on the type of Amiga machine your
	code happens to be running on.  On some machines it
	will cause an access light to be turned ON.

   INPUTS
	handle - Same handle as that used when [OwnCard()](autodocs-3.5/card-resource-owncard.md) was called.

   RETURNS
	TRUE if you are still the owner of the credit-card, and
	memory access is permitted.  FALSE if you are no longer
	the owner of the credit-card (usually indicating that
	the card was removed).

   NOTES
	This function may be called from within a task, or from a level 1
	or level 2 interrupt.

	It is highly recommended that you call this function
	before accessing credit-card memory, as well as checking
	the return value.  If it is a return value of FALSE, you
	should stop accessing credit-card memory.

   SEE ALSO
	[OwnCard()](autodocs-3.5/card-resource-owncard.md), [EndCardAccess()](autodocs-3.5/card-resource-endcardaccess.md)

