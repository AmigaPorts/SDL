---
title: exec.library/FindResident
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-findresident-2
functions: [InitResident]
libraries: [exec.library]
---

# exec.library/FindResident

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FindResident - find a resident module by name

   SYNOPSIS
	resident = FindResident(name)
	D0			A1

	struct [Resident](autodocs-3.5/include-exec-resident-h.md) *FindResident(STRPTR);

   FUNCTION
	Search the system resident tag list for a resident tag ("ROMTag") with
	the given name.  If found return a pointer to the resident tag
	structure, else return zero.

	[Resident](autodocs-3.5/include-exec-resident-h.md) modules are used by the system to pull all its parts
	together at startup.  [Resident](autodocs-3.5/include-exec-resident-h.md) tags are also found in disk based
	devices and libraries.

   INPUTS
	name - pointer to name string

   RESULT
	resident - pointer to the resident tag structure or
		zero if none found.

    SEE ALSO
	[exec/resident.h](autodocs-3.5/include-exec-resident-h.md), [InitResident()](autodocs-3.5/exec-library-initresident-2.md)

---

## See Also

- [InitResident — exec.library](../autodocs/exec.library.md#initresident)
