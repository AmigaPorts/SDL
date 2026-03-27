---
title: card.resource/CardChangeCount
manual: autodocs-3.5
chapter: autodocs-3.5
section: card-resource-cardchangecount
functions: []
libraries: []
---

# card.resource/CardChangeCount

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CardChangeCount -- Obtain card change count.

   SYNOPSIS
	count = CardChangeCount( VOID )
	d0

	ULONG CardChangeChange( VOID );

   FUNCTION
	This function returns the card change count.  The
	counter is incremented by one for every removal, and
	for every successful insertion (a card which is inserted
	long enough to be debounced before it is removed again).

   RESULT
	The change count number.

   NOTES
	This function may be called from a task, or any level interrupt.

   SEE ALSO

