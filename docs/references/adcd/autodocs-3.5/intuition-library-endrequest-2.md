---
title: intuition.library/EndRequest
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-endrequest-2
functions: [Request]
libraries: [intuition.library]
---

# intuition.library/EndRequest

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	EndRequest -- [Remove](autodocs-3.5/exec-library-remove-2.md) a currently active requester.

   SYNOPSIS
	EndRequest( [Requester](autodocs-3.5/include-intuition-intuition-h.md), [Window](autodocs-3.5/include-intuition-intuition-h.md) )
		    A0         A1

	VOID EndRequest( struct [Requester](autodocs-3.5/include-intuition-intuition-h.md) *, struct [Window](autodocs-3.5/include-intuition-intuition-h.md) * );

    FUNCTION
	Ends the request by erasing the requester and decoupling it from
	the window.

	Note that this doesn't necessarily clear all requesters from the window,
	only the specified one.  If the window labors under other requesters,
	they will remain in the window.

    INPUTS
	[Requester](autodocs-3.5/include-intuition-intuition-h.md) = pointer to the requester to be removed
	[Window](autodocs-3.5/include-intuition-intuition-h.md) = pointer to the [Window](autodocs-3.5/include-intuition-intuition-h.md) structure with which this requester
           is associated

    RESULT
	None

    BUGS

    SEE ALSO
	[Request()](autodocs-3.5/intuition-library-request-2.md)

---

## See Also

- [Request — intuition.library](../autodocs/intuition.library.md#request)
