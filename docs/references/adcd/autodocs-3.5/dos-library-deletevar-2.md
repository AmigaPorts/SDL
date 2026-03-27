---
title: dos.library/DeleteVar
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-deletevar-2
functions: [FindVar, GetVar, SetVar]
libraries: [dos.library]
---

# dos.library/DeleteVar

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	DeleteVar -- Deletes a local or environment variable (V36)

   SYNOPSIS
	success = DeleteVar( name, flags )
	D0		      D1    D2

	[BOOL](autodocs-3.5/include-exec-types-h.md) DeleteVar(STRPTR, ULONG )

   FUNCTION
	Deletes a local or environment variable.

   INPUTS
	name   - pointer to an variable name.  Note variable names follow
		 filesystem syntax and semantics.
	flags  - combination of type of var to delete (low 8 bits), and
		 flags to control the behavior of this routine.  Currently
		 defined flags include:

		 GVF_LOCAL_ONLY  - delete a local (to your process) variable.
		 GVF_GLOBAL_ONLY - delete a global environment variable.

		 The default is to delete a local variable if found, otherwise
		 a global environment variable if found (only for LV_VAR).

   RESULT
	success - If non-zero, the variable was sucessfully deleted, FALSE
		  indicates failure.

   BUGS
	LV_VAR is the only type that can be global

   SEE ALSO
	[GetVar()](autodocs-3.5/dos-library-getvar-2.md), [SetVar()](autodocs-3.5/dos-library-setvar-2.md), [FindVar()](autodocs-3.5/dos-library-findvar-2.md), [DeleteFile()](autodocs-3.5/dos-library-deletefile-2.md), [<dos/var.h>](autodocs-3.5/include-dos-var-h.md)

---

## See Also

- [FindVar — dos.library](../autodocs/dos.library.md#findvar)
- [GetVar — dos.library](../autodocs/dos.library.md#getvar)
- [SetVar — dos.library](../autodocs/dos.library.md#setvar)
