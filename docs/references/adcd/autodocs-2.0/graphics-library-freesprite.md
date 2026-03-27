---
title: graphics.library/FreeSprite
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-freesprite
functions: [ChangeSprite, GetSprite, MoveSprite]
libraries: [graphics.library]
---

# graphics.library/FreeSprite

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    FreeSprite -- Return sprite for use by others and virtual
                                      sprite machine.
SYNOPSIS

```c
    FreeSprite( pick )
                d0

    void FreeSprite( WORD );
```
FUNCTION

    Mark sprite as available for others to use.
    These sprite routines are provided to ease sharing of sprite
    hardware and to handle simple cases of sprite usage and
    movement.  It is assumed the programs that use these routines
    do want to be good citizens in their hearts. ie: they will
    not FreeSprite unless they actually own the sprite.
    The Virtual Sprite machine may ignore the simple sprite machine.
INPUTS

    pick - number in range of 0-7
RESULTS

```c
    sprite made available for subsequent callers of [GetSprite](autodocs-2.0/graphics-library-getsprite.md)
    as well as use by Virtual Sprite Machine.
```
BUGS

SEE ALSO

```c
    [GetSprite()](autodocs-2.0/graphics-library-getsprite.md) [ChangeSprite()](autodocs-2.0/graphics-library-changesprite.md) [MoveSprite()](autodocs-2.0/graphics-library-movesprite.md) [graphics/sprite.h](autodocs-2.0/includes-graphics-sprite-h.md)
```

---

## See Also

- [ChangeSprite — graphics.library](../autodocs/graphics.library.md#changesprite)
- [GetSprite — graphics.library](../autodocs/graphics.library.md#getsprite)
- [MoveSprite — graphics.library](../autodocs/graphics.library.md#movesprite)
