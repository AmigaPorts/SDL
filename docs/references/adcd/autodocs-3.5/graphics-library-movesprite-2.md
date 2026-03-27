---
title: graphics.library/MoveSprite
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-movesprite-2
functions: [ChangeSprite, FreeSprite, GetSprite]
libraries: [graphics.library]
---

# graphics.library/MoveSprite

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	MoveSprite -- [Move](autodocs-3.5/graphics-library-move-2.md) sprite to a point relative to top of viewport.

   SYNOPSIS
	MoveSprite(vp, sprite, x, y)
	           A0  A1      D0 D1

	void MoveSprite(struct [ViewPort](autodocs-3.5/include-graphics-view-h.md) *,struct [SimpleSprite](autodocs-3.5/include-graphics-sprite-h.md) *, WORD, WORD);

   FUNCTION
	[Move](autodocs-3.5/graphics-library-move-2.md) sprite image to new place on display.

   INPUTS
	vp - pointer to [ViewPort](autodocs-3.5/include-graphics-view-h.md) structure
	     if vp = 0, sprite is positioned relative to [View](autodocs-3.5/include-graphics-view-h.md).
	sprite - pointer to [SimpleSprite](autodocs-3.5/include-graphics-sprite-h.md) structure
	(x,y)  - new position relative to top of viewport or view.

   RESULTS
	Calculate the hardware information for the sprite and
	place it in the posctldata array. During next video display
	the sprite will appear in new position.

   BUGS
	Sprites really appear one pixel to the left of the position you specify.
	This bug affects the apparent display position of the sprite on the
	screen,	but does not affect the numeric position relative to the
	viewport or view. This behaviour only applies to SimpleSprites,
	not to ExtSprites.


   SEE ALSO
	[FreeSprite()](autodocs-3.5/graphics-library-freesprite-2.md)  [ChangeSprite()](autodocs-3.5/graphics-library-changesprite-2.md)  [GetSprite()](autodocs-3.5/graphics-library-getsprite-2.md)  [graphics/sprite.h](autodocs-3.5/include-graphics-sprite-h.md)

---

## See Also

- [ChangeSprite — graphics.library](../autodocs/graphics.library.md#changesprite)
- [FreeSprite — graphics.library](../autodocs/graphics.library.md#freesprite)
- [GetSprite — graphics.library](../autodocs/graphics.library.md#getsprite)
