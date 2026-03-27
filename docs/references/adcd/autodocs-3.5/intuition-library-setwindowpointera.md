---
title: intuition.library/SetWindowPointerA
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-setwindowpointera
functions: [ClearPointer, NewObject, OpenWindowTagList, SetPointer, SetWindowPointerA]
libraries: [intuition.library]
---

# intuition.library/SetWindowPointerA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	SetWindowPointerA -- Select a pointer for your window. (V39)
	SetWindowPointer -- Varargs stub for SetWindowPointerA(). (V39)

    SYNOPSIS
	SetWindowPointerA( window, taglist )
	                   A0      A1

	VOID SetWindowPointerA( struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) * );

	SetWindowPointer( window, tag1, ... )

	VOID SetWindowPointer( struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *, ULONG tag1, ... );

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
	The same three tags are also accepted by [OpenWindowTagList()](autodocs-3.5/intuition-library-openwindowtaglist-2.md),
	which allows you to establish the initial pointer at the
	time you open your window.

	WA_Pointer (APTR) - The pointer you wish to associate with
	    your window.  If NULL, you are requesting the [Preferences](autodocs-3.5/include-intuition-preferences-h.md)
	    default pointer.  [Custom](autodocs-3.5/include-hardware-custom-h.md) pointers should be allocated
	    by performing a [NewObject()](autodocs-3.5/intuition-library-newobject-2.md) on "pointerclass".
	    (See <intuition/pointerclass.h>).  Defaults to NULL.

	WA_BusyPointer (BOOL) - Set to TRUE to request the [Preferences](autodocs-3.5/include-intuition-preferences-h.md)
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
	[SetPointer()](autodocs-3.5/intuition-library-setpointer-2.md), [ClearPointer()](autodocs-3.5/intuition-library-clearpointer-2.md), ROM Kernel Manual: Libraries

---

## See Also

- [ClearPointer — intuition.library](../autodocs/intuition.library.md#clearpointer)
- [NewObject — intuition.library](../autodocs/intuition.library.md#newobject)
- [OpenWindowTagList — intuition.library](../autodocs/intuition.library.md#openwindowtaglist)
- [SetPointer — intuition.library](../autodocs/intuition.library.md#setpointer)
- [SetWindowPointerA — intuition.library](../autodocs/intuition.library.md#setwindowpointera)
