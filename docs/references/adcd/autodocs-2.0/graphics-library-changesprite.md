---
title: graphics.library/ChangeSprite
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-changesprite
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

    void ChangeSprite(struct [ViewPort](autodocs-2.0/includes-graphics-view-h.md) *, struct [SimpleSprite](autodocs-2.0/includes-graphics-sprite-h.md) *, void * )
```
FUNCTION

    The sprite image is changed to use the data starting at newdata
INPUTS

```c
    vp - pointer to [ViewPort](autodocs-2.0/includes-graphics-view-h.md) structure that this sprite is
              relative to,  or 0 if relative only top of [View](autodocs-2.0/includes-graphics-view-h.md)
    s - pointer to [SimpleSprite](autodocs-2.0/includes-graphics-sprite-h.md) structure
    newdata - pointer to data structure of the following form.
            struct spriteimage
            {
                UWORD    posctl[2]; /* used by simple sprite machine*/
                UWORD    data[height][2];   /* actual sprite image */
                UWORD    reserved[2];       /* initialized to */
                                                 /*  0x0,0x0 */
            };
    The programmer must initialize reserved[2].  Spriteimage must be
    in CHIP memory. The height subfield of the [SimpleSprite](autodocs-2.0/includes-graphics-sprite-h.md) structure
    must be set to reflect the height of the new spriteimage BEFORE
    calling ChangeSprite(). The programmer may allocate two sprites to
    handle a single attached sprite.  After [GetSprite()](autodocs-2.0/graphics-library-getsprite.md), ChangeSprite(),
    the programmer can set the SPRITE_ATTACHED bit in posctl[1] of the
    odd numbered sprite.
    If you need more than 8 sprites, look up VSprites in the
    graphics documentation.
```
RESULTS

BUGS

SEE ALSO

```c
    [FreeSprite()](autodocs-2.0/graphics-library-freesprite.md) ChangeSprite() [MoveSprite()](autodocs-2.0/graphics-library-movesprite.md) [AddVSprite()](autodocs-2.0/graphics-library-addvsprite.md) [graphics/sprite.h](autodocs-2.0/includes-graphics-sprite-h.md)
```

---

## See Also

- [AddVSprite — graphics.library](../autodocs/graphics.library.md#addvsprite)
- [ChangeSprite — graphics.library](../autodocs/graphics.library.md#changesprite)
- [FreeSprite — graphics.library](../autodocs/graphics.library.md#freesprite)
- [GetSprite — graphics.library](../autodocs/graphics.library.md#getsprite)
- [MoveSprite — graphics.library](../autodocs/graphics.library.md#movesprite)
