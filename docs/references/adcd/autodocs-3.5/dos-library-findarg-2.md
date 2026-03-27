---
title: dos.library/FindArg
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-findarg-2
functions: [FreeArgs, ReadArgs]
libraries: [dos.library]
---

# dos.library/FindArg

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FindArg - find a keyword in a template (V36)

   SYNOPSIS
	index = FindArg(template, keyword)
	D0                D1        D2

	[LONG](autodocs-3.5/include-exec-types-h.md) FindArg(STRPTR, STRPTR)

   FUNCTION
	Returns the argument number of the keyword, or -1 if it is not a
	keyword for the template.  Abbreviations are handled.

   INPUTS
	keyword  - keyword to search for in template
	template - template string to search

   RESULT
	index - number of entry in template, or -1 if not found

   BUGS
	In earlier published versions of the autodoc, keyword and template
	were backwards.

   SEE ALSO
	[ReadArgs()](autodocs-3.5/dos-library-readargs-2.md), [ReadItem()](autodocs-3.5/dos-library-readitem-2.md), [FreeArgs()](autodocs-3.5/dos-library-freeargs-2.md)

---

## See Also

- [FreeArgs — dos.library](../autodocs/dos.library.md#freeargs)
- [ReadArgs — dos.library](../autodocs/dos.library.md#readargs)
