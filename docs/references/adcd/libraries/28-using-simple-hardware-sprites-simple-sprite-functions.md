---
title: 28 / Using Simple (Hardware) Sprites / Simple Sprite Functions
manual: libraries
chapter: libraries
section: 28-using-simple-hardware-sprites-simple-sprite-functions
functions: [ChangeSprite, FreeSprite, GetSprite, MakeVPort, MoveSprite, OpenScreen]
libraries: [graphics.library, intuition.library]
---

# 28 / Using Simple (Hardware) Sprites / Simple Sprite Functions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

There are four basic functions that you use to to control Simple Sprites:


```c
       [GetSprite()](libraries/28-simple-sprite-functions-accessing-a-hardware-sprite.md)  Attempts to allocates a sprite for exclusive use
    [ChangeSprite()](libraries/28-sprite-functions-changing-the-appearance-of-a-simple.md)  Modifies a Simple Sprite's image data
      [MoveSprite()](libraries/28-simple-sprite-functions-moving-a-simple-sprite.md)  Changes a Simple Sprite's position
      [FreeSprite()](libraries/28-simple-sprite-functions-relinquishing-a-simple-sprite.md)  Relinquishes a sprite so it can be used by others
```
To use these Simple Sprite functions (or the VSprite functions) the SPRITE
flag must have been set in the [NewScreen](libraries/3-screen-data-structures-other-screen-data-structures.md) structure for [OpenScreen()](libraries/3-intuition-screens-custom-screen-functions.md). If
Intuition is not being used, this flag must be specified in the [View](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) and
[ViewPort](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) data structures before [MakeVPort()](libraries/27-forming-a-basic-display-creating-the-display-instructions.md) is called.

 [Accessing A Hardware Sprite](libraries/28-simple-sprite-functions-accessing-a-hardware-sprite.md) 
 [Changing The Appearance Of A Simple Sprite](libraries/28-sprite-functions-changing-the-appearance-of-a-simple.md) 
 [Moving A Simple Sprite](libraries/28-simple-sprite-functions-moving-a-simple-sprite.md) 
 [Relinquishing A Simple Sprite](libraries/28-simple-sprite-functions-relinquishing-a-simple-sprite.md) 
 [Controlling Sprite DMA](libraries/28-simple-sprite-functions-controlling-sprite-dma.md) 
 [Complete Simple Sprite Example](libraries/lib-examples-ssprite-c.md) 

---

## See Also

- [ChangeSprite — graphics.library](../autodocs/graphics.library.md#changesprite)
- [FreeSprite — graphics.library](../autodocs/graphics.library.md#freesprite)
- [GetSprite — graphics.library](../autodocs/graphics.library.md#getsprite)
- [MakeVPort — graphics.library](../autodocs/graphics.library.md#makevport)
- [MoveSprite — graphics.library](../autodocs/graphics.library.md#movesprite)
- [OpenScreen — intuition.library](../autodocs/intuition.library.md#openscreen)
