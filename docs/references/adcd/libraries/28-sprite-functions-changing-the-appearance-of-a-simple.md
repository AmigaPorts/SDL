---
title: 28 / / Sprite Functions / Changing The Appearance Of A Simple Sprite
manual: libraries
chapter: libraries
section: 28-sprite-functions-changing-the-appearance-of-a-simple
functions: [ChangeSprite]
libraries: [graphics.library]
---

# 28 / / Sprite Functions / Changing The Appearance Of A Simple Sprite

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [ChangeSprite()](autodocs-2.0/graphics-library-changesprite.md) function can be used to alter the appearance of a
Simple Sprite.  ChangeSprite() substitutes new image data for the data
currently used to display a Simple Sprite.  It is called by the following
sequence:


```c
    struct ViewPort     *vp;
    struct SimpleSprite *sprite;
    APTR                newdata;

    ChangeSprite(vp, sprite, newdata);
```
The vp input to this function is a pointer to the [ViewPort](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) for this Sprite
or 0 if this Sprite is relative only to the current [View](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md).  The sprite
argument is a pointer to a [SimpleSprite](libraries/28-sprites-bobs-and-animation-using-simple-hardware-sprites.md) data structure.  (You must
allocate an actual SimpleSprite structure for sprite to point to.)  Set
newdata to the address of an image data structure containing the new
image.  The data must reside in Chip ([MEMF_CHIP](libraries/20-memory-functions-memory-attributes.md)) memory.

The structure for the new sprite image data is shown below.  It is not a
system structure, so it will not be found in the system includes, but it
is described in the documentation for the [ChangeSprite()](autodocs-2.0/graphics-library-changesprite.md) call.


```c
    struct spriteimage
        {
        UWORD posctl[2];  /* position and control data for this Sprite */

        /* Two words per line of Sprite height, first of the two words
         *  contains the MSB for color selection, second word contains
         * LSB (colors 0,1,2,3 from allowable color register selection
         *  set). Color '0' for any Sprite pixel makes it transparent.
         */
        UWORD data[height][2];  /* actual Sprite image */

        UWORD reserved[2];  /* reserved, initialize to 0, 0 */
        };
```

---

## See Also

- [ChangeSprite — graphics.library](../autodocs/graphics.library.md#changesprite)
