---
title: dos.library/SetVar
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-setvar-2
functions: [DeleteVar, FindVar, GetVar]
libraries: [dos.library]
---

# dos.library/SetVar

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SetVar -- Sets a local or environment variable (V36)

   SYNOPSIS
	success = SetVar( name, buffer, size, flags )
	D0	           D1     D2     D3    D4

	[BOOL](autodocs-3.5/include-exec-types-h.md) SetVar(STRPTR, [STRPTR](autodocs-3.5/include-exec-types-h.md), [LONG](autodocs-3.5/include-exec-types-h.md), ULONG )

   FUNCTION
	Sets a local or environment variable.  It is advised to only use
	ASCII strings inside variables, but not required.

   INPUTS
	name   - pointer to an variable name.  Note variable names follow
		 filesystem syntax and semantics.
	buffer - a user allocated area which contains a string that is the
		 value to be associated with this variable.
	size   - length of the buffer region in bytes.  -1 means buffer
		 contains a null-terminated string.
	flags  - combination of type of var to set (low 8 bits), and
		 flags to control the behavior of this routine.  Currently
		 defined flags include:

		GVF_LOCAL_ONLY - set a local (to your process) variable.
		GVF_GLOBAL_ONLY - set a global environment variable.

		The default is to set a local environment variable.

   RESULT
	success - If non-zero, the variable was sucessfully set, FALSE
	 	  indicates failure.

   BUGS
	LV_VAR is the only type that can be global

   SEE ALSO
	[GetVar()](autodocs-3.5/dos-library-getvar-2.md), [DeleteVar()](autodocs-3.5/dos-library-deletevar-2.md), [FindVar()](autodocs-3.5/dos-library-findvar-2.md), [<dos/var.h>](autodocs-3.5/include-dos-var-h.md)

---

## See Also

- [DeleteVar — dos.library](../autodocs/dos.library.md#deletevar)
- [FindVar — dos.library](../autodocs/dos.library.md#findvar)
- [GetVar — dos.library](../autodocs/dos.library.md#getvar)
