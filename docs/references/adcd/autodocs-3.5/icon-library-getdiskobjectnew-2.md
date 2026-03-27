---
title: icon.library/GetDiskObjectNew
manual: autodocs-3.5
chapter: autodocs-3.5
section: icon-library-getdiskobjectnew-2
functions: [GetDefDiskObject, GetDiskObject, IoErr]
libraries: [dos.library, icon.library]
---

# icon.library/GetDiskObjectNew

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GetDiskObjectNew - read in a Workbench disk object from disk.    (V36)

   SYNOPSIS
	diskobj = GetDiskObjectNew(name)
	  D0                      A0

	struct [DiskObject](autodocs-3.5/include-workbench-workbench-h.md) *GetDiskObjectNew(STRPTR);

   FUNCTION
	This routine reads in a Workbench disk object in from disk.  The
	name parameter will have ".info" postpended to it, and the
	icon file of that name will be read.  If the call fails,
	it will return zero.  The reason for the failure may be obtained
	via [IoErr()](autodocs-3.5/dos-library-ioerr-2.md).

	Using this routine protects you from any future changes to
	the way icons are stored within the system.

	A [FreeList](autodocs-3.5/include-workbench-workbench-h.md) structure is allocated just after the [DiskObject](autodocs-3.5/include-workbench-workbench-h.md)
	structure; [FreeDiskObject](autodocs-3.5/icon-library-freediskobject-2.md) makes use of this to get rid of the
	memory that was allocated.

	This call is functionally identical to [GetDiskObject()](autodocs-3.5/icon-library-getdiskobject-2.md) with one
	exception. If its call to [GetDiskObject()](autodocs-3.5/icon-library-getdiskobject-2.md) fails, this function calls
	[GetDefDiskObject()](autodocs-3.5/icon-library-getdefdiskobject-2.md). This is useful when there is no .info file for the
	icon you are trying to get a disk object for. Applications that use
	workbench application windows MUST use this call if they want to handle
	the user dropping an icon (that doesn't have a ".info" file) on their
	window. The V2.0 icon editor program is an example of a Workbench
	application window that uses this call.

   INPUTS
	name -- name of the object (STRPTR) or NULL if you just want a
	        [DiskObject](autodocs-3.5/include-workbench-workbench-h.md) structure allocated for you (useful when
	        calling AddAppIcon() in workbench.library).

   RESULTS
	diskobj -- the Workbench disk object in question

   SEE ALSO
	[dos.library/IoErr](autodocs-3.5/dos-library-ioerr-2.md)
	[icon.library/FreeDiskObject](autodocs-3.5/icon-library-freediskobject-2.md)
	[icon.library/GetDiskObject](autodocs-3.5/icon-library-getdiskobject-2.md)
	[icon.library/PutDiskObject](autodocs-3.5/icon-library-putdiskobject-2.md)
	[icon.library/DeleteDiskObject](autodocs-3.5/icon-library-deletediskobject-2.md)
	[icon.library/GetIconTagList](autodocs-3.5/icon-library-geticontaglist.md)
	[icon.library/PutIconTagList](autodocs-3.5/icon-library-puticontaglist.md)
	[workbench.library/AddAppIconA](autodocs-3.5/workbench-library-addappicona-2.md)

---

## See Also

- [GetDefDiskObject — icon.library](../autodocs/icon.library.md#getdefdiskobject)
- [GetDiskObject — icon.library](../autodocs/icon.library.md#getdiskobject)
- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
