---
title: intuition.library/FreeSysRequest
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-freesysrequest-2
functions: [AutoRequest, BuildEasyRequestArgs, BuildSysRequest, CloseWindow]
libraries: [intuition.library]
---

# intuition.library/FreeSysRequest

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	FreeSysRequest -- Free resources gotten by a call to [BuildSysRequest()](autodocs-3.5/intuition-library-buildsysrequest-2.md).

    SYNOPSIS
	FreeSysRequest( [Window](autodocs-3.5/include-intuition-intuition-h.md) )
		        A0

	VOID FreeSysRequest( struct [Window](autodocs-3.5/include-intuition-intuition-h.md) * );

    FUNCTION
	This routine frees up all memory allocated by a successful call to
	the [BuildSysRequest()](autodocs-3.5/intuition-library-buildsysrequest-2.md) procedure.  If [BuildSysRequest()](autodocs-3.5/intuition-library-buildsysrequest-2.md) returned a
	pointer to a window, then you are able to wait on the message port
	of that window to detect an event which satisfies the requester.
	When you want to remove the requester, you call this procedure.  It
	ends the requester and deallocates any memory used in the creation
	of the requester.  It also closes the special window that was opened
	for your system requester.

	For V36: It's OK if you pass a NULL or a TRUE (1) value to
	this function.  Also, this function properly disposes of
	requesters gotten using [BuildEasyRequestArgs()](autodocs-3.5/intuition-library-buildeasyrequestargs-2.md).

    INPUTS
	[Window](autodocs-3.5/include-intuition-intuition-h.md) = value of the window pointer returned by a successful call to
```c
           the [BuildSysRequest()](autodocs-3.5/intuition-library-buildsysrequest-2.md) procedure

    RESULT
```
	None

    BUGS

    SEE ALSO
	[BuildSysRequest()](autodocs-3.5/intuition-library-buildsysrequest-2.md), [AutoRequest()](autodocs-3.5/intuition-library-autorequest-2.md), [CloseWindow()](autodocs-3.5/intuition-library-closewindow-2.md)

---

## See Also

- [AutoRequest — intuition.library](../autodocs/intuition.library.md#autorequest)
- [BuildEasyRequestArgs — intuition.library](../autodocs/intuition.library.md#buildeasyrequestargs)
- [BuildSysRequest — intuition.library](../autodocs/intuition.library.md#buildsysrequest)
- [CloseWindow — intuition.library](../autodocs/intuition.library.md#closewindow)
