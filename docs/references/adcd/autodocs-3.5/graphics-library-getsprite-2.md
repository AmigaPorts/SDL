---
title: graphics.library/GetSprite
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-getsprite-2
functions: [ChangeSprite, FreeSprite, GetSprite, MoveSprite]
libraries: [graphics.library]
---

# graphics.library/GetSprite

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GetSprite -- Attempt to get a sprite for the simple sprite manager.

   SYNOPSIS
	Sprite_Number = GetSprite( sprite, pick )
	    d0			    a0      d0

	WORD GetSprite( struct [SimpleSprite](autodocs-3.5/include-graphics-sprite-h.md) *, WORD );

   FUNCTION
	Attempt to allocate one of the eight sprites for private use
	with the simple sprite manager. This must be done before using
	further calls to the simple sprite machine. If the programmer
	wants to use 15 color sprites, they must allocate both sprites
	and set the 'SPRITE_ATTACHED' bit in the odd sprite's posctldata
	array.

   INPUTS
	sprite - ptr to programmers [SimpleSprite](autodocs-3.5/include-graphics-sprite-h.md) structure.
	pick - number in the range of 0-7 or
	  -1 if programmer just wants the next one.

   RESULTS
	If pick is 0-7 attempt to allocate the sprite. If the sprite
	is already allocated then return -1.
	If pick -1 allocate the next sprite starting search at 0.
	If no sprites are available return -1 and fill -1 in num entry
	of [SimpleSprite](autodocs-3.5/include-graphics-sprite-h.md) structure.
	If the sprite is available for allocation, mark it allocated
	and fill in the 'num' entry of the [SimpleSprite](autodocs-3.5/include-graphics-sprite-h.md) structure.
	If successful return the sprite number.

   BUGS

   SEE ALSO
	[FreeSprite()](autodocs-3.5/graphics-library-freesprite-2.md) [ChangeSprite()](autodocs-3.5/graphics-library-changesprite-2.md) [MoveSprite()](autodocs-3.5/graphics-library-movesprite-2.md) GetSprite() [graphics/sprite.h](autodocs-3.5/include-graphics-sprite-h.md)

---

## See Also

- [ChangeSprite — graphics.library](../autodocs/graphics.library.md#changesprite)
- [FreeSprite — graphics.library](../autodocs/graphics.library.md#freesprite)
- [GetSprite — graphics.library](../autodocs/graphics.library.md#getsprite)
- [MoveSprite — graphics.library](../autodocs/graphics.library.md#movesprite)
