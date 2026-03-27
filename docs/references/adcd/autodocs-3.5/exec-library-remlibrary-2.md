---
title: exec.library/RemLibrary
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-remlibrary-2
functions: [Forbid, Permit]
libraries: [exec.library]
---

# exec.library/RemLibrary

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	RemLibrary -- remove a library from the system

   SYNOPSIS
	RemLibrary(library)
	           A1

	void RemLibrary(struct [Library](autodocs-3.5/include-exec-libraries-h.md) *);

   FUNCTION
	This function calls the library's EXPUNGE vector, which requests
	that a library delete itself.  The library may refuse to do this if
	it is busy or currently open. This is not typically called by user
	code.

	There are certain, limited circumstances where it may be
	appropriate to attempt to specifically flush a certain [Library](autodocs-3.5/include-exec-libraries-h.md).
	Example:

	 /* Attempts to flush the named library out of memory. */
	 #include [<exec/types.h>](autodocs-3.5/include-exec-types-h.md)
	 #include [<exec/execbase.h>](autodocs-3.5/include-exec-execbase-h.md)

	 void FlushLibrary(name)
	 [STRPTR](autodocs-3.5/include-exec-types-h.md) name;
	 {
	 struct [Library](autodocs-3.5/include-exec-libraries-h.md) *result;

	    Forbid();
	    if(result=(struct [Library](autodocs-3.5/include-exec-libraries-h.md) *)FindName(&SysBase->LibList,name))
		RemLibrary(result);
	    Permit();
	 }

   INPUTS
	library - pointer to a library node structure

---

## See Also

- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [Permit — exec.library](../autodocs/exec.library.md#permit)
