---
title: intuition.library/ClearDMRequest
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-cleardmrequest-2
functions: [Request, SetDMRequest]
libraries: [intuition.library]
---

# intuition.library/ClearDMRequest

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	ClearDMRequest -- Clear (detaches) the DMRequest of the window.

    SYNOPSIS
	Response = ClearDMRequest( [Window](autodocs-3.5/include-intuition-intuition-h.md) )
	D0			   A0

	[BOOL](autodocs-3.5/include-exec-types-h.md) ClearDMRequest( struct [Window](autodocs-3.5/include-intuition-intuition-h.md) * );

    FUNCTION
	Attempts to clear the DMRequest from the specified window,
	that is detaches the special requester that you attach to
	the double-click of the menu button which the user can then
	bring up on demand.  This routine WILL NOT clear the DMRequest
	if it's active (in use by the user). The IDCMP message class
	IDCMP_REQCLEAR can be used to detect that the requester is not in use,
	but that message is sent only when the last of perhaps several
	requesters in use in a window is terminated.

    INPUTS
	[Window](autodocs-3.5/include-intuition-intuition-h.md) = pointer to the window from which the DMRequest is to be cleared.

    RESULT
	If the DMRequest was not currently in use, detaches the DMRequest
	from the window and returns TRUE.

	If the DMRequest was currently in use, doesn't change anything
	and returns FALSE.

    BUGS

    SEE ALSO
	[SetDMRequest()](autodocs-3.5/intuition-library-setdmrequest-2.md), [Request()](autodocs-3.5/intuition-library-request-2.md)

---

## See Also

- [Request — intuition.library](../autodocs/intuition.library.md#request)
- [SetDMRequest — intuition.library](../autodocs/intuition.library.md#setdmrequest)
