# intuition.library/BuildEasyRequestArgs



    NAME
	BuildEasyRequestArgs -- Simple creation of system request. (V36)
	BuildEasyRequest -- Varargs stub for BuildEasyRequestArgs(). (V36)

    SYNOPSIS
	ReqWindow = BuildEasyRequestArgs( RefWindow, easyStruct, IDCMP, Args )
	D0                                A0         A1          D0     A3

	struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *BuildEasyRequestArgs( struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *,
		struct [EasyStruct](../Includes_and_Autodocs_3._guide/node05E0.html#line1456) *, ULONG, [APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37) );

	ReqWindow = BuildEasyRequest( RefWindow, easyStruct, IDCMP, Arg1, ... )

	struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *BuildEasyRequest( struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *,
		struct [EasyStruct](../Includes_and_Autodocs_3._guide/node05E0.html#line1456) *, ULONG, [APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37), ... );

    FUNCTION
	This function is to EasyRequest() as [BuildSysRequest()](../Includes_and_Autodocs_3._guide/node0399.html) is to
	AutoRequest(): it returns a pointer to the system requester
	window.  The input from that window can then be processed
	under application control.

	It is recommended that this processing be done with
	[SysReqHandler()](../Includes_and_Autodocs_3._guide/node03FB.html), so that future enhancement to the
	processing will be enjoyed.

	After you have determined that the requester is satisfied or
	cancelled, you must free this requester using [FreeSysRequest()](../Includes_and_Autodocs_3._guide/node03B3.html).

	Please see the autodoc for EasyRequest().

	NOTE: This function switches the processor stack to ensure
	sufficient stack space for the function to complete.

    INPUTS
	[Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) = reference window for requester: determines the
	    requester window title and screen.
	easyStruct = pointer to [EasyStruct](../Includes_and_Autodocs_3._guide/node05E0.html#line1456) structure, as described
	    in the EasyRequest() autodocs.
	IDCMP = (NOT A POINTER) provided application specific IDCMP
	    flags for the system requester window.
	Args = see [EasyRequestArgs()](../Includes_and_Autodocs_3._guide/node03AB.html)

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
	See also BUGS listed for [EasyRequestArgs()](../Includes_and_Autodocs_3._guide/node03AB.html).

    SEE ALSO
	[EasyRequestArgs()](../Includes_and_Autodocs_3._guide/node03AB.html), [FreeSysRequest()](../Includes_and_Autodocs_3._guide/node03B3.html), [SysReqHandler()](../Includes_and_Autodocs_3._guide/node03FB.html),
	[BuildSysRequest()](../Includes_and_Autodocs_3._guide/node0399.html), [AutoRequest()](../Includes_and_Autodocs_3._guide/node0396.html)

