# iffparse.library/StopChunk



   NAME
	StopChunk -- declare a chunk which should cause [ParseIFF](../Includes_and_Autodocs_3._guide/node0372.html) to return.
	             (V36)

   SYNOPSIS
	error = StopChunk(iff, type, id);
	D0                A0   D0    D1

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) StopChunk(struct [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) *, [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), LONG);		 type;

   FUNCTION
	Installs an entry handler for the specified chunk which will cause
	the [ParseIFF()](../Includes_and_Autodocs_3._guide/node0372.html) function to return control to the caller when this
	chunk is encountered. This is only of value when [ParseIFF()](../Includes_and_Autodocs_3._guide/node0372.html) is
	called with the IFFPARSE_SCAN control code.

   INPUTS
	iff - pointer to [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) structure (need not be open).
	type - type code for chunk to declare (ex. "ILBM").
	id - identifier for chunk to declare (ex. "BODY").

   RESULT
	error - 0 if successful or an IFFERR_#? error code if unsuccessful.

   SEE ALSO
	[StopChunks()](../Includes_and_Autodocs_3._guide/node037B.html), [ParseIFF()](../Includes_and_Autodocs_3._guide/node0372.html), [<libraries/iffparse.h>](../Includes_and_Autodocs_3._guide/node05E8.html)

