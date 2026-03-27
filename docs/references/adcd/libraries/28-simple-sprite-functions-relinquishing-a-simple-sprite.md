---
title: 28 / / Simple Sprite Functions / Relinquishing A Simple Sprite
manual: libraries
chapter: libraries
section: 28-simple-sprite-functions-relinquishing-a-simple-sprite
functions: [FreeSprite, GetSprite]
libraries: [graphics.library]
---

# 28 / / Simple Sprite Functions / Relinquishing A Simple Sprite

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [FreeSprite()](autodocs-2.0/graphics-library-freesprite.md) function returns a hardware sprite allocated with
[GetSprite()](libraries/28-using-simple-hardware-sprites-simple-sprite-functions.md) to the system so that GELs or other tasks can use it.  After
you call FreeSprite(), the GELs system can use it to allocate VSprites.
The syntax of this function is:


```c
    WORD sprite_number;

    FreeSprite(sprite_number);
```
The sprite_number argument is the number (0-7) of the sprite to be
returned to the system.

---

## See Also

- [FreeSprite — graphics.library](../autodocs/graphics.library.md#freesprite)
- [GetSprite — graphics.library](../autodocs/graphics.library.md#getsprite)
