---
title: icon.library/PutDiskObject
manual: autodocs-3.5
chapter: autodocs-3.5
section: icon-library-putdiskobject-2
functions: [GetDiskObject, IoErr, PutDiskObject]
libraries: [dos.library, icon.library]
---

# icon.library/PutDiskObject

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	PutDiskObject - write out a [DiskObject](autodocs-3.5/include-workbench-workbench-h.md) to disk.

   SYNOPSIS
	status = PutDiskObject(name, diskobj)
	 D0                    A0      A1

	[BOOL](autodocs-3.5/include-exec-types-h.md) PutDiskObject(STRPTR, struct [DiskObject](autodocs-3.5/include-workbench-workbench-h.md) *);

   FUNCTION
	This routine writes out a [DiskObject](autodocs-3.5/include-workbench-workbench-h.md) structure, and its
	associated information.  The file name of the info
	file will be the name parameter with ".info" postpended
	to it.  If the call fails, FALSE will be returned.  The
	reason for the failure may be obtained via [IoErr()](autodocs-3.5/dos-library-ioerr-2.md).

	As of release V2.0, PutDiskObject() (if successful) notifies Workbench
	when an icon has been created/modified.

	Using this routine protects you from any future changes to
	the way icons are stored within the system.

   INPUTS
	name -- name of the object (pointer to a character string)
	diskobj -- a pointer to a [DiskObject](autodocs-3.5/include-workbench-workbench-h.md)

   RESULTS
	status -- TRUE if the call succeeded else FALSE

   NOTES
	It is recommended that if you wish to copy an icon from one place
	to another than you use [GetDiskObject()](autodocs-3.5/icon-library-getdiskobject-2.md) and PutDiskObject()
	and do not copy them directly.

   SEE ALSO
	[dos.library/IoErr](autodocs-3.5/dos-library-ioerr-2.md)
	[icon.library/DeleteDiskObject](autodocs-3.5/icon-library-deletediskobject-2.md)
	[icon.library/FreeDiskObject](autodocs-3.5/icon-library-freediskobject-2.md)
	[icon.library/GetDiskObject](autodocs-3.5/icon-library-getdiskobject-2.md)
	[icon.library/GetIconTagList](autodocs-3.5/icon-library-geticontaglist.md)
	[icon.library/PutIconTagList](autodocs-3.5/icon-library-puticontaglist.md)

---

## See Also

- [GetDiskObject — icon.library](../autodocs/icon.library.md#getdiskobject)
- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [PutDiskObject — icon.library](../autodocs/icon.library.md#putdiskobject)
