---
title: icon.library/DeleteDiskObject
manual: autodocs-3.5
chapter: autodocs-3.5
section: icon-library-deletediskobject-2
functions: [IoErr]
libraries: [dos.library]
---

# icon.library/DeleteDiskObject

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	DeleteDiskObject - Delete a Workbench disk object from disk.     (V37)

   SYNOPSIS
	result = DeleteDiskObject(name)
	  D0                      A0

	[BOOL](autodocs-3.5/include-exec-types-h.md) DeleteDiskObject(STRPTR);

   FUNCTION
	This routine will try to delete a Workbench disk object from disk.
	The name parameter will have ".info" postpended to it, and the
	icon file of that name will be deleted.  If the call fails,
	it will return FALSE. The reason for the failure may be obtained
	via [dos.library/IoErr()](autodocs-3.5/dos-library-ioerr-2.md).

	This call also updates the Workbench screen if needed.

	Using this routine protects you from any future changes to
	the way icons are stored within the system.

   INPUTS
	name -- name of the object (char *)

   RESULTS
	result -- TRUE if it worked, FALSE if not.

   EXAMPLE

	error = 0;

	/* Check if you have the right library version */
	if(IconBase->lib_Version > 36)
	{
	    if (!DeleteDiskObject(name))
	        error = IoErr();
	}
	else
	{
	    /* Delete name plus ".info" */
	}

	if (error != 0)
	{
	    /* Do error routine...*/
	}

   SEE ALSO
	[dos.library/IoErr](autodocs-3.5/dos-library-ioerr-2.md)
	[icon.library/PutDiskObject](autodocs-3.5/icon-library-putdiskobject-2.md)
	[icon.library/GetDiskObject](autodocs-3.5/icon-library-getdiskobject-2.md)
	[icon.library/FreeDiskObject](autodocs-3.5/icon-library-freediskobject-2.md)
	[icon.library/GetIconTagList](autodocs-3.5/icon-library-geticontaglist.md)
	[icon.library/PutIconTagList](autodocs-3.5/icon-library-puticontaglist.md)

---

## See Also

- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
