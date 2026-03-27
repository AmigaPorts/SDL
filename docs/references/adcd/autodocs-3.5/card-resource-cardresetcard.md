---
title: card.resource/CardResetCard
manual: autodocs-3.5
chapter: autodocs-3.5
section: card-resource-cardresetcard
functions: []
libraries: []
---

# card.resource/CardResetCard

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CardResetCard -- Reset credit-card.

   SYNOPSIS
	success=CardResetCard( handle );
				a1

	[BOOL](autodocs-3.5/include-exec-types-h.md) CardResetCard( struct [CardHandle](autodocs-3.5/include-resources-card-h.md) * );

   FUNCTION
	Used to reset a credit-card.  Some cards, such as some
	configurable cards can be reset.

	Asserts credit-card reset for at least 10us.

   INPUTS
	handle - Same handle as that used when [OwnCard()](autodocs-3.5/card-resource-owncard.md) was called.

   RETURNS
	TRUE  - Successful.

	FALSE  - Not successful.  Most likely because the credit-card
	card has been removed, and you are no longer the owner.

   NOTES
	This function may be called from within a task, or from a level 1
	or level 2 interrupt.

	***IMPORTANT***

	It is the responsibility of the card owner to reset
	configurable cards, or any other type of card such as
	some I/O cards before calling [ReleaseCard()](autodocs-3.5/card-resource-releasecard.md) if the owner
	has made use of that card such that it is no longer in its
	reset state (unless you are releasing the card because it
	has been removed).

	If the card manufacturer indicates that a certain amount
	of time must elapse between end of reset, and completion
	of card initialization, you should wait at least that long
	before releasing the card (unless you are releasing the card
	because it has been removed).

   SEE ALSO
	[OwnCard()](autodocs-3.5/card-resource-owncard.md), [ReleaseCard()](autodocs-3.5/card-resource-releasecard.md)

