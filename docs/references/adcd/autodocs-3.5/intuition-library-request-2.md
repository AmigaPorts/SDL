---
title: intuition.library/Request
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-request-2
functions: []
libraries: []
---

# intuition.library/Request

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	Request -- Activate a requester.

    SYNOPSIS
	Success = Request( [Requester](autodocs-3.5/include-intuition-intuition-h.md), [Window](autodocs-3.5/include-intuition-intuition-h.md) )
	D0		   A0         A1

	[BOOL](autodocs-3.5/include-exec-types-h.md) Request( struct [Requester](autodocs-3.5/include-intuition-intuition-h.md) *, struct [Window](autodocs-3.5/include-intuition-intuition-h.md) * );

    FUNCTION
	Links in and displays a requester into the specified window.

	This routine ignores the window's IDCMP_REQVERIFY flag.

    INPUTS
	[Requester](autodocs-3.5/include-intuition-intuition-h.md) = pointer to the requester to be displayed
	[Window](autodocs-3.5/include-intuition-intuition-h.md) = pointer to the window into which this requester goes

	New for V36: the POINTREL flag now has meaning if the requester
	is not a DMR (Double-Menu Requester):
	If POINTREL is set this requester should be placed in the center
	of the window, offset by Requester.RelLeft and Requester.RelTop.
	If the requester doesn't fit in the window, its position will be
	adjusted to show the upper-left corner.

    RESULT
	If the requester is successfully opened, TRUE is returned.  Otherwise,
	if the requester could not be opened, FALSE is returned.

    BUGS
	It turns out that the return code of this function is not
	always correct under V34 and prior.  If your requester does
	not have an ENDGADGET, then you can examine window->FirstRequest
	to see if your requester successfully opened.  (A requester with
	an ENDGADGET can go away all by itself before you get the chance
	to look).  Under V36 and higher, the return code from this routine
	is fine.

	There is a maximum of 8 requesters that are supported in
	a window that can be changed in size, position, or depth.

    SEE ALSO
	The Requesters section of the Intuition Reference Manual

