---
title: card.resource/CardAccessSpeed
manual: autodocs-3.5
chapter: autodocs-3.5
section: card-resource-cardaccessspeed
functions: []
libraries: []
---

# card.resource/CardAccessSpeed

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CardAccessSpeed -- Select best possible memory access speed.

   SYNOPSIS
	result=CardAccessSpeed( handle, nanoseconds );
	d0			 a1      d0

	ULONG CardAccessSpeed( struct [CardHandle](autodocs-3.5/include-resources-card-h.md) *, ULONG );

   FUNCTION
	This function is used to set memory access speed for all CPU
	accesses to card memory.

	Typically this information would be determined by first examining
	the Card Information Structure.

	Then you would use this function to let the card.resource
	select the best possible access speed for you, however note
	that the range of possible access speeds may vary on some
	machines (depending on the type of credit-card interface
	hardware being provided).

   INPUTS
	handle - Same handle as that used when [OwnCard()](autodocs-3.5/card-resource-owncard.md) was called.

	nanoseconds - Preferred access speed in nanoseconds.

   RETURNS
	Speed - Access speed selected by resource (in nanoseconds).

	0  - Not successful.  Either because the credit-card was
	removed, or the access speed you requested is slower than
	that supported by the credit-card interface hardware.

   NOTES
	This function may be called from within a task, or from a level 1
	or level 2 interrupt.

   SEE ALSO
	[OwnCard()](autodocs-3.5/card-resource-owncard.md)

