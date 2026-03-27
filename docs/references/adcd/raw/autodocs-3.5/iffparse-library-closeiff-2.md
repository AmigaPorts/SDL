# iffparse.library/CloseIFF



   NAME
	CloseIFF -- close an IFF context. (V36)

   SYNOPSIS
	CloseIFF(iff);
	         A0

	VOID CloseIFF(struct [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) *);

   FUNCTION
	Completes an IFF read or write operation by closing the IFF context
	established for this [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) structure. The [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) structure
	itself is left ready for re-use and a new context can be opened with
	[OpenIFF()](../Includes_and_Autodocs_3._guide/node0370.html). This function can be used for cleanup if a read or write
	fails partway through.

	As part of its cleanup operation, CloseIFF() calls the client-
	supplied stream hook vector. The [IFFStreamCmd](../Includes_and_Autodocs_3._guide/node05E8.html#line65) packet will be set
	as follows:

		sc_Command:	IFFCMD_CLEANUP
		sc_Buf:		(Not applicable)
		sc_NBytes:	(Not applicable)

	This operation is NOT permitted to fail;  any error code returned
	will be ignored (best to return 0, though). DO NOT write to this
	structure.

   INPUTS
	iff - pointer to [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) structure previously opened with
	      [OpenIFF()](../Includes_and_Autodocs_3._guide/node0370.html). Starting with V39, this may be NULL.

   SEE ALSO
	[OpenIFF()](../Includes_and_Autodocs_3._guide/node0370.html), [InitIFF()](../Includes_and_Autodocs_3._guide/node036B.html), [<libraries/iffparse.h>](../Includes_and_Autodocs_3._guide/node05E8.html)

