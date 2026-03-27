---
title: disk.resource/ReadUnitID
manual: autodocs-3.5
chapter: autodocs-3.5
section: disk-resource-readunitid-2
functions: []
libraries: []
---

# disk.resource/ReadUnitID

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

```c
       ReadUnitID - reread and return the type of drive (V37)
```
   SYNOPSIS
```c
       idtype = ReadUnitID( unitNum ), DRResource
```
	D0	               D0         A6

	ULONG ReadUnitID(LONG);

   FUNCTION
	Rereads the drive id for a specific unit (for handling drives
	that change ID according to what sort of disk is in them.  You
	MUST have done a [GetUnit](autodocs-3.5/disk-resource-getunit-2.md) before calling this function!

   INPUTS
	unitNum -- a legal unit number (zero through three)

   RESULTS
	idtype -- the type of the disk drive.  Standard types are
		defined in the resource include file.

   EXCEPTIONS

   SEE ALSO
	[GetUnitID()](autodocs-3.5/disk-resource-getunitid-2.md)

   BUGS

