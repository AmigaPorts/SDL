---
title: graphics.library/ChangeSprite
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-changesprite-2
functions: [AddVSprite, ChangeSprite, FreeSprite, GetSprite, MoveSprite]
libraries: [graphics.library]
---

# graphics.library/ChangeSprite

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       ChangeSprite -- Change the sprite image pointer.
   SYNOPSIS

```c
       ChangeSprite( vp, s, newdata)
                     a0  a1   a2
```
	void ChangeSprite(struct [ViewPort](autodocs-3.5/include-graphics-view-h.md) *, struct [SimpleSprite](autodocs-3.5/include-graphics-sprite-h.md) *, void * )

   FUNCTION 
	The sprite image is changed to use the data starting at newdata

   INPUTS
```c
       vp - pointer to [ViewPort](autodocs-3.5/include-graphics-view-h.md) structure that this sprite is
```
		  relative to,  or 0 if relative only top of [View](autodocs-3.5/include-graphics-view-h.md)
	s - pointer to [SimpleSprite](autodocs-3.5/include-graphics-sprite-h.md) structure
	newdata	- pointer to data structure of the following form.
		struct spriteimage
		{
		    [UWORD](autodocs-3.5/include-exec-types-h.md)    posctl[2];	/* used by simple sprite machine*/
		    [UWORD](autodocs-3.5/include-exec-types-h.md)    data[height][2];   /* actual sprite image */
		    [UWORD](autodocs-3.5/include-exec-types-h.md)    reserved[2];	/* initialized to */
			                             /*  0x0,0x0 */
		};
	The programmer must initialize reserved[2].  Spriteimage must be
	in CHIP memory. The height subfield of the [SimpleSprite](autodocs-3.5/include-graphics-sprite-h.md) structure
	must be set to reflect the height of the new spriteimage BEFORE
	calling ChangeSprite(). The programmer may allocate two sprites to
	handle a single attached sprite.  After [GetSprite()](autodocs-3.5/graphics-library-getsprite-2.md), ChangeSprite(),
	the programmer can set the SPRITE_ATTACHED bit in posctl[1] of the
	odd numbered sprite.
	If you need more than 8 sprites, look up VSprites in the
	graphics documentation.

   RESULTS 

   BUGS 

   SEE ALSO
	[FreeSprite()](autodocs-3.5/graphics-library-freesprite-2.md) ChangeSprite() [MoveSprite()](autodocs-3.5/graphics-library-movesprite-2.md) [AddVSprite()](autodocs-3.5/graphics-library-addvsprite-2.md) [graphics/sprite.h](autodocs-3.5/include-graphics-sprite-h.md)

---

## See Also

- [AddVSprite — graphics.library](../autodocs/graphics.library.md#addvsprite)
- [ChangeSprite — graphics.library](../autodocs/graphics.library.md#changesprite)
- [FreeSprite — graphics.library](../autodocs/graphics.library.md#freesprite)
- [GetSprite — graphics.library](../autodocs/graphics.library.md#getsprite)
- [MoveSprite — graphics.library](../autodocs/graphics.library.md#movesprite)
