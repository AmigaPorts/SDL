---
title: 28 / / Simple Sprite Functions / Moving A Simple Sprite
manual: libraries
chapter: libraries
section: 28-simple-sprite-functions-moving-a-simple-sprite
functions: [MoveSprite]
libraries: [graphics.library]
---

# 28 / / Simple Sprite Functions / Moving A Simple Sprite

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[MoveSprite()](autodocs-2.0/graphics-library-movesprite.md) repositions a Simple Sprite.  After this function is called,
the Simple Sprite is moved to a new position relative to the upper left
corner of the [ViewPort](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md).  It is called as follows:


```c
    struct ViewPort     *vp;
    struct SimpleSprite *sprite;
    SHORT               x, y;

    MoveSprite(vp, sprite, x, y);
```
There are three inputs to [MoveSprite()](autodocs-2.0/graphics-library-movesprite.md).  Set the vp argument to the
address of the [ViewPort](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) with which this Simple Sprite interacts or 0 if
this Simple Sprite's position is relative only to the current [View](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md).  Set
sprite to the address of your [SimpleSprite](libraries/28-sprites-bobs-and-animation-using-simple-hardware-sprites.md) data structure.  The x and y
arguments sepcify a pixel position to which the Simple Sprite is to be
moved.

---

## See Also

- [MoveSprite — graphics.library](../autodocs/graphics.library.md#movesprite)
