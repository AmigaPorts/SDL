---
title: icon.library/FreeDiskObject
manual: autodocs-3.5
chapter: autodocs-3.5
section: icon-library-freediskobject-2
functions: [FreeFreeList, GetDiskObject]
libraries: [icon.library]
---

# icon.library/FreeDiskObject

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FreeDiskObject - free all memory in a Workbench disk object.

   SYNOPSIS
	FreeDiskObject(diskobj)
	               A0

	void FreeDiskObject(struct [DiskObject](autodocs-3.5/include-workbench-workbench-h.md) *);

   FUNCTION
	This routine frees all memory in a Workbench disk object, and the
	object itself.  It is implemented via [FreeFreeList()](autodocs-3.5/icon-library-freefreelist-2.md).

	[GetDiskObject()](autodocs-3.5/icon-library-getdiskobject-2.md) takes care of all the initialization required
	to set up the object's free list.  This procedure may ONLY
	be called on a [DiskObject](autodocs-3.5/include-workbench-workbench-h.md) allocated via [GetDiskObject()](autodocs-3.5/icon-library-getdiskobject-2.md).

   INPUTS
	diskobj -- a pointer to a [DiskObject](autodocs-3.5/include-workbench-workbench-h.md) structure; as of V44,
	    a NULL diskobj pointer will be ignored.

   SEE ALSO
	[icon.library/GetDiskObject](autodocs-3.5/icon-library-getdiskobject-2.md)
	[icon.library/PutDiskObject](autodocs-3.5/icon-library-putdiskobject-2.md)
	[icon.library/DeleteDiskObject](autodocs-3.5/icon-library-deletediskobject-2.md)
	[icon.library/FreeFreeList](autodocs-3.5/icon-library-freefreelist-2.md)
	[icon.library/GetIconTagList](autodocs-3.5/icon-library-geticontaglist.md)
	[icon.library/PutIconTagList](autodocs-3.5/icon-library-puticontaglist.md)

---

## See Also

- [FreeFreeList — icon.library](../autodocs/icon.library.md#freefreelist)
- [GetDiskObject — icon.library](../autodocs/icon.library.md#getdiskobject)
