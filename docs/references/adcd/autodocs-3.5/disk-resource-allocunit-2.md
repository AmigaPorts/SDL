---
title: disk.resource/AllocUnit
manual: autodocs-3.5
chapter: autodocs-3.5
section: disk-resource-allocunit-2
functions: []
libraries: []
---

# disk.resource/AllocUnit

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       AllocUnit - allocate a unit of the disk
   SYNOPSIS
```c
       Success = AllocUnit( unitNum ), DRResource
```
	D0     	             D0         A6

	[BOOL](autodocs-3.5/include-exec-types-h.md) AllocUnit(LONG);

   FUNCTION
	This routine allocates one of the units of the disk.  It should
	be called before trying to use the disk (via GetUnit).

	In reality, it is perfectly fine to use [GetUnit/GiveUnit](autodocs-3.5/disk-resource-giveunit-2.md) if AllocUnit
	fails.  Do NOT call [FreeUnit](autodocs-3.5/disk-resource-freeunit-2.md) if AllocUnit did not succeed.  This
	has been the case for all revisions of disk.resource.

   INPUTS
	unitNum -- a legal unit number (zero through three)

   RESULTS
	Success -- nonzero if successful.  zero on failure.

   EXCEPTIONS

   SEE ALSO

   BUGS

