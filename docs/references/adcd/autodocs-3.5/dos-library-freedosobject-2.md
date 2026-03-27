---
title: dos.library/FreeDosObject
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-freedosobject-2
functions: [AllocDosObject, FreeVec]
libraries: [dos.library, exec.library]
---

# dos.library/FreeDosObject

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FreeDosObject -- Frees an object allocated by [AllocDosObject()](autodocs-3.5/dos-library-allocdosobject-2.md) (V36)

   SYNOPSIS
	FreeDosObject(type, ptr)
		       D1   D2

	void FreeDosObject(ULONG, void *)

   FUNCTION
	Frees an object allocated by [AllocDosObject()](autodocs-3.5/dos-library-allocdosobject-2.md).  Do NOT call for
	objects allocated in any other way.

   INPUTS
	type - type passed to [AllocDosObject()](autodocs-3.5/dos-library-allocdosobject-2.md)
	ptr  - ptr returned by [AllocDosObject()](autodocs-3.5/dos-library-allocdosobject-2.md)

   BUGS
	Before V39, DOS_CLI objects will only have the struct
	[CommandLineInterface](autodocs-3.5/include-dos-dosextens-h.md) freed, not the strings it points to.  This
	is fixed in V39 dos.  Before V39, you can workaround this bug by
	using [FreeVec()](autodocs-3.5/exec-library-freevec-2.md) on cli_SetName, cli_CommandFile, cli_CommandName,
	and cli_Prompt, and then setting them all to NULL.  In V39 or
	above, do NOT use the workaround.

   SEE ALSO
	[AllocDosObject()](autodocs-3.5/dos-library-allocdosobject-2.md), [FreeVec()](autodocs-3.5/exec-library-freevec-2.md), [<dos/dos.h>](autodocs-3.5/include-dos-dos-h.md)

---

## See Also

- [AllocDosObject — dos.library](../autodocs/dos.library.md#allocdosobject)
- [FreeVec — exec.library](../autodocs/exec.library.md#freevec)
