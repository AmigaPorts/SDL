---
title: workbench.library/MakeWorkbenchObjectVisibleArary/MakeWorkbenchObjectVisibleA
manual: autodocs-3.5
chapter: autodocs-3.5
section: workbench-library-makeworkbenchobjectvisiblearary
functions: [IoErr]
libraries: [dos.library]
---

# workbench.library/MakeWorkbenchObjectVisibleArary/MakeWorkbenchObjectVisibleA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	MakeWorkbenchObjectVisibleA -- Change a Workbench window in such a
	    way as to make a particular icon visible. (V44)

   SYNOPSIS
	success = MakeWorkbenchObjectVisibleA(name,tags)
	   D0                                  A0   A1

	[BOOL](autodocs-3.5/include-exec-types-h.md) MakeWorkbenchObjectVisibleA(STRPTR name,struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *tags);

	success = MakeWorkbenchObjectVisible(name,...);

	[BOOL](autodocs-3.5/include-exec-types-h.md) MakeWorkbenchObjectVisible(STRPTR name,...);

   FUNCTION
	Due to how the scrollers of a Workbench window affect the positions
	of the icons inside that window, some icons may not be drawn inside
	the bounds of the window. By using MakeWorkbenchObjectVisibleA()
	the window scrollers can be made to scroll such a "hidden" icon
	into view.

   INPUTS
	name -- Name of the icon to make visible. Note that the window
	    the icon resides in must already be open.

	tags -- Additional options.

   TAGS
	No tags are defined yet (V44).

   RESULTS
	result -- FALSE if the icon in question could not be found,
	    TRUE otherwise. If FALSE is returned, you can query the error
	    code using [dos.library/IoErr()](autodocs-3.5/dos-library-ioerr-2.md).

   EXAMPLE
	/* Make the icon for the drawer "SYS:" visible. */
	MakeWorkbenchObjectVisible("SYS:",TAG_END);

   NOTES
	The name of the icon to make visible is interpreted relative
	to the current directory of the program to call
	MakeWorkbenchObjectVisibleA().

	For this function call to succeed, Workbench must be open. This
	means that the LoadWB command was executed and the Workbench
	screen has been opened.

	While the user is dragging icons, no on-screen rendering may
	take place. In this state Workbench may refuse to execute the
	MakeWorkbenchObjectVisible() call and return an error code instead
	(ERROR_OBJECT_IN_USE).

   SEE ALSO
	[dos.library/IoErr](autodocs-3.5/dos-library-ioerr-2.md)

---

## See Also

- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
