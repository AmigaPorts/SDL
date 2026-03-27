---
title: iffparse.library/ExitHandler
manual: autodocs-3.5
chapter: autodocs-3.5
section: iffparse-library-exithandler-2
functions: [EntryHandler, ParseIFF, StopChunk, StoreItemInContext, StoreLocalItem]
libraries: [iffparse.library]
---

# iffparse.library/ExitHandler

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ExitHandler -- add an exit handler to the [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) context. (V36)

   SYNOPSIS
	error = ExitHandler(iff, type, id, position, handler, object);
	D0                  A0   D0    D1  D2        A1       A2

	[LONG](autodocs-3.5/include-exec-types-h.md) ExitHandler(struct [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) *, [LONG](autodocs-3.5/include-exec-types-h.md), [LONG](autodocs-3.5/include-exec-types-h.md), [LONG](autodocs-3.5/include-exec-types-h.md),
	                 struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *, [APTR](autodocs-3.5/include-exec-types-h.md) object(;

   FUNCTION
	Installs an exit handler vector for a specific type of chunk into the
	context for the given [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) structure. Type and id are the longword
	identifiers for the chunk to handle. The handler is a client-supplied
	standard [Hook](autodocs-3.5/include-utility-hooks-h.md) structure, properly initialized. Position tells
	where to put the handler in the context. The handler will be called
	just before the parser exits the given chunk in the "pause" parse
	state. The IFF stream may not be positioned predictably within the
	chunk. The handler will execute in the same context as whoever
	called [ParseIFF()](autodocs-3.5/iffparse-library-parseiff-2.md). The handler will be called (through the hook)
	with the following arguments:

		A0:	the [Hook](autodocs-3.5/include-utility-hooks-h.md) pointer you passed.
		A2:	the 'object' pointer you passed.
		A1:	pointer to a [LONG](autodocs-3.5/include-exec-types-h.md) containing the value
			IFFCMD_EXIT.

	The error code your call-back routine returns will affect the parser
	in three different ways:

	Return value		Result
	------------		------
	0:			Normal success;  [ParseIFF()](autodocs-3.5/iffparse-library-parseiff-2.md) will continue
				through the file.
	IFF_RETURN2CLIENT:	[ParseIFF()](autodocs-3.5/iffparse-library-parseiff-2.md) will stop and return the value 0.
				(StopChunk() is internally implemented using
				this return value.)
	Any other value:	[ParseIFF()](autodocs-3.5/iffparse-library-parseiff-2.md) will stop and return the value
				you supplied. This is how errors should be
				returned.

   INPUTS
	iff - pointer to [IFFHandle](autodocs-3.5/include-libraries-iffparse-h.md) structure.
	type - type code for chunk to handle (ex. "ILBM").
	id - identifier code for chunk to handle (ex. "CMAP").
	position - local context item position. One of the IFFSLI_#? codes.
	handler - pointer to [Hook](autodocs-3.5/include-utility-hooks-h.md) structure.
	object - a client-defined pointer which is passed in A2 during call-
		 back.

   RESULT
	error - 0 if successful or an IFFERR_#? error code if unsuccessful.

   BUGS
	Returning the values IFFERR_EOF or IFFERR_EOC from the call-back
	routine *may* confuse the parser.

	There is no way to explicitly remove a handler once installed.
	However, by installing a do-nothing handler using IFFSLI_TOP,
	previous handlers will be overridden until the context expires.

   SEE ALSO
	[EntryHandler()](autodocs-3.5/iffparse-library-entryhandler-2.md), [StoreLocalItem()](autodocs-3.5/iffparse-library-storelocalitem-2.md), [StoreItemInContext()](autodocs-3.5/iffparse-library-storeitemincontext-2.md),
	[<utility/hooks.h>](autodocs-3.5/include-utility-hooks-h.md), [<libraries/iffparse.h>](autodocs-3.5/include-libraries-iffparse-h.md)

---

## See Also

- [EntryHandler — iffparse.library](../autodocs/iffparse.library.md#entryhandler)
- [ParseIFF — iffparse.library](../autodocs/iffparse.library.md#parseiff)
- [StopChunk — iffparse.library](../autodocs/iffparse.library.md#stopchunk)
- [StoreItemInContext — iffparse.library](../autodocs/iffparse.library.md#storeitemincontext)
- [StoreLocalItem — iffparse.library](../autodocs/iffparse.library.md#storelocalitem)
