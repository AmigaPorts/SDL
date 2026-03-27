# iffparse.library/InitIFFasDOS



   NAME
	InitIFFasDOS -- initialize an [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) as a DOS stream. (V36)

   SYNOPSIS
	InitIFFasDOS(iff)
	             A0

	InitIFFasDOS(struct [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) *);

   FUNCTION
	The function initializes the given [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) to operate on DOS
	streams. The iff_Stream field will need to be initialized as a [BPTR](../Includes_and_Autodocs_3._guide/node05F8.html#line129)
	returned from the DOS function [Open()](../Includes_and_Autodocs_3._guide/node0196.html).

   INPUTS
	iff - pointer to [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) structure.

   SEE ALSO
	[InitIFF()](../Includes_and_Autodocs_3._guide/node036B.html)

