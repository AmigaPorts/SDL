---
title: 11 Special Functions / Using Sprites in Intuition Windows and Screens
manual: libraries
chapter: libraries
section: 11-special-functions-using-sprites-in-intuition-windows-and
functions: [AllocMem, AllocRemember, CopyMem, DrawGList, MoveSprite]
libraries: [exec.library, graphics.library, intuition.library]
---

# 11 Special Functions / Using Sprites in Intuition Windows and Screens

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Sprite functionality has limitations under Intuition.  The hardware and
graphics library sprite systems manage sprites independently of the
Intuition display.  In particular:

  * Sprites cannot be attached to any particular screen.  Instead, they

    always appear in front of every screen.
  * When a screen is moved, the sprites do not automatically move with

```c
    it. The sprites move to their correct locations only when the
    appropriate function is called (either [DrawGList()](libraries/28-displaying-the-vsprites-drawing-the-graphics-elements.md) or [MoveSprite()](libraries/28-simple-sprite-functions-moving-a-simple-sprite.md)).
```
Hardware sprites are of limited use under the Intuition paradigm.  They
travel out of windows and out of screens, unlike all other Intuition
mechanisms (except the Intuition pointer, which is meant to be global).

Remember that sprite data must be in Chip memory to be accessible to the
custom chips.  This may be done with a compiler specific feature, such as
the __chip keyword of SAS/C.  Otherwise, Chip memory can be allocated with
the Exec [AllocMem()](libraries/20-exec-memory-allocation-memory-functions.md) function or the Intuition [AllocRemember()](libraries/11-easy-memory-allocation-and-deallocation-helps-you.md) function,
setting the memory requirement flag to [MEMF_CHIP](libraries/17-introduction-to-exec-dynamic-memory-allocation.md).  The sprite data may
then be copied to Chip memory using a function like [CopyMem()](libraries/20-using-memory-copy-functions-copying-system-memory.md) in the Exec
library.  See the chapter "[Graphics Sprites, Bobs and Animation](libraries/28-sprite-functions-changing-the-appearance-of-a-simple.md)" for more
information.

---

## See Also

- [AllocMem — exec.library](../autodocs/exec.library.md#allocmem)
- [AllocRemember — intuition.library](../autodocs/intuition.library.md#allocremember)
- [CopyMem — exec.library](../autodocs/exec.library.md#copymem)
- [DrawGList — graphics.library](../autodocs/graphics.library.md#drawglist)
- [MoveSprite — graphics.library](../autodocs/graphics.library.md#movesprite)
