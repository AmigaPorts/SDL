# graphics.library/AllocBitMap



   NAME
	AllocBitMap -- [Allocate](../Includes_and_Autodocs_3._guide/node01E5.html) a bitmap and attach bitplanes to it. (V39)


   SYNOPSIS
	bitmap=AllocBitMap(sizex,sizey,depth, flags, friend_bitmap)
	                   d0    d1    d2     d3       a0

	struct [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45) *AllocBitMap(ULONG,ULONG,ULONG,ULONG, struct [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45) *);

   FUNCTION
	Allocates and initializes a bitmap structure. Allocates and initializes
	bitplane data, and sets the bitmap's planes to point to it.

   INPUTS
	sizex = the width (in pixels) desired for the bitmap data.

	sizey = the height (in pixels) desired.

	depth = the number of bitplanes deep for the allocation.
		Pixels with AT LEAST this many bits will be allocated.

	flags = BMF_CLEAR to specify that the allocated raster should be
	        filled with color 0.

	        BMF_DISPLAYABLE to specify that this bitmap data should
	        be allocated in such a manner that it can be displayed.
	        Displayable data has more severe alignment restrictions
	        than non-displayable data in some systems.

	        BMF_INTERLEAVED tells graphics that you would like your
	        bitmap to be allocated with one large chunk of display
	        memory for all bitplanes. This minimizes color flashing
	        on deep displays. If there is not enough contiguous RAM
		for an interleaved bitmap, graphics.library will fall
		back to a non-interleaved one.

	        BMF_MINPLANES causes graphics to only allocate enough space
	        in the bitmap structure for "depth" plane pointers. This
		is for system use and should not be used by applications use
		as it is inefficient, and may waste memory.

	friend_bitmap = pointer to another bitmap, or NULL. If this pointer
	        is passed, then the bitmap data will be allocated in
	        the most efficient form for blitting to friend_bitmap.

   BUGS

   NOTES
	When allocating using a friend bitmap, it is not safe to assume
	anything about the structure of the bitmap data if that friend
	[BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45) might not be a standard amiga bitmap (for instance, if
	the workbench is running on a non-amiga display device, its
	Screen->RastPort->BitMap won't be in standard amiga format.
	The only safe operations to perform on a non-standard [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45) are:

	        - blitting it to another bitmap, which must be either a standard
	          Amiga bitmap, or a friend of this bitmap.

	        - blitting from this bitmap to a friend bitmap or to a standard
	          Amiga bitmap.

	        - attaching it to a rastport and making rendering calls.

	Good arguments to pass for the friend_bitmap are your window's
	RPort->BitMap, and your screen's RastPort->BitMap.
	Do NOT pass &(screenptr->BitMap)!

	BitMaps not allocated with BMF_DISPLAYABLE may not be used as
	Intuition [Custom](../Includes_and_Autodocs_3._guide/node05F6.html#line24) BitMaps or as RasInfo->BitMaps.  They may be blitted
	to a BMF_DISPLAYABLE [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45), using one of the [BltBitMap()](../Includes_and_Autodocs_3._guide/node02B2.html) family of
	functions.

   SEE ALSO
	[FreeBitMap()](../Includes_and_Autodocs_3._guide/node02D6.html)

