---
title: exec.library/CloseLibrary
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-closelibrary-2
functions: [OpenLibrary]
libraries: [exec.library]
---

# exec.library/CloseLibrary

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CloseLibrary -- conclude access to a library

   SYNOPSIS
	CloseLibrary(library)
		     A1

	void CloseLibrary(struct [Library](autodocs-3.5/include-exec-libraries-h.md) *);

   FUNCTION
	This function informs the system that access to the given library
	has been concluded.  The user must not reference the library or any
	function in the library after this close.

	Starting with V36, it is safe to pass a NULL instead of
	a library pointer.

   INPUTS
	library - pointer to a library node

   NOTE
	[Library](autodocs-3.5/include-exec-libraries-h.md) writers must pass a SegList pointer or NULL back from their
	open point.  This value is used by the system, and not visible as
	a return code from CloseLibrary.

   SEE ALSO
	[OpenLibrary()](autodocs-3.5/exec-library-openlibrary-2.md)

---

## See Also

- [OpenLibrary — exec.library](../autodocs/exec.library.md#openlibrary)
