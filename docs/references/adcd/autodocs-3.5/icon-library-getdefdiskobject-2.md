---
title: icon.library/GetDefDiskObject
manual: autodocs-3.5
chapter: autodocs-3.5
section: icon-library-getdefdiskobject-2
functions: [IoErr]
libraries: [dos.library]
---

# icon.library/GetDefDiskObject

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GetDefDiskObject - read default wb disk object from disk.       (V36)

   SYNOPSIS
	diskobj = GetDefDiskObject(def_type)
	  D0                          D0

	struct [DiskObject](autodocs-3.5/include-workbench-workbench-h.md) *GetDefDiskObject(LONG);

   FUNCTION
	This routine reads in a default Workbench disk object from disk.
	The valid def_types can be found in [workbench/workbench.h](autodocs-3.5/include-workbench-workbench-h.md) and
	currently include WBDISK thru WBKICK. If the call fails,
	it will return NULL. The reason for the failure may be obtained
	via [IoErr()](autodocs-3.5/dos-library-ioerr-2.md).

	Using this routine protects you from any future changes to
	the way default icons are stored within the system.

   INPUTS
	def_type -- default icon type (WBDISK thru WBKICK).

   RESULTS
	diskobj -- the default Workbench disk object in question

   NOTES
	icon.library V36 through V40 did not support the WBDEVICE default
	icon type.

   SEE ALSO
	[dos.library/IoErr](autodocs-3.5/dos-library-ioerr-2.md)
	[icon.library/PutDefDiskObject](autodocs-3.5/icon-library-putdefdiskobject-2.md)
	[icon.library/PutIconTagList](autodocs-3.5/icon-library-puticontaglist.md)

---

## See Also

- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
