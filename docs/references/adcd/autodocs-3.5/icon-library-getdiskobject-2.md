---
title: icon.library/GetDiskObject
manual: autodocs-3.5
chapter: autodocs-3.5
section: icon-library-getdiskobject-2
functions: [IoErr]
libraries: [dos.library]
---

# icon.library/GetDiskObject

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GetDiskObject - read in a Workbench disk object from disk.

   SYNOPSIS
	diskobj = GetDiskObject(name)
	  D0                      A0

	struct [DiskObject](autodocs-3.5/include-workbench-workbench-h.md) *GetDiskObject(STRPTR);

   FUNCTION
	This routine reads in a Workbench disk object in from disk.  The
	name parameter will have ".info" postpended to it, and the
	icon file of that name will be read.  If the call fails,
	it will return NULL.  The reason for the failure may be obtained
	via [IoErr()](autodocs-3.5/dos-library-ioerr-2.md).

	Using this routine protects you from any future changes to
	the way icons are stored within the system.

	A [FreeList](autodocs-3.5/include-workbench-workbench-h.md) structure is allocated just after the [DiskObject](autodocs-3.5/include-workbench-workbench-h.md)
	structure; [FreeDiskObject](autodocs-3.5/icon-library-freediskobject-2.md) makes use of this to get rid of the
	memory that was allocated.

   INPUTS
	name -- name of the object (STRPTR) or NULL if you just want a
	        [DiskObject](autodocs-3.5/include-workbench-workbench-h.md) structure allocated for you (useful when
	        calling AddAppIcon() in workbench.library).

   RESULTS
	diskobj -- the Workbench disk object in question

   SEE ALSO
	[dos.library/IoErr](autodocs-3.5/dos-library-ioerr-2.md)
	[icon.library/DeleteDiskObject](autodocs-3.5/icon-library-deletediskobject-2.md)
	[icon.library/FreeDiskObject](autodocs-3.5/icon-library-freediskobject-2.md)
	[icon.library/GetDiskObjectNew](autodocs-3.5/icon-library-getdiskobjectnew-2.md)
	[icon.library/GetIconTagList](autodocs-3.5/icon-library-geticontaglist.md)
	[icon.library/NewDiskObject](autodocs-3.5/icon-library-newdiskobject.md)
	[icon.library/PutDiskObject](autodocs-3.5/icon-library-putdiskobject-2.md)
	[icon.library/PutIconTagList](autodocs-3.5/icon-library-puticontaglist.md)
	[workbench.library/AddAppIconA](autodocs-3.5/workbench-library-addappicona-2.md)

---

## See Also

- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
