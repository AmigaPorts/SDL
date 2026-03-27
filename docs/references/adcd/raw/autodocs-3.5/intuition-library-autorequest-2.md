# intuition.library/AutoRequest



    NAME
	AutoRequest -- Automatically build and get response from a requester.

    SYNOPSIS
	Response = AutoRequest( [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908), BodyText, PosText, NegText,
	D0                      A0      A1        A2       A3
			PosFlags, NegFlags, Width, Height )
			D0        D1        D2     D3

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) AutoRequest( struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *, struct [IntuiText](../Includes_and_Autodocs_3._guide/node05E0.html#line655) *,
		struct [IntuiText](../Includes_and_Autodocs_3._guide/node05E0.html#line655) *, struct [IntuiText](../Includes_and_Autodocs_3._guide/node05E0.html#line655) *,
		ULONG, ULONG, WORD, WORD );

    FUNCTION
	This procedure automatically builds a requester for you and then
	waits for a response from the user, or for the system to satisfy your
	request.  If the response is positive, this procedure returns TRUE.
	If the response is negative, this procedure returns FALSE.

	An IDCMPFlag specification is created by bitwise "or'ing" your
	PosFlags, NegFlags, and the IDCMP classes IDCMP_GADGETUP and
	IDCMP_RAWKEY.  You may specify zero flags for either the PosFlags
	or NegFlags arguments.

	The [IntuiText](../Includes_and_Autodocs_3._guide/node05E0.html#line655) arguments, and the width and height values, are
	passed directly to the [BuildSysRequest()](../Includes_and_Autodocs_3._guide/node0399.html) procedure along with
	your window pointer and the IDCMP flags.  Please refer to
	[BuildSysRequest()](../Includes_and_Autodocs_3._guide/node0399.html) for a description of the [IntuiText](../Includes_and_Autodocs_3._guide/node05E0.html#line655) that you are
	expected to supply when calling this routine.  It's an important
	but long-winded description that need not be duplicated here.

	If the [BuildSysRequest()](../Includes_and_Autodocs_3._guide/node0399.html) procedure does not return a pointer
	to a window, it will return TRUE or FALSE (not valid structure
	pointers) instead, and these [BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) values will be returned to
	you immediately.

	On the other hand, if a valid window pointer is returned, that
	window will have had its IDCMP ports and flags initialized according
	to your specifications.  AutoRequest() then waits for IDCMP messages
	on the UserPort, which satisfies one of four requirements:
	-   either the message is of a class that matches
	    one of your PosFlags arguments (if you've supplied
	    any), in which case this routine returns TRUE.  Or
	-   the message class matches one of your NegFlags
	    arguments (if you've supplied any), in which case
	    this routine returns FALSE.  Or
	-   the IDCMP message is of class IDCMP_GADGETUP, which means that
	    one of the two gadgets, as provided with the PosText and NegText
	    arguments, was selected by the user.  If the TRUE gadget
	    was selected, TRUE is returned.  If the FALSE gadget was
	    selected, FALSE is returned.
	-   Lastly, two IDCMP_RAWKEY messages may satisfy the request: those
	    for the V and B keys with the left Amiga key depressed.
	    These keys, satisfy the gadgets on the left or right side of
	    the requester--TRUE or FALSE--, respectively.

	    NOTE: For V36, these two keys left-Amiga-B and V are processed
	    through the default keymap.

	When the dust has settled, this routine calls [FreeSysRequest()](../Includes_and_Autodocs_3._guide/node03B3.html) if
	necessary to clean up the requester and any other allocated memory.

	NOTE: For V36, this function now switches the processor stack
	to ensure sufficient stack space for the function to succeed.

    INPUTS
	[Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) = pointer to a [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) structure.  See [BuildSysRequest()](../Includes_and_Autodocs_3._guide/node0399.html)
	    for a full discussion.
	BodyText = pointer to an [IntuiText](../Includes_and_Autodocs_3._guide/node05E0.html#line655) structure
	PosText = pointer to an [IntuiText](../Includes_and_Autodocs_3._guide/node05E0.html#line655) structure, may by NULL.
	NegText = pointer to an [IntuiText](../Includes_and_Autodocs_3._guide/node05E0.html#line655) structure, MUST be valid!
	PosFlags = flags for the IDCMP
	NegFlags = flags for the IDCMP
	Width, Height = the sizes to be used for the rendering of the requester

	NOTE for V36: The width and height parameters are ignored, as
	are several other specifications in the [IntuiText](../Includes_and_Autodocs_3._guide/node05E0.html#line655), to make
	AutoRequest() requesters retroactively conform to the new look
	designed for EasyRequest().

    RESULT
	The return value is either TRUE or FALSE.  See the text above for a
	complete description of the chain of events that might lead to either
	of these values being returned.

    NOTES
	When DOS brings up AutoRequests() on your process (eg.
	"Please insert volume XXX in any drive", they normally come
	up on the Workbench screen.  If you set your [Process](../Includes_and_Autodocs_3._guide/node05D9.html#line36) pr_WindowPtr
	field to point to one of your windows, then DOS will bring its
	requesters up on the same screen as that window.  A pr_WindowPtr
	of -1 prevents requesters from coming up at all.
	(Some FileSystem requesters cannot be redirected or supressed).

    BUGS
	The requester no longer devolves into a call to [DisplayAlert()](../Includes_and_Autodocs_3._guide/node03A3.html)
	if there is not enough memory for the requester.

    SEE ALSO
	[EasyRequestArgs()](../Includes_and_Autodocs_3._guide/node03AB.html), [BuildSysRequest()](../Includes_and_Autodocs_3._guide/node0399.html), [SysReqHandler()](../Includes_and_Autodocs_3._guide/node03FB.html)

