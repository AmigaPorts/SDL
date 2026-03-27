---
title: icon.library/PutDefDiskObject
manual: autodocs-3.5
chapter: autodocs-3.5
section: icon-library-putdefdiskobject-2
functions: [IoErr, PutDiskObject]
libraries: [dos.library, icon.library]
---

# icon.library/PutDefDiskObject

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	PutDefDiskObject - write disk object as the default for its type.  (V36)

   SYNOPSIS
	status = PutDefDiskObject(diskobj)
	  D0                        A0

	[BOOL](autodocs-3.5/include-exec-types-h.md) PutDefDiskObject(struct [DiskObject](autodocs-3.5/include-workbench-workbench-h.md) *);

   FUNCTION
	This routine writes out a [DiskObject](autodocs-3.5/include-workbench-workbench-h.md) structure, and its
	associated information.  If the call fails, FALSE will
	be returned.  The reason for the failure may be obtained
	via [IoErr()](autodocs-3.5/dos-library-ioerr-2.md).

	Note that this function calls [PutDiskObject()](autodocs-3.5/icon-library-putdiskobject-2.md) internally which means
	that this call (if sucessful) notifies workbench than an icon has
	been created/modified.

	Using this routine protects you from any future changes to
	the way default icons are stored within the system.

   INPUTS
	diskobj -- a pointer to a [DiskObject](autodocs-3.5/include-workbench-workbench-h.md)

   RESULTS
	status -- TRUE if the call succeeded else FALSE

   SEE ALSO
	[dos.library/IoErr](autodocs-3.5/dos-library-ioerr-2.md)
	[icon.library/GetDefDiskObject](autodocs-3.5/icon-library-getdefdiskobject-2.md)
	[icon.library/GetIconTagList](autodocs-3.5/icon-library-geticontaglist.md)
	[icon.library/PutDiskObject](autodocs-3.5/icon-library-putdiskobject-2.md)

---

## See Also

- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [PutDiskObject — icon.library](../autodocs/icon.library.md#putdiskobject)
