---
title: intuition.library/BuildEasyRequestArgs
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-buildeasyrequestargs-2
functions: [AutoRequest, BuildEasyRequestArgs, BuildSysRequest, EasyRequestArgs, FreeSysRequest, SysReqHandler]
libraries: [intuition.library]
---

# intuition.library/BuildEasyRequestArgs

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	BuildEasyRequestArgs -- Simple creation of system request. (V36)
	BuildEasyRequest -- Varargs stub for BuildEasyRequestArgs(). (V36)

    SYNOPSIS
	ReqWindow = BuildEasyRequestArgs( RefWindow, easyStruct, IDCMP, Args )
	D0                                A0         A1          D0     A3

	struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *BuildEasyRequestArgs( struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *,
		struct [EasyStruct](autodocs-3.5/include-intuition-intuition-h.md) *, ULONG, [APTR](autodocs-3.5/include-exec-types-h.md) );

	ReqWindow = BuildEasyRequest( RefWindow, easyStruct, IDCMP, Arg1, ... )

	struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *BuildEasyRequest( struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *,
		struct [EasyStruct](autodocs-3.5/include-intuition-intuition-h.md) *, ULONG, [APTR](autodocs-3.5/include-exec-types-h.md), ... );

    FUNCTION
	This function is to EasyRequest() as [BuildSysRequest()](autodocs-3.5/intuition-library-buildsysrequest-2.md) is to
	AutoRequest(): it returns a pointer to the system requester
	window.  The input from that window can then be processed
	under application control.

	It is recommended that this processing be done with
	[SysReqHandler()](autodocs-3.5/intuition-library-sysreqhandler-2.md), so that future enhancement to the
	processing will be enjoyed.

	After you have determined that the requester is satisfied or
	cancelled, you must free this requester using [FreeSysRequest()](autodocs-3.5/intuition-library-freesysrequest-2.md).

	Please see the autodoc for EasyRequest().

	NOTE: This function switches the processor stack to ensure
	sufficient stack space for the function to complete.

    INPUTS
	[Window](autodocs-3.5/include-intuition-intuition-h.md) = reference window for requester: determines the
	    requester window title and screen.
	easyStruct = pointer to [EasyStruct](autodocs-3.5/include-intuition-intuition-h.md) structure, as described
	    in the EasyRequest() autodocs.
	IDCMP = (NOT A POINTER) provided application specific IDCMP
	    flags for the system requester window.
	Args = see [EasyRequestArgs()](autodocs-3.5/intuition-library-easyrequestargs-2.md)

    RESULT
	A pointer to the system request window opened.  In the event
	of problems, you may also be returned the value '0' which
	is to be interpreted as the "FALSE, Cancel" choice, or
	(if you have a second gadget defined) the value '1', which
	is to be taken to mean the equivalent of your corresponding
	left-most gadget.

	If there is a problem creating the window, a recoverable alert may
	be substituted for the requester, and the result, either 0 or 1,
	returned.

    BUGS
	Does not put up alternative alert.
	See also BUGS listed for [EasyRequestArgs()](autodocs-3.5/intuition-library-easyrequestargs-2.md).

    SEE ALSO
	[EasyRequestArgs()](autodocs-3.5/intuition-library-easyrequestargs-2.md), [FreeSysRequest()](autodocs-3.5/intuition-library-freesysrequest-2.md), [SysReqHandler()](autodocs-3.5/intuition-library-sysreqhandler-2.md),
	[BuildSysRequest()](autodocs-3.5/intuition-library-buildsysrequest-2.md), [AutoRequest()](autodocs-3.5/intuition-library-autorequest-2.md)

---

## See Also

- [AutoRequest — intuition.library](../autodocs/intuition.library.md#autorequest)
- [BuildEasyRequestArgs — intuition.library](../autodocs/intuition.library.md#buildeasyrequestargs)
- [BuildSysRequest — intuition.library](../autodocs/intuition.library.md#buildsysrequest)
- [EasyRequestArgs — intuition.library](../autodocs/intuition.library.md#easyrequestargs)
- [FreeSysRequest — intuition.library](../autodocs/intuition.library.md#freesysrequest)
- [SysReqHandler — intuition.library](../autodocs/intuition.library.md#sysreqhandler)
