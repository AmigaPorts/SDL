# graphics.library/AllocSpriteDataA



   NAME
	AllocSpriteDataA -- allocate sprite data and convert from a bitmap. (V39)
	AllocSpriteData -- varargs stub for AllocSpriteData(). (V39)

   SYNOPSIS
	SpritePtr | 0 = AllocSpriteDataA(bitmap,taglist)
	 d0	 	                 a2      a1

	struct [ExtSprite](../Includes_and_Autodocs_3._guide/node060B.html#line26) *AllocSpriteDataA( struct [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45) *, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) * );

	extsprite=AllocSpriteData(bitmap,tags,...TAG_END)

    FUNCTION
	[Allocate](../Includes_and_Autodocs_3._guide/node01E5.html) memory to hold a sprite image, and convert the passed-in
	bitmap data to the appropriate format. The tags allow specification
	of width, scaling, and other options.

   INPUTS
	bitmap - ptr to a bitmap. This bitmap provides the source data for the
		sprite image.

	tags -
		SPRITEA_Width specifies how many pixels wide you desire
		the sprite to be. Specifying a width wider than the hardware
		can handle will cause the function to return failure. If the
		bitmap passed in is narrower than the width asked for, then
		it will be padded on the right with transparent pixels.
		Defaults to 16.

		SPRITEA_XReplication controls the horizontal pixel replication factor
		used when converting the bitmap data. Valid values are:
			0 - perform a 1 to 1 conversion
			1 - each pixel from the source is replicated twice
			    in the output.
			2 - each pixel is replicated 4 times.
		       -1 - skip every other pixel in the source bitmap
		       -2 - only include every fourth pixel from the source.

			This tag is useful for converting data from one resolution
		to another. For instance, hi-res bitmap data can be correctly
		converted for a lo-res sprite by using an x replication factor
		of -1. Defaults to 0.

		SPRITEA_YReplication controls the vertical pixel replication factor
		in the same manner as SPRITEA_XReplication controls the horizontal.

		SPRITEA_OutputHeight specifies how tall the resulting sprite
		should be. Defaults to the bitmap height. The bitmap MUST be at
		least as tall as the output height.

		SPRITEA_Attached tells the function that you wish to convert
		the data for the second sprite in an attached sprite pair.
		This will cause AllocSpriteData() to take its data from the
		3rd and 4th bitplanes of the passed in bitmap.


	Bitplane data is not required to be in chip ram for this function.


   RESULTS
	SpritePtr = a pointer to a [ExtSprite](../Includes_and_Autodocs_3._guide/node060B.html#line26) structure, or 0 if there is
	a failure. You should pass this pointer to [FreeSpriteData()](../Includes_and_Autodocs_3._guide/node02DE.html) when finished
	with the sprite.

   BUGS
		Under V39, the appropriate attach bits would not be set in the sprite
	data.
		The work-around is to set the bits manually. Bit 7 of the second
	word should be set. On a 32 bit sprite, bit 7 of the 3rd word should
	also be set. For a 64 bit sprite, bit 7 of the 5th word should also be
	set. This should NOT be done under V40, as the bug is fixed.

   SEE ALSO
	[FreeSpriteData()](../Includes_and_Autodocs_3._guide/node02DE.html) [FreeSprite()](../Includes_and_Autodocs_3._guide/node02DD.html) [ChangeSprite()](../Includes_and_Autodocs_3._guide/node02BC.html) [MoveSprite()](../Includes_and_Autodocs_3._guide/node0302.html) [GetExtSpriteA()](../Includes_and_Autodocs_3._guide/node02E6.html)
	[AllocBitMap()](../Includes_and_Autodocs_3._guide/node02A0.html) [graphics/sprite.h](../Includes_and_Autodocs_3._guide/node060B.html)

