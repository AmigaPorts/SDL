---
title: disk.resource/FreeUnit
manual: autodocs-3.5
chapter: autodocs-3.5
section: disk-resource-freeunit-2
functions: []
libraries: []
---

# disk.resource/FreeUnit

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       FreeUnit - deallocate the disk
   SYNOPSIS
```c
       FreeUnit( unitNum ), DRResource
```
		  D0         A6

	void FreeUnit(LONG);

   FUNCTION
	This routine deallocates one of the units of the disk.  It should
	be called when done with the disk.  Do not call it if you did
	no successfully allocate the disk (there is no protection -- you
	will probably crash the disk system).

   INPUTS
	unitNum -- a legal unit number (zero through three)

   RESULTS

   EXCEPTIONS

   SEE ALSO
	FreeUnit()

   BUGS
	Doesn't check if you own the unit, or even if anyone owns it.

