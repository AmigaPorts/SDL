# graphics.library/InitRastPort



   NAME
	InitRastPort -- Initialize raster port structure

   SYNOPSIS
   	InitRastPort( rp )
		      a1

	void InitRastPort(struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *rp);

   FUNCTION

```c
       Initialize a [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) structure to standard values.
```
   INPUTS
	rp	= pointer to a [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) structure.

   RESULT
	all entries in [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) get zeroed out, with the following exceptions:

	    Mask, FgPen, AOLPen, and LinePtrn are set to -1.
	    The DrawMode is set to JAM2
	    The font is set to the standard system font

   NOTES
	The struct Rastport describes a control structure
```c
       for a write-able raster. The [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) structure
       describes how a complete single playfield display
       will be written into. A [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) structure is
       referenced whenever any drawing or filling
       operations are to be performed on a section of
       memory.

       The section of memory which is being used in this
       way may or may not be presently a part of the
       current actual onscreen display memory. The name
       of the actual memory section which is linked to
       the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) is referred to here as a "raster" or
       as a bitmap.

       NOTE: Calling the routine InitRastPort only
       establishes various defaults. It does NOT
       establish where, in memory, the rasters are
       located. To do graphics with this [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) the user
```
	must set up the [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45) pointer in the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53).

   BUGS

   SEE ALSO
   	graphics/rastport.h

