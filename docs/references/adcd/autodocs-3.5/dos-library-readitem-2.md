---
title: dos.library/ReadItem
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-readitem-2
functions: [FGetC, FindArg, FreeArgs, Input, ReadArgs, UnGetC]
libraries: [dos.library]
---

# dos.library/ReadItem

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ReadItem - reads a single argument/name from command line (V36)

   SYNOPSIS
	value = ReadItem(buffer, maxchars, input)
	D0                D1        D2      D3

	[LONG](autodocs-3.5/include-exec-types-h.md) ReadItem(STRPTR, [LONG](autodocs-3.5/include-exec-types-h.md), struct [CSource](autodocs-3.5/include-dos-rdargs-h.md) *)

   FUNCTION
	Reads a "word" from either [Input()](autodocs-3.5/dos-library-input-2.md) (buffered), or via [CSource](autodocs-3.5/include-dos-rdargs-h.md), if it
	is non-NULL (see [<dos/rdargs.h>](autodocs-3.5/include-dos-rdargs-h.md) for more information).  Handles
	quoting and some '*' substitutions (*e and *n) inside quotes (only).
	See [dos/dos.h](autodocs-3.5/include-dos-dos-h.md) for a listing of values returned by ReadItem()
	(ITEM_XXXX).  A "word" is delimited by whitespace, quotes, '=', or
	an EOF.

	ReadItem always unreads the last thing read (UnGetC(fh,-1)) so the
	caller can find out what the terminator was.

   INPUTS
	buffer   - buffer to store word in.
	maxchars - size of the buffer
	input    - [CSource](autodocs-3.5/include-dos-rdargs-h.md) input or NULL (uses FGetC(Input()))

   RESULT
	value - See [<dos/dos.h>](autodocs-3.5/include-dos-dos-h.md) for return values.

   BUGS
	Doesn't actually unread the terminator.

   SEE ALSO
	[ReadArgs()](autodocs-3.5/dos-library-readargs-2.md), [FindArg()](autodocs-3.5/dos-library-findarg-2.md), [UnGetC()](autodocs-3.5/dos-library-ungetc-2.md), [FGetC()](autodocs-3.5/dos-library-fgetc-2.md), [Input()](autodocs-3.5/dos-library-input-2.md), [<dos/dos.h>](autodocs-3.5/include-dos-dos-h.md),
	[<dos/rdargs.h>](autodocs-3.5/include-dos-rdargs-h.md), [FreeArgs()](autodocs-3.5/dos-library-freeargs-2.md)

---

## See Also

- [FGetC — dos.library](../autodocs/dos.library.md#fgetc)
- [FindArg — dos.library](../autodocs/dos.library.md#findarg)
- [FreeArgs — dos.library](../autodocs/dos.library.md#freeargs)
- [Input — dos.library](../autodocs/dos.library.md#input)
- [ReadArgs — dos.library](../autodocs/dos.library.md#readargs)
- [UnGetC — dos.library](../autodocs/dos.library.md#ungetc)
