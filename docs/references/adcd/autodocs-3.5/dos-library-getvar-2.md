---
title: dos.library/GetVar
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-getvar-2
functions: [DeleteVar, FindVar, IoErr, SetVar]
libraries: [dos.library]
---

# dos.library/GetVar

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GetVar -- Returns the value of a local or global variable (V36)

   SYNOPSIS
	len = GetVar( name, buffer, size, flags )
	D0	       D1     D2     D3    D4

	[LONG](autodocs-3.5/include-exec-types-h.md) GetVar( [STRPTR](autodocs-3.5/include-exec-types-h.md), [STRPTR](autodocs-3.5/include-exec-types-h.md), [LONG](autodocs-3.5/include-exec-types-h.md), ULONG )

   FUNCTION
	Gets the value of a local or environment variable.  It is advised to
 	only use ASCII strings inside variables, but not required.  This stops
	putting characters into the destination when a n is hit, unless
	GVF_BINARY_VAR is specified.  (The n is not stored in the buffer.)

   INPUTS
	name   - pointer to a variable name.
	buffer - a user allocated area which will be used to store
		 the value associated with the variable.
	size   - length of the buffer region in bytes.
	flags  - combination of type of var to get value of (low 8 bits), and
		 flags to control the behavior of this routine.  Currently
		 defined flags include:

			GVF_GLOBAL_ONLY - tries to get a global env variable.
			GVF_LOCAL_ONLY  - tries to get a local variable.
			GVF_BINARY_VAR  - don't stop at n
			GVF_DONT_NULL_TERM - no null termination (only valid
					  for binary variables). (V37)

		 The default is to try to get a local variable first, then
		 to try to get a global environment variable.

   RESULT
	len -   Size of environment variable.  -1 indicates that the
		variable was not defined (if [IoErr()](autodocs-3.5/dos-library-ioerr-2.md) returns
		ERROR_OBJECT_NOT_FOUND - it returns ERROR_BAD_NUMBER if
		you specify a size of 0).  If the value would overflow
		the user buffer, the buffer is truncated.  The buffer
		returned is null-terminated (even if GVF_BINARY_VAR is
		used, unless GVF_DONT_NULL_TERM is in effect).  If it
		succeeds, len is the number of characters put in the buffer
		(not including null termination), and [IoErr()](autodocs-3.5/dos-library-ioerr-2.md) will return the
		the size of the variable (regardless of buffer size).

   BUGS
	LV_VAR is the only type that can be global.
	Under V36, we documented (and it returned) the size of the variable,
	not the number of characters transferred.  For V37 this was changed
	to the number of characters put in the buffer, and the total size
	of the variable is put in [IoErr()](autodocs-3.5/dos-library-ioerr-2.md).
	GVF_DONT_NULL_TERM only works for local variables under V37.  For
	V39, it also works for globals.

   SEE ALSO
	[SetVar()](autodocs-3.5/dos-library-setvar-2.md), [DeleteVar()](autodocs-3.5/dos-library-deletevar-2.md), [FindVar()](autodocs-3.5/dos-library-findvar-2.md), [<dos/var.h>](autodocs-3.5/include-dos-var-h.md)

---

## See Also

- [DeleteVar — dos.library](../autodocs/dos.library.md#deletevar)
- [FindVar — dos.library](../autodocs/dos.library.md#findvar)
- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [SetVar — dos.library](../autodocs/dos.library.md#setvar)
