---
title: disk.resource/GiveUnit
manual: autodocs-3.5
chapter: autodocs-3.5
section: disk-resource-giveunit-2
functions: []
libraries: []
---

# disk.resource/GiveUnit

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       GiveUnit - Free the disk back up
   SYNOPSIS

```c
       GiveUnit(), DRResource
           	    A6
```
	void GiveUnit();

   FUNCTION
	This routine frees the disk after a driver is done with it.
	If others are waiting, it will notify them.

   INPUTS

   RESULTS

   EXCEPTIONS

   SEE ALSO
	[GetUnit()](autodocs-3.5/disk-resource-getunit-2.md)

   BUGS
	In pre-V36, GiveUnit didn't check if you owned the unit.  A patch
	for this was part of 1.3.1 SetPatch.  Fixed in V36.

