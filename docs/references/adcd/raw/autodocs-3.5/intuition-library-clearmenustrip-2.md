# intuition.library/ClearMenuStrip



    NAME
	ClearMenuStrip -- Clear (detach) the menu strip from the window.

    SYNOPSIS
	ClearMenuStrip( [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) )
		        A0

	VOID ClearMenuStrip( struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) * );

    FUNCTION
	Detaches the current menu strip from the window; menu strips
	are attached to windows using the [SetMenuStrip()](../Includes_and_Autodocs_3._guide/node03F2.html) function
	(or, for V36, [ResetMenuStrip()](../Includes_and_Autodocs_3._guide/node03E6.html) ).

	If the menu is in use (for that matter if any menu is in use)
	this function will block (Wait()) until the user has finished.

	Call this function before you make any changes to the data
	in a [Menu](../Includes_and_Autodocs_3._guide/node05E0.html#line59) or [MenuItem](../Includes_and_Autodocs_3._guide/node05E0.html#line87) structure which is part of a menu
	strip linked into a window.

    INPUTS
	[Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) = pointer to a window structure

    RESULT
	None

    BUGS

    SEE ALSO
	[SetMenuStrip()](../Includes_and_Autodocs_3._guide/node03F2.html), [ResetMenuStrip()](../Includes_and_Autodocs_3._guide/node03E6.html)

