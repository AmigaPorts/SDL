---
title: graphics.library/FreeSpriteData
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-freespritedata
functions: [AllocBitMap, ChangeSprite, FreeSprite, FreeSpriteData, MoveSprite]
libraries: [graphics.library]
---

# graphics.library/FreeSpriteData

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FreeSpriteData -- free sprite data allocated by AllocSpriteData() (V39)

   SYNOPSIS
	FreeSpriteData(extsp)
			a2

	void FreeSpriteData(struct [ExtSprite](autodocs-3.5/include-graphics-sprite-h.md) *);


   FUNCTION

   INPUTS
	extsp - The extended sprite structure to be freed. Passing NULL is a
	NO-OP.

   SEE ALSO
	FreeSpriteData() [FreeSprite()](autodocs-3.5/graphics-library-freesprite-2.md) [ChangeSprite()](autodocs-3.5/graphics-library-changesprite-2.md) [MoveSprite()](autodocs-3.5/graphics-library-movesprite-2.md) GetExtSprite()
	[AllocBitMap()](autodocs-3.5/graphics-library-allocbitmap.md) [graphics/sprite.h](autodocs-3.5/include-graphics-sprite-h.md)

---

## See Also

- [AllocBitMap — graphics.library](../autodocs/graphics.library.md#allocbitmap)
- [ChangeSprite — graphics.library](../autodocs/graphics.library.md#changesprite)
- [FreeSprite — graphics.library](../autodocs/graphics.library.md#freesprite)
- [FreeSpriteData — graphics.library](../autodocs/graphics.library.md#freespritedata)
- [MoveSprite — graphics.library](../autodocs/graphics.library.md#movesprite)
