---
title: amiga.lib/FreeIEvents
manual: autodocs-3.5
chapter: autodocs-3.5
section: amiga-lib-freeievents-2
functions: []
libraries: []
---

# amiga.lib/FreeIEvents

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FreeIEvents -- free a chain of input events allocated by
		       [InvertString()](autodocs-3.5/amiga-lib-invertstring-2.md). (V36)

   SYNOPSIS
	FreeIEvents(events)

	VOID FreeIEvents(struct [InputEvent](autodocs-3.5/include-devices-inputevent-h.md) *);

   FUNCTION
	This function frees a linked list of input events as obtained from
	[InvertString()](autodocs-3.5/amiga-lib-invertstring-2.md).

   INPUTS

       events - the list of input events to free, may be NULL.
   SEE ALSO
	[InvertString()](autodocs-3.5/amiga-lib-invertstring-2.md)

