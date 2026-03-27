---
title: disk.resource/GetUnitID
manual: autodocs-3.5
chapter: autodocs-3.5
section: disk-resource-getunitid-2
functions: []
libraries: []
---

# disk.resource/GetUnitID

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       GetUnitID - find out what type of disk is out there
   SYNOPSIS
```c
       idtype = GetUnitID( unitNum ), DRResource
```
	D0	            D0         A6

	[LONG](autodocs-3.5/include-exec-types-h.md) GetUnitID(LONG);

   FUNCTION
	Gets the drive ID for a given unit.  Note that this value may
	change if someone calls [ReadUnitID](autodocs-3.5/disk-resource-readunitid-2.md), and the drive id changes.

   INPUTS
	unitNum -- a legal unit number (zero through three)

   RESULTS
	idtype -- the type of the disk drive.  Standard types are
		defined in the resource include file.

   EXCEPTIONS

   SEE ALSO
	[ReadUnitID()](autodocs-3.5/disk-resource-readunitid-2.md)

   BUGS

