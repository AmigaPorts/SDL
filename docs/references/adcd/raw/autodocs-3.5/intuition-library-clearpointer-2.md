# intuition.library/ClearPointer



    NAME
	ClearPointer -- Clear the mouse pointer definition from a window.

    SYNOPSIS
	ClearPointer( [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) )
		      A0

	VOID ClearPointer( struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) * );

    FUNCTION
	Clears the window of its own definition of the Intuition mouse pointer.
	After calling ClearPointer(), every time this window is the active
	one the default Intuition pointer will be the pointer displayed
	to the user.  If your window is the active one when this routine
	is called, the change will take place immediately.

	[Custom](../Includes_and_Autodocs_3._guide/node05F6.html#line24) definitions of the mouse pointer which this function clears
	are installed by a call to [SetPointer()](../Includes_and_Autodocs_3._guide/node03F4.html).

    INPUTS
	[Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) = pointer to the window to be cleared of its pointer definition

    RESULT
	None

    BUGS

    SEE ALSO
	[SetWindowPointerA()](../Includes_and_Autodocs_3._guide/node03F7.html), [SetPointer()](../Includes_and_Autodocs_3._guide/node03F4.html)

