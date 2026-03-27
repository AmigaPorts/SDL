# graphics.library/InitTmpRas



   NAME
	InitTmpRas -- Initialize area of local memory for usage by
			areafill, floodfill, text.

   SYNOPSIS
   	InitTmpRas(tmpras, buffer, size)

              	    a0	     a1     d0
	void InitTmpRas( struct [TmpRas](../Includes_and_Autodocs_3._guide/node05D7.html#line31) *, void *, ULONG );

   FUNCTION
	The area of memory pointed to by buffer is set up to be used
	by [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) routines that may need to get some memory for
	intermediate operations in preparation to putting the graphics
	into the final [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45).
	Tmpras is used to control the usage of buffer.

   INPUTS
	tmpras - pointer to a [TmpRas](../Includes_and_Autodocs_3._guide/node05D7.html#line31) structure to be linked into
		a [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53)
	buffer - pointer to a contiguous piece of chip memory.
	size - size in bytes of buffer

   RESULT
	makes buffer available for users of [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53)

   BUGS
	Would be nice if RastPorts could share one [TmpRas](../Includes_and_Autodocs_3._guide/node05D7.html#line31).

   SEE ALSO
	[AreaEnd()](../Includes_and_Autodocs_3._guide/node02AA.html) [Flood()](../Includes_and_Autodocs_3._guide/node02D4.html) [Text()](../Includes_and_Autodocs_3._guide/node0332.html) [graphics/rastport.h](../Includes_and_Autodocs_3._guide/node05D7.html)

