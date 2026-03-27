---
title: icon.library/NewDiskObject
manual: autodocs-3.5
chapter: autodocs-3.5
section: icon-library-newdiskobject
functions: [IoErr]
libraries: [dos.library]
---

# icon.library/NewDiskObject

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	NewDiskObject -- Create an empty icon (V44)

   SYNOPSIS
	icon = NewDiskObject(type)
	D0                   D0

	struct [DiskObject](autodocs-3.5/include-workbench-workbench-h.md) * NewDiskObject(LONG type);

   FUNCTION
	This function is used to create an "empty" [DiskObject](autodocs-3.5/include-workbench-workbench-h.md)
	structure, which has no image data associated with it.
	Still, all the necessary structures are in place,
	you just have to fill them in.

   INPUTS
	type -- Icon type to create, this must be one of WBDISK,
	    WBDRAWER, WBTOOL, WBPROJECT, WBGARBAGE, WBDEVICE or WBKICK.

   RESULT
	icon -- Pointer to a struct [DiskObject](autodocs-3.5/include-workbench-workbench-h.md) or NULL in case of error.
	    You can use [IoErr()](autodocs-3.5/dos-library-ioerr-2.md) to retrieve the error code.

   NOTES
	The [DiskObject](autodocs-3.5/include-workbench-workbench-h.md) returned by this function will have a zero
	width and height [Image](autodocs-3.5/include-intuition-intuition-h.md) in the do_Gadget.GadgetRender member
	and the do_Gadget.Width/do_Gadget.Height members will both
	be 0, too.

   SEE ALSO
	[dos.library/IoErr](autodocs-3.5/dos-library-ioerr-2.md)
	[workbench/icon.h](autodocs-3.5/include-workbench-icon-h.md)
	[workbench/workbench.h](autodocs-3.5/include-workbench-workbench-h.md)

---

## See Also

- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
