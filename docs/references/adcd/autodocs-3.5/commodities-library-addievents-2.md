---
title: commodities.library/AddIEvents
manual: autodocs-3.5
chapter: autodocs-3.5
section: commodities-library-addievents-2
functions: []
libraries: []
---

# commodities.library/AddIEvents

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AddIEvents -- add input events to commodities' input stream. (V36)

   SYNOPSIS
	AddIEvents(events)
		   A0

	VOID AddIEvents(struct [InputEvent](autodocs-3.5/include-devices-inputevent-h.md) *);

   FUNCTION
	This function adds a null-terminated linked list of input events to
	the input stream processed by commodities. It is a touch easier than
	using the input device directly.

	The contents of the input events are copied into commodity messages,
	so they may be disposed of as soon as this call returns.

	The messages are initially routed to the first broker in
	commodities' object list.

   INPUTS
	events - the list of input events to add (may be NULL)

   WARNING
	The [cx_lib/InvertString()](autodocs-3.5/amiga-lib-invertstring-2.md) function creates lists of input events that
	are in reverse order. Thus, passing the result of [InvertString()](autodocs-3.5/amiga-lib-invertstring-2.md)
	to this function will insert a series of input events that will
	generate a string that's a mirror image of the string passed to
	[InvertString()](autodocs-3.5/amiga-lib-invertstring-2.md) originally.

	The solution to the above is to either flip the string before
	passing it to [InvertString()](autodocs-3.5/amiga-lib-invertstring-2.md), or flip the resulting list of input
	events.

   BUGS
	Prior to V40, this function did not copy the data pointed to by
	ie_EventAddress for any events of type IECLASS_NEWPOINTERPOS.

   SEE ALSO
	[cx_lib/FreeIEvents()](autodocs-3.5/amiga-lib-freeievents-2.md)

