---
title: dos.library/FindVar
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-findvar-2
functions: [DeleteVar, GetVar, SetVar]
libraries: [dos.library]
---

# dos.library/FindVar

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FindVar -- Finds a local variable (V36)

   SYNOPSIS
	var = FindVar( name, type )
	D0		D1    D2

	struct [LocalVar](autodocs-3.5/include-dos-var-h.md) * FindVar(STRPTR, ULONG )

   FUNCTION
	Finds a local variable structure.

   INPUTS
	name - pointer to an variable name.  Note variable names follow
	       filesystem syntax and semantics.

	type - type of variable to be found (see [<dos/var.h>](autodocs-3.5/include-dos-var-h.md))

   RESULT

	var  - pointer to a [LocalVar](autodocs-3.5/include-dos-var-h.md) structure or NULL

   SEE ALSO
	[GetVar()](autodocs-3.5/dos-library-getvar-2.md), [SetVar()](autodocs-3.5/dos-library-setvar-2.md), [DeleteVar()](autodocs-3.5/dos-library-deletevar-2.md), [<dos/var.h>](autodocs-3.5/include-dos-var-h.md)

---

## See Also

- [DeleteVar — dos.library](../autodocs/dos.library.md#deletevar)
- [GetVar — dos.library](../autodocs/dos.library.md#getvar)
- [SetVar — dos.library](../autodocs/dos.library.md#setvar)
