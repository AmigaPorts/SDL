# graphics.library/FreeBitMap



   NAME
	FreeBitMap -- free a bitmap created by [AllocBitMap](../Includes_and_Autodocs_3._guide/node02A0.html) (V39)

   SYNOPSIS
	FreeBitMap(bm)
	           a0

	VOID FreeBitMap(struct [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45) *)

   FUNCTION
	Frees bitmap and all associated bitplanes

   INPUTS
	bm  =  A pointer to a [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45) structure. Passing a NULL-pointer
	       (meaning "do nothing") is OK.

   BUGS

   NOTES
	Be careful to insure that any rendering done to the bitmap has
	completed (by calling [WaitBlit()](../Includes_and_Autodocs_3._guide/node0339.html)) before you call this function.

   SEE ALSO
	[AllocBitMap()](../Includes_and_Autodocs_3._guide/node02A0.html)

