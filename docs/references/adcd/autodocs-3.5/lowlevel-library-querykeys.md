---
title: lowlevel.library/QueryKeys
manual: autodocs-3.5
chapter: autodocs-3.5
section: lowlevel-library-querykeys
functions: []
libraries: []
---

# lowlevel.library/QueryKeys

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	QueryKeys -- return the states for a set of keys. (V40)

   SYNOPSIS
	QueryKeys(queryArray, arraySize);
	          A0          D1

	VOID QueryKeys(struct [KeyQuery](autodocs-3.5/include-libraries-lowlevel-h.md) *, UBYTE);

   FUNCTION
	Scans the keyboard to determine which of the rawkey codes
	listed in the QueryArray are currently pressed. The state for each
	key is returned in the array.

	This function may be invoked from within an interrupt, but the size
	of QueryArray should be kept as small as possible.

	This is a low level function that does not fit the normal Amiga
	multitasking model. The values returned have no knowledge
	of which window/screen currently has input focus.

   INPUTS
	queryArray - an array of [KeyQuery](autodocs-3.5/include-libraries-lowlevel-h.md) structures. The kq_KeyCode fields
		     of these structures should be filled with the rawkey
		     codes you wish to query about. Upon return from this
		     function, the kq_Pressed field of these structures
		     will be set to TRUE if the associated key is down,
	             and FALSE if not.
	arraySize - number of key code entries in queryArray

   SEE ALSO
	[<libraries/lowlevel.h>](autodocs-3.5/include-libraries-lowlevel-h.md)

