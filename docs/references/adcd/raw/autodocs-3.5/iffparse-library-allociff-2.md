# iffparse.library/AllocIFF



   NAME
	AllocIFF -- create a new [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) structure. (V36)

   SYNOPSIS
	iff = AllocIFF()
	D0

	struct [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) *AllocIFF(VOID);

   FUNCTION
	Allocates and initializes a new [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) structure.
	This function is the only supported way to create an [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43)
	structure since there are private fields that need to be initialized.

   RESULT
	iff - pointer to [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) structure or NULL if the allocation failed.

   SEE ALSO
	[FreeIFF()](../Includes_and_Autodocs_3._guide/node0366.html), [<libraries/iffparse.h>](../Includes_and_Autodocs_3._guide/node05E8.html)

