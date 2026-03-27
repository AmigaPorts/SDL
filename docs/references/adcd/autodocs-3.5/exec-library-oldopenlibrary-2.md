---
title: exec.library/OldOpenLibrary
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-oldopenlibrary-2
functions: [CloseLibrary]
libraries: [exec.library]
---

# exec.library/OldOpenLibrary

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	OldOpenLibrary -- obsolete [OpenLibrary](autodocs-3.5/exec-library-openlibrary-2.md)

   SYNOPSIS
	library = OldOpenLibrary(libName)
	D0			 A1

	struct [Library](autodocs-3.5/include-exec-libraries-h.md) *OldOpenLibrary(APTR);

   FUNCTION
	The 1.0 release of the Amiga system had an incorrect version of
	[OpenLibrary](autodocs-3.5/exec-library-openlibrary-2.md) that did not check the version number during the
	library open.  This obsolete function is provided so that object
	code compiled using a 1.0 system will still run.

	This exactly the same as "OpenLibrary(libName,0L);"

   INPUTS
	libName - the name of the library to open

   RESULTS
	library - a library pointer for a successful open, else zero

   SEE ALSO
	[CloseLibrary()](autodocs-3.5/exec-library-closelibrary-2.md)

---

## See Also

- [CloseLibrary — exec.library](../autodocs/exec.library.md#closelibrary)
