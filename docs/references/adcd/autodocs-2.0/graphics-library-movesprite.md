---
title: graphics.library/MoveSprite
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-movesprite
functions: [ChangeSprite, FreeSprite, GetSprite]
libraries: [graphics.library]
---

# graphics.library/MoveSprite

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    MoveSprite -- Move sprite to a point relative to top of viewport.
SYNOPSIS

```c
    MoveSprite(vp, sprite, x, y)
               A0  A1      D0 D1

    void MoveSprite(struct [ViewPort](autodocs-2.0/includes-graphics-view-h.md) *,struct [SimpleSprite](autodocs-2.0/includes-graphics-sprite-h.md) *, WORD, WORD);
```
FUNCTION

    Move sprite image to new place on display.
INPUTS

```c
    vp - pointer to [ViewPort](autodocs-2.0/includes-graphics-view-h.md) structure
         if vp = 0, sprite is positioned relative to [View](autodocs-2.0/includes-graphics-view-h.md).
    sprite - pointer to [SimpleSprite](autodocs-2.0/includes-graphics-sprite-h.md) structure
    (x,y)  - new position relative to top of viewport or view.
```
RESULTS

    Calculate the hardware information for the sprite and
    place it in the posctldata array. During next video display
    the sprite will appear in new position.
BUGS

    Sprites really appear one pixel to the left of the position you
    specify.  This bug affects the apparent display position of the sprite
    on the screen, but does not affect the numeric position relative to
    the viewport or view.
SEE ALSO

```c
    [FreeSprite()](autodocs-2.0/graphics-library-freesprite.md)  [ChangeSprite()](autodocs-2.0/graphics-library-changesprite.md)  [GetSprite()](autodocs-2.0/graphics-library-getsprite.md)  [graphics/sprite.h](autodocs-2.0/includes-graphics-sprite-h.md)
```

---

## See Also

- [ChangeSprite — graphics.library](../autodocs/graphics.library.md#changesprite)
- [FreeSprite — graphics.library](../autodocs/graphics.library.md#freesprite)
- [GetSprite — graphics.library](../autodocs/graphics.library.md#getsprite)
