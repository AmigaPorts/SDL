# intuition.library/OffMenu



    NAME
	OffMenu -- [Disable](../Includes_and_Autodocs_3._guide/node0203.html) the given menu or menu item.

    SYNOPSIS
	OffMenu( [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908), MenuNumber )
		 A0      D0

	VOID OffMenu( struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *, [UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43) );

    FUNCTION
	This command disables a sub-item, an item, or a whole menu.
	This depends on the contents of the data packed into MenuNumber,
	which is described in the Intuition Reference Manual.

    INPUTS
	[Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) = pointer to the window
	MenuNumber = the menu piece to be disabled

    RESULT
	None

    BUGS

    SEE ALSO
	[OnMenu()](../Includes_and_Autodocs_3._guide/node03D2.html), [ResetMenuStrip()](../Includes_and_Autodocs_3._guide/node03E6.html)

