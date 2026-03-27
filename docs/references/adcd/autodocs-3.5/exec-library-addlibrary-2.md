---
title: exec.library/AddLibrary
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-addlibrary-2
functions: [CloseLibrary, OpenLibrary, RemLibrary]
libraries: [exec.library]
---

# exec.library/AddLibrary

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AddLibrary -- add a library to the system

   SYNOPSIS
	AddLibrary(library)
		   A1

	void AddLibrary(struct [Library](autodocs-3.5/include-exec-libraries-h.md) *);

   FUNCTION
	This function adds a new library to the system, making it available
	to other programs.  The library should be ready to be opened at
	this time.  It will be added to the system library name list, and
	the checksum on the library entries will be calculated.

   INPUTS
	library - pointer to a properly initialized library structure

   SEE ALSO
	[RemLibrary()](autodocs-3.5/exec-library-remlibrary-2.md), [CloseLibrary()](autodocs-3.5/exec-library-closelibrary-2.md), [OpenLibrary()](autodocs-3.5/exec-library-openlibrary-2.md), [MakeLibrary()](autodocs-3.5/exec-library-makelibrary-2.md)

---

## See Also

- [CloseLibrary — exec.library](../autodocs/exec.library.md#closelibrary)
- [OpenLibrary — exec.library](../autodocs/exec.library.md#openlibrary)
- [RemLibrary — exec.library](../autodocs/exec.library.md#remlibrary)
