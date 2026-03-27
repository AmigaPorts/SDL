---
title: 28 / / / Parameters To Your Inter-GEL Collision Routines
manual: libraries
chapter: libraries
section: 28-parameters-to-your-inter-gel-collision-routines
functions: [DoCollision]
libraries: [graphics.library]
---

# 28 / / / Parameters To Your Inter-GEL Collision Routines

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

If, instead of a GEL-to-boundary collision, [DoCollision()](libraries/28-graphics-sprites-bobs-and-animation-function-reference.md) senses a
GEL-to-GEL collision, the system calls your collision routine with the
following two arguments:

  * Address of the VSprite that is the uppermost (or leftmost if y

```c
    coordinates are identical) GEL of a colliding pair.
```
  * Address of the VSprite that is the lowermost (or rightmost if y

```c
    coordinates are identical) GEL of the pair.
```

---

## See Also

- [DoCollision — graphics.library](../autodocs/graphics.library.md#docollision)
