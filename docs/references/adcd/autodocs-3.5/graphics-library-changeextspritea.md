---
title: graphics.library/ChangeExtSpriteA
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-changeextspritea
functions: [AllocSpriteDataA, ChangeSprite, FreeSprite, MoveSprite]
libraries: [graphics.library]
---

# graphics.library/ChangeExtSpriteA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

```c
       ChangeExtSpriteA -- Change the sprite image pointer. (V39)
```
   SYNOPSIS

```c
       ChangeExtSpriteA( vp, oldsprite, newsprite, tags)
                     	  a0  a1   	 a2	    a3
```
	success=ChangeExtSpriteA(struct [ViewPort](autodocs-3.5/include-graphics-view-h.md) *, struct [ExtSprite](autodocs-3.5/include-graphics-sprite-h.md) *,
			struct [ExtSprite](autodocs-3.5/include-graphics-sprite-h.md) *, struct TagList *);

	success=ChangeExtSprite(vp,old_sp,new_sp,tag,....);

   FUNCTION 
	Attempt to change which sprite is displayed for a given
	sprite engine.

   INPUTS
```c
       vp - pointer to [ViewPort](autodocs-3.5/include-graphics-view-h.md) structure that this sprite is
```
		  relative to,  or 0 if relative only top of [View](autodocs-3.5/include-graphics-view-h.md)
	oldsprite - pointer the old [ExtSprite](autodocs-3.5/include-graphics-sprite-h.md) structure
	newsprite - pointer to the new [ExtSprite](autodocs-3.5/include-graphics-sprite-h.md) structure.

   RESULTS 
 	success - 0 if there was an error.
   BUGS 

   SEE ALSO
	[FreeSprite()](autodocs-3.5/graphics-library-freesprite-2.md) [ChangeSprite()](autodocs-3.5/graphics-library-changesprite-2.md) [MoveSprite()](autodocs-3.5/graphics-library-movesprite-2.md) [AllocSpriteDataA()](autodocs-3.5/graphics-library-allocspritedataa.md)
	[graphics/sprite.h](autodocs-3.5/include-graphics-sprite-h.md)

---

## See Also

- [AllocSpriteDataA — graphics.library](../autodocs/graphics.library.md#allocspritedataa)
- [ChangeSprite — graphics.library](../autodocs/graphics.library.md#changesprite)
- [FreeSprite — graphics.library](../autodocs/graphics.library.md#freesprite)
- [MoveSprite — graphics.library](../autodocs/graphics.library.md#movesprite)
