---
title: card.resource/CardResetRemove
manual: autodocs-3.5
chapter: autodocs-3.5
section: card-resource-cardresetremove
functions: []
libraries: []
---

# card.resource/CardResetRemove

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CardResetRemove -- Set/Clear reset on card removal.

   SYNOPSIS
	success=CardResetRemove( handle, flag );
				 a1      d0

	[BOOL](autodocs-3.5/include-exec-types-h.md) CardResetRemove( struct [CardHandle](autodocs-3.5/include-resources-card-h.md) *, ULONG );

   FUNCTION
	Used to set/clear HARDWARE [RESET](autodocs-3.5/sad-reset.md) on card change detect.

	This function should generally not be used by devices
	which support HOT-REMOVAL.  HARDWARE [RESET](autodocs-3.5/sad-reset.md) on removal
	is generally intended for execute-in-place software, or
	ram cards whose memory has been added as system ram.

   INPUTS
	handle - Same handle as that used when [OwnCard()](autodocs-3.5/card-resource-owncard.md) was called.

	flag - TRUE if you want to SET HARDWARE [RESET](autodocs-3.5/sad-reset.md) on credit
	       card removal.  FALSE if you want to CLEAR HARDWARE
	       [RESET](autodocs-3.5/sad-reset.md).

   RETURNS
	1  - Success.

	0  - Function failed (most likely because the card was removed
	     by the user, and you are no longer the owner of the card).

	-1 - This function is not being made available.

   NOTES
	This function should only be called from a task.

   SEE ALSO
	[OwnCard()](autodocs-3.5/card-resource-owncard.md)

