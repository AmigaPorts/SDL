# intuition.library/ZipWindow



    NAME
	ZipWindow -- Change window to "alternate" position and
	             dimensions. (V36)

    SYNOPSIS
	ZipWindow( [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) )
		   A0

	VOID ZipWindow( struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) * );

    FUNCTION
	Changes the position and dimension of a window to the values
	at the last occasion of ZipWindow being called (or invoked
	via the "zoom" gadget).

	Typically this is used to snap between a normal, large, working
	dimension of the window to a smaller, more innocuous position
	and dimension.

	Like [MoveWindow()](../Includes_and_Autodocs_3._guide/node03C8.html), [SizeWindow()](../Includes_and_Autodocs_3._guide/node03FA.html), and [ChangeWindowBox()](../Includes_and_Autodocs_3._guide/node039B.html), the action of
	this function is deferred to the Intuition input handler.

	More tuning needs to be done to establish initial values for
	the first invocation of this function for a window.  You can
	provide initial values using the [OpenWindow()](../Includes_and_Autodocs_3._guide/node03D5.html) tag item
	WA_Zoom.

	It could also use a new name, but "ZoomWindow" is misleading,
	since "Zoom" normally implies "scale."

	The zoom gadget will appear (in the place of the old "toback"
	gadget) when you open your window if you either specify a
	sizing gadget or use WA_Zoom.

	You can detect that this function has taken effect by receiving
	an IDCMP_CHANGEWINDOW IDCMP message.

    INPUTS
	[Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) -- window to be changed.

    RESULT
	None

    BUGS
	[OpenWindow()](../Includes_and_Autodocs_3._guide/node03D5.html) assumes that the proper default "other" dimensions
	are "full size."

    SEE ALSO
	[ChangeWindowBox()](../Includes_and_Autodocs_3._guide/node039B.html), [MoveWindow()](../Includes_and_Autodocs_3._guide/node03C8.html), [SizeWindow()](../Includes_and_Autodocs_3._guide/node03FA.html)

