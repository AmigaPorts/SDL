# intuition.library/SetWindowPointerA



    NAME
	SetWindowPointerA -- Select a pointer for your window. (V39)
	SetWindowPointer -- Varargs stub for SetWindowPointerA(). (V39)

    SYNOPSIS
	SetWindowPointerA( window, taglist )
	                   A0      A1

	VOID SetWindowPointerA( struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) * );

	SetWindowPointer( window, tag1, ... )

	VOID SetWindowPointer( struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *, ULONG tag1, ... );

    FUNCTION
	Allows you to set the pointer image associated with the
	specified window.  Whenever the window is the active one,
	the pointer image will change to the window's version.
	If the window is the active one when this routine is
	called, the change takes place immediately.

    INPUTS
	window = pointer to the window to receive this pointer definition
	taglist = pointer to a taglist describing your pointer

    TAGS
	The same three tags are also accepted by [OpenWindowTagList()](../Includes_and_Autodocs_3._guide/node03D6.html),
	which allows you to establish the initial pointer at the
	time you open your window.

	WA_Pointer (APTR) - The pointer you wish to associate with
	    your window.  If NULL, you are requesting the [Preferences](../Includes_and_Autodocs_3._guide/node063B.html#line57)
	    default pointer.  [Custom](../Includes_and_Autodocs_3._guide/node05F6.html#line24) pointers should be allocated
	    by performing a [NewObject()](../Includes_and_Autodocs_3._guide/node03CB.html) on "pointerclass".
	    (See <intuition/pointerclass.h>).  Defaults to NULL.

	WA_BusyPointer (BOOL) - Set to TRUE to request the [Preferences](../Includes_and_Autodocs_3._guide/node063B.html#line57)
	    busy-pointer.  If FALSE, your pointer will be as requested
	    by WA_Pointer.  Defaults to FALSE.

	WA_PointerDelay (BOOL) - Set to TRUE to defer changing your
	    pointer for a brief instant.  This is typically used
	    along with setting the busy pointer, especially when
	    the application knows it may be busy for a very short
	    while.  If the application clears the pointer or sets
	    another pointer before the delay expires, the pending
	    pointer change is cancelled.  This reduces short
	    flashes of the busy pointer.

    RESULT
	None

    EXAMPLE
	This example sets the standard busy pointer with pointer-delay,
	does a bit of work, then clears the pointer:

		/* Put up the busy pointer, with pointer-delay */
		SetWindowPointer( win,
		    WA_BusyPointer, TRUE,
		    WA_PointerDelay, TRUE,
		    TAG_DONE );

		/* Do busy stuff here */

		/* No tags means "clear the pointer" */
		SetWindowPointer( win,
		    TAG_DONE );

    BUGS

    SEE ALSO
	[SetPointer()](../Includes_and_Autodocs_3._guide/node03F4.html), [ClearPointer()](../Includes_and_Autodocs_3._guide/node039E.html), ROM Kernel Manual: Libraries

