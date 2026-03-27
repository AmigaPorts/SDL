# intuition.library/ActivateWindow



    NAME
	ActivateWindow -- Activate an Intuition window.

    SYNOPSIS
	ActivateWindow( [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) )
	                A0

	VOID ActivateWindow( struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) * );

    FUNCTION
	Activates an Intuition window.

	Note that this call may have its action deferred: you cannot assume
	that when this call is made the selected window has become active.
	This action will be postponed while the user plays with gadgets and
	menus, or sizes and drags windows.  You may detect when the window
	actually has become active by the IDCMP_ACTIVEWINDOW IDCMP message.

	This call is intended to provide flexibility but not to confuse the
	user.  Please call this function synchronously with some action
	by the user.

    INPUTS
	[Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) = a pointer to a [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) structure

    RESULT
	None.

    BUGS
	Some versions of the documentation claimed that this function
	had a meaningful return value under V36 and higher.  That is
	not true.

	Calling this function in a tight loop can blow out Intuition's
	deferred action queue.

    SEE ALSO
	[OpenWindow()](../Includes_and_Autodocs_3._guide/node03D5.html), and the WFLG_ACTIVATE window flag

