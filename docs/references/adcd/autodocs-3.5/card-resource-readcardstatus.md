---
title: card.resource/ReadCardStatus
manual: autodocs-3.5
chapter: autodocs-3.5
section: card-resource-readcardstatus
functions: []
libraries: []
---

# card.resource/ReadCardStatus

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ReadCardStatus -- [Read](autodocs-3.5/dos-library-read-2.md) credit card status register

   SYNOPSIS
	status=ReadCardStatus()
	d0

	[UBYTE](autodocs-3.5/include-exec-types-h.md) ReadCardStatus( void );

   FUNCTION
	Returns current state of the credit card status register.

	See card.h/i for bit definitions.

	Note that the meaning of the returned status bits may vary
	depending on the type of card inserted in the slot, and
	mode of operation.  Interpretation of the bits is left
	up to the application.

   RETURNS
	A [UBYTE](autodocs-3.5/include-exec-types-h.md) value to be interpreted as status bits.

   NOTES
	This function may be called from within a task, or from any level
	interrupt.

   SEE ALSO
	[resources/card.h](autodocs-3.5/include-resources-card-h.md), resources/card.i

