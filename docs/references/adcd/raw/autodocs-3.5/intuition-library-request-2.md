# intuition.library/Request



    NAME
	Request -- Activate a requester.

    SYNOPSIS
	Success = Request( [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143), [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) )
	D0		   A0         A1

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) Request( struct [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143) *, struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) * );

    FUNCTION
	Links in and displays a requester into the specified window.

	This routine ignores the window's IDCMP_REQVERIFY flag.

    INPUTS
	[Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143) = pointer to the requester to be displayed
	[Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) = pointer to the window into which this requester goes

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

