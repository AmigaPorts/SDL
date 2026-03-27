# intuition.library/EndRequest



    NAME
	EndRequest -- [Remove](../Includes_and_Autodocs_3._guide/node022F.html) a currently active requester.

   SYNOPSIS
	EndRequest( [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143), [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) )
		    A0         A1

	VOID EndRequest( struct [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143) *, struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) * );

    FUNCTION
	Ends the request by erasing the requester and decoupling it from
	the window.

	Note that this doesn't necessarily clear all requesters from the window,
	only the specified one.  If the window labors under other requesters,
	they will remain in the window.

    INPUTS
	[Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143) = pointer to the requester to be removed
	[Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) = pointer to the [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) structure with which this requester
           is associated

    RESULT
	None

    BUGS

    SEE ALSO
	[Request()](../Includes_and_Autodocs_3._guide/node03E5.html)

