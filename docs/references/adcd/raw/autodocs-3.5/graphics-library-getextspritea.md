# graphics.library/GetExtSpriteA



   NAME
	GetExtSpriteA -- Attempt to get a sprite for the extended sprite
					 manager. (V39)
	GetExtSprite -- varargs stub for GetExtSpriteA. (V39)

   SYNOPSIS
	Sprite_Number = GetExtSpriteA( sprite, tags )  (V39)
	    d0			        a2      a1

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) GetExtSpriteA( struct [ExtSprite](../Includes_and_Autodocs_3._guide/node060B.html#line26) *, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) * );

	spritenum=GetExtSprite(sprite,tags,...);

   FUNCTION
	Attempt to allocate one of the eight sprites for private use
	with the extended sprite manager.

   INPUTS
	sprite - ptr to programmer's [ExtSprite](../Includes_and_Autodocs_3._guide/node060B.html#line26) (from AllocSpriteData()).
	tags - a standard tag list:

		GSTAG_SPRITE_NUM	specifies a specific sprite to get by number.

		GSTAG_ATTACHED specifies that you wish to get a sprite pair.
			the tag data field points to a [ExtSprite](../Includes_and_Autodocs_3._guide/node060B.html#line26) structure
			for the second sprite. You must free both sprites.


   RESULTS
	Sprite_number = a sprite number or -1 for an error.
		This call will fail if no sprites could be allocated, or
		if you try to allocate a sprite which would require
		a mode change when there are other sprites of incompatible
		modes in use.

   BUGS

	GSTAG_ATTACHED does not work in version 39. When running under V39,
	you should attach the second sprite with a separate GetExtSprite call.

   SEE ALSO
	[FreeSprite()](../Includes_and_Autodocs_3._guide/node02DD.html) [ChangeSprite()](../Includes_and_Autodocs_3._guide/node02BC.html) [MoveSprite()](../Includes_and_Autodocs_3._guide/node0302.html) [GetSprite()](../Includes_and_Autodocs_3._guide/node02EC.html) [graphics/sprite.h](../Includes_and_Autodocs_3._guide/node060B.html)

