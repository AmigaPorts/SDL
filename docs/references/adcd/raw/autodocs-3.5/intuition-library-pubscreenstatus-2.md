# intuition.library/PubScreenStatus



    NAME
	PubScreenStatus -- Change status flags for a public screen. (V36)

    SYNOPSIS
	ResultFlags = PubScreenStatus( [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132), StatusFlags )
	D0		   	       A0      D0

	[UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43) PubScreenStatus( struct [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) *, [UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43) );

    FUNCTION
	Changes status flags for a given public screen.  The only
	flag bit currently defined is PSNF_PRIVATE.  Thus,
	PubScreenStatus( screen, PSNF_PRIVATE ) makes a screen
	private, while PubScreenStatus( screen, 0 ) makes it public.

	Do not apply this function to a screen if your program
	isn't the screen's "owner", in particular, don't call
	this function for the Workbench screen.

    INPUTS
	[Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) = pointer to public screen
	StatusFlags = Any of the PSNF_ flags (only PSNF_PRIVATE is
	    currently defined).

    RESULT
	Returns 0 in the lowest order bit of the return value
	if the screen wasn't public, or because it can not be taken
	private because visitors are open in it.

	All other bits in the return code are reserved for future
	enhancement.

    BUGS

    SEE ALSO
	[OpenScreen()](../Includes_and_Autodocs_3._guide/node03D3.html), Intuition V36 update documentation

