# intuition.library/ClearDMRequest



    NAME
	ClearDMRequest -- Clear (detaches) the DMRequest of the window.

    SYNOPSIS
	Response = ClearDMRequest( [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) )
	D0			   A0

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) ClearDMRequest( struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) * );

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
	[Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) = pointer to the window from which the DMRequest is to be cleared.

    RESULT
	If the DMRequest was not currently in use, detaches the DMRequest
	from the window and returns TRUE.

	If the DMRequest was currently in use, doesn't change anything
	and returns FALSE.

    BUGS

    SEE ALSO
	[SetDMRequest()](../Includes_and_Autodocs_3._guide/node03EF.html), [Request()](../Includes_and_Autodocs_3._guide/node03E5.html)

