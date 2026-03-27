---
title: card.resource/EndCardAccess
manual: autodocs-3.5
chapter: autodocs-3.5
section: card-resource-endcardaccess
functions: []
libraries: []
---

# card.resource/EndCardAccess

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	EndCardAccess -- Called at the end of credit-card memory access

   SYNOPSIS
	result=EndCardAccess( handle )
	d0			a1

	ULONG EndCardAccess( struct [CardHandle](autodocs-3.5/include-resources-card-h.md) * );

   FUNCTION
	This function should be called when you are done accessing
	credit-card memory.

	Its effect will depend on the type of Amiga machine your
	code happens to be running on.  On some machines it
	will cause an access light to be turned OFF in approximately
	1/2 second.

	On machines which support an access light, the light will
	automatically be turned off when you call [ReleaseCard()](autodocs-3.5/card-resource-releasecard.md).

   INPUTS
	handle - Same handle as that used when [OwnCard()](autodocs-3.5/card-resource-owncard.md) was called.

   RETURNS
	TRUE if you are still the owner of the credit-card.  FALSE
	if you are no longer the owner of the credit-card (usually
	indicating the card was removed).

   NOTES
	This function may be called from within a task, or from a level 1
	or level 2 interrupt.

	It is highly recommended that you call this function
	after accessing credit-card memory, as well as checking
	the return value.  If it is a return value of FALSE, you
	should stop accessing credit-card memory, and conclude
	that the card was removed before this function was called.

	On some machines it is possible that the credit-card will be
	removed before you receive the removed interrupt.

   SEE ALSO
	[OwnCard()](autodocs-3.5/card-resource-owncard.md), [ReleaseCard()](autodocs-3.5/card-resource-releasecard.md), [BeginCardAccess()](autodocs-3.5/card-resource-begincardaccess.md)

