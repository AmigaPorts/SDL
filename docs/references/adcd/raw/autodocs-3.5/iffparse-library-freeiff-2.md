# iffparse.library/FreeIFF



   NAME
	FreeIFF -- deallocate an [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) structure. (V36)

   SYNOPSIS
	FreeIFF(iff);
	        A0

	VOID FreeIFF(struct [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) *);

   FUNCTION
	Deallocates all resources associated with this [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) structure.
	The structure MUST have already been closed with [CloseIFF()](../Includes_and_Autodocs_3._guide/node035C.html).

   INPUTS
	iff - pointer to [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) structure to free. Starting with V39,
	      this may be NULL.

   SEE ALSO
	[AllocIFF()](../Includes_and_Autodocs_3._guide/node0359.html), [CloseIFF()](../Includes_and_Autodocs_3._guide/node035C.html), [<libraries/iffparse.h>](../Includes_and_Autodocs_3._guide/node05E8.html)

