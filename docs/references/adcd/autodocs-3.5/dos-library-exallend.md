---
title: dos.library/ExAllEnd
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-exallend
functions: [AllocDosObject]
libraries: [dos.library]
---

# dos.library/ExAllEnd

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ExAllEnd -- Stop an [ExAll()](autodocs-3.5/dos-library-exall-2.md) (V39)

   SYNOPSIS
	ExAllEnd(lock, buffer, size, type, control)
	          D1     D2     D3    D4     D5

	ExAllEnd(BPTR,[STRPTR](autodocs-3.5/include-exec-types-h.md),[LONG](autodocs-3.5/include-exec-types-h.md),[LONG](autodocs-3.5/include-exec-types-h.md),struct [ExAllControl](autodocs-3.5/include-dos-exall-h.md) *)

   FUNCTION
	Stops an [ExAll()](autodocs-3.5/dos-library-exall-2.md) on a directory before it hits NO_MORE_ENTRIES.
	The full set of arguments that had been passed to [ExAll()](autodocs-3.5/dos-library-exall-2.md) must be
	passed to ExAllEnd(), so it can handle filesystems that can't abort
	an [ExAll()](autodocs-3.5/dos-library-exall-2.md) directly.

   INPUTS
	lock    - [Lock](autodocs-3.5/dos-library-lock-2.md) on directory to be examined.
	buffer  - Buffer for data returned (MUST be at least word-aligned,
		  preferably long-word aligned).
	size    - Size in bytes of 'buffer'.
	type    - Type of data to be returned.
	control - Control data structure (see notes above).  MUST have been
		  allocated by AllocDosObject!

   SEE ALSO
	[ExAll()](autodocs-3.5/dos-library-exall-2.md), [AllocDosObject()](autodocs-3.5/dos-library-allocdosobject-2.md)

---

## See Also

- [AllocDosObject — dos.library](../autodocs/dos.library.md#allocdosobject)
