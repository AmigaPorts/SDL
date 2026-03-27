---
title: dos.library/MakeLink
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-makelink-2
functions: [Lock, Open]
libraries: [dos.library]
---

# dos.library/MakeLink

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	MakeLink -- Creates a filesystem link (V36)

   SYNOPSIS
	success = MakeLink( name, dest, soft )
	D0		     D1    D2    D3

	[BOOL](autodocs-3.5/include-exec-types-h.md) MakeLink( [STRPTR](autodocs-3.5/include-exec-types-h.md), [LONG](autodocs-3.5/include-exec-types-h.md), [LONG](autodocs-3.5/include-exec-types-h.md) )

   FUNCTION
	Create a filesystem link from 'name' to dest.  For "soft-links",
	dest is a pointer to a null-terminated path string.  For "hard-
	links", dest is a lock (BPTR).  'soft' is FALSE for hard-links,
	non-zero otherwise.

	Soft-links are resolved at access time by a combination of the
	filesystem (by returning ERROR_IS_SOFT_LINK to dos), and by
	Dos (using [ReadLink()](autodocs-3.5/dos-library-readlink-2.md) to resolve any links that are hit).

	Hard-links are resolved by the filesystem in question.  A series
	of hard-links to a file are all equivalent to the file itself.
	If one of the links (or the original entry for the file) is
	deleted, the data remains until there are no links left.

   INPUTS
	name - Name of the link to create
	dest - [CPTR](autodocs-3.5/include-exec-types-h.md) to path string, or [BPTR](autodocs-3.5/include-dos-dos-h.md) lock
	soft - FALSE for hard-links, non-zero for soft-links

   RESULT
	Success - boolean

   BUGS
	In V36, soft-links didn't work in the ROM filesystem.  This was
	fixed for V37.

   SEE ALSO
	[ReadLink()](autodocs-3.5/dos-library-readlink-2.md), [Open()](autodocs-3.5/dos-library-open-2.md), [Lock()](autodocs-3.5/dos-library-lock-2.md)

---

## See Also

- [Lock — dos.library](../autodocs/dos.library.md#lock)
- [Open — dos.library](../autodocs/dos.library.md#open)
