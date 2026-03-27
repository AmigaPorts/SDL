---
title: graphics.library/GetExtSpriteA
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-getextspritea
functions: [ChangeSprite, FreeSprite, GetSprite, MoveSprite]
libraries: [graphics.library]
---

# graphics.library/GetExtSpriteA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GetExtSpriteA -- Attempt to get a sprite for the extended sprite
					 manager. (V39)
	GetExtSprite -- varargs stub for GetExtSpriteA. (V39)

   SYNOPSIS
	Sprite_Number = GetExtSpriteA( sprite, tags )  (V39)
	    d0			        a2      a1

	[LONG](autodocs-3.5/include-exec-types-h.md) GetExtSpriteA( struct [ExtSprite](autodocs-3.5/include-graphics-sprite-h.md) *, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) * );

	spritenum=GetExtSprite(sprite,tags,...);

   FUNCTION
	Attempt to allocate one of the eight sprites for private use
	with the extended sprite manager.

   INPUTS
	sprite - ptr to programmer's [ExtSprite](autodocs-3.5/include-graphics-sprite-h.md) (from AllocSpriteData()).
	tags - a standard tag list:

		GSTAG_SPRITE_NUM	specifies a specific sprite to get by number.

		GSTAG_ATTACHED specifies that you wish to get a sprite pair.
			the tag data field points to a [ExtSprite](autodocs-3.5/include-graphics-sprite-h.md) structure
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
	[FreeSprite()](autodocs-3.5/graphics-library-freesprite-2.md) [ChangeSprite()](autodocs-3.5/graphics-library-changesprite-2.md) [MoveSprite()](autodocs-3.5/graphics-library-movesprite-2.md) [GetSprite()](autodocs-3.5/graphics-library-getsprite-2.md) [graphics/sprite.h](autodocs-3.5/include-graphics-sprite-h.md)

---

## See Also

- [ChangeSprite — graphics.library](../autodocs/graphics.library.md#changesprite)
- [FreeSprite — graphics.library](../autodocs/graphics.library.md#freesprite)
- [GetSprite — graphics.library](../autodocs/graphics.library.md#getsprite)
- [MoveSprite — graphics.library](../autodocs/graphics.library.md#movesprite)
