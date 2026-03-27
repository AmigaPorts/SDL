---
title: workbench.library/CloseWorkbenchObjectAorkbench.library/CloseWorkbenchObjectA
manual: autodocs-3.5
chapter: autodocs-3.5
section: workbench-library-closeworkbenchobjectaorkbench-library
functions: [IoErr]
libraries: [dos.library]
---

# workbench.library/CloseWorkbenchObjectAorkbench.library/CloseWorkbenchObjectA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CloseWorkbenchObjectA -- [Close](autodocs-3.5/dos-library-close-2.md) a drawer as if the user had clicked
	    on the window close gadget. (V44)

   SYNOPSIS
	success = CloseWorkbenchObjectA(name,tags)
	   D0                            A0   A1

	[BOOL](autodocs-3.5/include-exec-types-h.md) CloseWorkbenchObjectA(STRPTR name,struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *tags);

	success = CloseWorkbenchObject(name,...);

	[BOOL](autodocs-3.5/include-exec-types-h.md) CloseWorkbenchObject(STRPTR name,...);

   FUNCTION
	This routine attempts to close the named object as if the user
	had clicked on its drawer window close gadget.

   INPUTS
	name -- Name of the drawer to be closed.

	tags -- Additional options.

   TAGS
	No tags are defined yet (V44).

   RESULTS
	result -- FALSE if the object in question could not be closed,
	    TRUE otherwise. If FALSE is returned, you can query the error
	    code using [dos.library/IoErr()](autodocs-3.5/dos-library-ioerr-2.md).

   EXAMPLE
	/* [Close](autodocs-3.5/dos-library-close-2.md) the drawer "SYS:" */
	CloseWorkbenchObjectA("SYS:",NULL);

   NOTES
	The name of the drawer to be closed is interpreted relative
	to the current directory of the program to call
	CloseWorkbenchObjectA().

	For this function call to succeed, Workbench must be open. This
	means that the LoadWB command was executed and the Workbench
	screen has been opened.

	While the user is dragging icons, no on-screen rendering may
	take place. In this state Workbench may refuse to execute the
	CloseWorkbenchObject() call and return an error code instead
	(ERROR_OBJECT_IN_USE).

   SEE ALSO
	[dos.library/IoErr](autodocs-3.5/dos-library-ioerr-2.md)
	[workbench.library/OpenWorkbenchObjectA](autodocs-3.5/workbench-library-openworkbenchobjecta.md)

---

## See Also

- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
