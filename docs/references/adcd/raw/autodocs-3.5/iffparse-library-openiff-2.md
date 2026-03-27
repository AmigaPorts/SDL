# iffparse.library/OpenIFF



   NAME
	OpenIFF -- prepare an [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) to read or write a new IFF stream.
	           (V36)

   SYNOPSIS
	error = OpenIFF(iff, rwMode);
	D0              A0   D0

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) OpenIFF(struct [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) *, LONG);

   FUNCTION
	Initializes an [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) structure for a new read or write. The
	direction of the I/O is given by the value of rwMode, which can be
	either IFFF_READ or IFFF_WRITE.

	As part of its initialization procedure, OpenIFF() calls the client-
	supplied stream hook vector. The [IFFStreamCmd](../Includes_and_Autodocs_3._guide/node05E8.html#line65) packet will contain
	the following:

		sc_Command:	IFFCMD_INIT
		sc_Buf:		(Not applicable)
		sc_NBytes:	(Not applicable)

	This operation is permitted to fail. DO NOT write to this structure.

   INPUTS
	iff - pointer to [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) structure. Starting with V39, this may be
	      NULL, in which case IFFERR_NOMEM is returned.
	rwMode - IFFF_READ or IFFF_WRITE

   RESULT
	error - contains an error code or 0 if successful

   SEE ALSO
	[CloseIFF()](../Includes_and_Autodocs_3._guide/node035C.html), [InitIFF()](../Includes_and_Autodocs_3._guide/node036B.html), [<libraries/iffparse.h>](../Includes_and_Autodocs_3._guide/node05E8.html)

