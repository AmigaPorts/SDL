---
title: 10 / The Pointer / Custom Pointer
manual: libraries
chapter: libraries
section: 10-the-pointer-custom-pointer
functions: [ClearPointer, SetPointer]
libraries: [intuition.library]
---

# 10 / The Pointer / Custom Pointer

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

An application can set a custom pointer for a window to replace the
default pointer. This custom pointer will be displayed whenever the window
is the active one.

To place a custom pointer in a window, call [SetPointer()](autodocs-2.0/intuition-library-setpointer.md).


```c
    void SetPointer( struct Window *window, UWORD *pointer, long height,
                     long width, long xOffset, long yOffset );
```
Set the window argument to the address of the window that is to receive
this custom pointer definition.  The pointer argument is the address of
the data that defines the custom pointer image. The format of this data is
discussed in the next section, "[The Sprite Data Structure](libraries/10-custom-pointer-the-sprite-data-structure.md)".

The height and width specify the dimensions of the pointer sprite.  There
is no height restriction but the width of the sprite must be less than or
equal to 16.

The xOffset and yOffset are used to offset the top left corner of the
hardware sprite imagery from what Intuition regards as the current
position of the pointer.  Another way of describing this is the offset of
the default Intuition pointer hot spot from the top left corner of the
sprite.

For instance, by specifying offsets of (0,0), the top left corner of the
sprite image will be placed at the pointer position.  On the other hand,
specifying an xOffset of -7 (remember, sprites are 16 pixels wide) will
center the sprite over the pointer position.  Specifying an xOffset of -15
will place the right edge of the sprite will be over the pointer position.


    Specifying the Hot Spot.
    ------------------------
    For compatibility, the application must specify that the "hot
    spot" of the pointer is one pixel to the left of the desired
    position. Changes to the pointer done by a program must compensate
    for this. The Preferences Pointer editor correctly handles this
    situation.
To remove the custom pointer from the window, call [ClearPointer()](autodocs-2.0/intuition-library-clearpointer.md).


```c
    void ClearPointer( struct Window *window );
```
Set the window argument to the address of the window that is to have its
custom pointer definition cleared.  The pointer will be restored to the
default Intuition pointer imagery

[SetPointer()](autodocs-2.0/intuition-library-setpointer.md) and [ClearPointer()](autodocs-2.0/intuition-library-clearpointer.md) take effect immediately if the window is
active, otherwise, the change will only be displayed when the window is
made active.

 [The Sprite Data Structure](libraries/10-custom-pointer-the-sprite-data-structure.md) 

---

## See Also

- [ClearPointer — intuition.library](../autodocs/intuition.library.md#clearpointer)
- [SetPointer — intuition.library](../autodocs/intuition.library.md#setpointer)
