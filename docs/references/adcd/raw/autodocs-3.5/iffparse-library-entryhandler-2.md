# iffparse.library/EntryHandler



   NAME
	EntryHandler -- add an entry handler to the [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) context. (V36)

   SYNOPSIS
	error = EntryHandler(iff, type, id, position, handler, object);
	D0                   A0   D0    D1  D2        A1       A2

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) EntryHandler(struct [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) *, [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39),
	                  struct [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) *, APTR);

   FUNCTION
	Installs an entry handler vector for a specific type of chunk into
	the context for the given [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) structure. Type and id are the
	longword identifiers for the chunk to handle. The handler is a client-
	supplied standard [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) structure, properly initialized. position
	tells where to put the handler in the context. The handler will be
	called whenever the parser enters a chunk of the given type, so the
	IFF stream will be positioned to read the first data byte in the
	chunk. The handler will execute in the same context as whoever
	called [ParseIFF()](../Includes_and_Autodocs_3._guide/node0372.html). The handler will be called (through the hook)
	with the following arguments:

		A0:	the [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) pointer you passed.
		A2:	the 'object' pointer you passed.
		A1:	pointer to a [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) containing the value
			IFFCMD_ENTRY.

	The error code your call-back routine returns will affect the parser
	in three different ways:

	Return value		Result
	------------		------
	0:			Normal success;  [ParseIFF()](../Includes_and_Autodocs_3._guide/node0372.html) will continue
				through the file.
	IFF_RETURN2CLIENT:	[ParseIFF()](../Includes_and_Autodocs_3._guide/node0372.html) will stop and return the value 0.
				(StopChunk() is internally implemented using
				this return value.)
	Any other value:	[ParseIFF()](../Includes_and_Autodocs_3._guide/node0372.html) will stop and return the value
				you supplied. This is how errors should be
				returned.

   INPUTS
	iff - pointer to [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) structure.
	type - type code for chunk to handle (ex. "ILBM").
	id - ID code for chunk to handle (ex. "CMAP").
	position- local context item position. One of the IFFSLI_#? codes.
	handler - pointer to [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) structure.
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
	[ExitHandler()](../Includes_and_Autodocs_3._guide/node0361.html), [StoreLocalItem()](../Includes_and_Autodocs_3._guide/node037E.html), [StoreItemInContext()](../Includes_and_Autodocs_3._guide/node037D.html),
	[<utility/hooks.h>](../Includes_and_Autodocs_3._guide/node0617.html), [<libraries/iffparse.h>](../Includes_and_Autodocs_3._guide/node05E8.html)

