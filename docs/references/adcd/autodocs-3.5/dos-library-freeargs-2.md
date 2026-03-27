---
title: dos.library/FreeArgs
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-freeargs-2
functions: [FindArg, ReadArgs]
libraries: [dos.library]
---

# dos.library/FreeArgs

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FreeArgs - Free allocated memory after [ReadArgs()](autodocs-3.5/dos-library-readargs-2.md) (V36)

   SYNOPSIS
	FreeArgs(rdargs)
	           D1

	void FreeArgs(struct [RDArgs](autodocs-3.5/include-dos-rdargs-h.md) *)

   FUNCTION
	Frees memory allocated to return arguments in from [ReadArgs()](autodocs-3.5/dos-library-readargs-2.md).  If
	[ReadArgs](autodocs-3.5/dos-library-readargs-2.md) allocated the [RDArgs](autodocs-3.5/include-dos-rdargs-h.md) structure it will be freed.  If NULL
	is passed in this function does nothing.

   INPUTS
	rdargs - structure returned from [ReadArgs()](autodocs-3.5/dos-library-readargs-2.md) or NULL.

   SEE ALSO
	[ReadArgs()](autodocs-3.5/dos-library-readargs-2.md), [ReadItem()](autodocs-3.5/dos-library-readitem-2.md), [FindArg()](autodocs-3.5/dos-library-findarg-2.md)

---

## See Also

- [FindArg — dos.library](../autodocs/dos.library.md#findarg)
- [ReadArgs — dos.library](../autodocs/dos.library.md#readargs)
