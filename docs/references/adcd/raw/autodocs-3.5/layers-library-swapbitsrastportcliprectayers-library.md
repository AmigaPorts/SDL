# layers.library/SwapBitsRastPortClipRectayers.library/SwapBitsRastPortClipRect



    NAME
	SwapBitsRastPortClipRect -- Swap bits between common bitmap
	                            and obscured [ClipRect](../Includes_and_Autodocs_3._guide/node05EA.html#line56)

    SYNOPSIS
	SwapBitsRastPortClipRect( rp, cr )
	                          a0  a1

	void SwapBitsRastPortClipRect( struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, struct [ClipRect](../Includes_and_Autodocs_3._guide/node05EA.html#line56) *);

    FUNCTION
	Support routine useful for those that need to do some
	operations not done by the layer library.  Allows programmer
	to swap the contents of a small [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45) with a subsection of
	the display. This is accomplished without using extra memory.
	The bits in the display [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) are exchanged with the
	bits in the ClipRect's [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45).

	Note: the [ClipRect](../Includes_and_Autodocs_3._guide/node05EA.html#line56) structures which the layer library allocates are
	actually a little bigger than those described in the [graphics/clip.h](../Includes_and_Autodocs_3._guide/node05EA.html)
	include file.  So be warned that it is not a good idea to have
	instances of cliprects in your code.

    INPUTS
	rp - pointer to rastport
	cr - pointer to cliprect to swap bits with

    NOTE
	Because the blit operation started by this function is done asynchronously,
	it is imperative that a [WaitBlit()](../Includes_and_Autodocs_3._guide/node0339.html) be performed before releasing or using
	the processor to modify any of the associated structures.

    BUGS

    SEE ALSO
	[graphics/clip.h](../Includes_and_Autodocs_3._guide/node05EA.html), [graphics/rastport.h](../Includes_and_Autodocs_3._guide/node05D7.html), [graphics/clip.h](../Includes_and_Autodocs_3._guide/node05EA.html)

