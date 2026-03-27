# intuition.library/ResetMenuStrip



    NAME
	ResetMenuStrip -- Re-attach a menu strip to a window. (V36)

    SYNOPSIS
	Success = ResetMenuStrip( [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908), [Menu](../Includes_and_Autodocs_3._guide/node05E0.html#line59) )
	D0		          A0      A1

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) ResetMenuStrip( struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *, struct [Menu](../Includes_and_Autodocs_3._guide/node05E0.html#line59) * );

    FUNCTION
	This function is simply a "fast" version of [SetMenuStrip()](../Includes_and_Autodocs_3._guide/node03F2.html) that
	doesn't perform the precalculations of menu page sizes that
	[SetMenuStrip()](../Includes_and_Autodocs_3._guide/node03F2.html) does.

	You may call this function ONLY IF the menu strip and all items
	and sub-items have not changed since the menu strip was passed to
	[SetMenuStrip()](../Includes_and_Autodocs_3._guide/node03F2.html), with the following exceptions:

	- You may change the CHECKED flag to turn a checkmark on or off.
	- You may change the ITEMENABLED flag to enable/disable some
	  [MenuItem](../Includes_and_Autodocs_3._guide/node05E0.html#line87) or [Menu](../Includes_and_Autodocs_3._guide/node05E0.html#line59) structures.

	In all other ways, this function performs like [SetMenuStrip()](../Includes_and_Autodocs_3._guide/node03F2.html).

	The new sequence of events you can use is:
	- [OpenWindow()](../Includes_and_Autodocs_3._guide/node03D5.html)
	- [SetMenuStrip()](../Includes_and_Autodocs_3._guide/node03F2.html)
	zero or more iterations of:
	    - [ClearMenuStrip()](../Includes_and_Autodocs_3._guide/node039D.html)
	    - change CHECKED or ITEMENABLED flags
	    - ResetMenuStrip()
	- [ClearMenuStrip()](../Includes_and_Autodocs_3._guide/node039D.html)
	- [CloseWindow()](../Includes_and_Autodocs_3._guide/node03A0.html)

    INPUTS
	[Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) = pointer to a [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) structure
	[Menu](../Includes_and_Autodocs_3._guide/node05E0.html#line59) = pointer to the first menu in the menu strip

    RESULT
	TRUE always.

    BUGS

    SEE ALSO
	[SetMenuStrip()](../Includes_and_Autodocs_3._guide/node03F2.html), [ClearMenuStrip()](../Includes_and_Autodocs_3._guide/node039D.html)

