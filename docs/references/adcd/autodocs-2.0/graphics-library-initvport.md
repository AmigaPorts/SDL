---
title: graphics.library/InitVPort
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-initvport
functions: [MakeVPort]
libraries: [graphics.library]
---

# graphics.library/InitVPort

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    InitVPort - Initialize [ViewPort](autodocs-2.0/includes-graphics-view-h.md) structure.
```
SYNOPSIS

```c
    InitVPort( vp )
               a0

    void InitVPort( struct [ViewPort](autodocs-2.0/includes-graphics-view-h.md) * );
```
FUNCTION

```c
    Initialize [ViewPort](autodocs-2.0/includes-graphics-view-h.md) structure to default values.
```
INPUTS

```c
    vp - pointer to a [ViewPort](autodocs-2.0/includes-graphics-view-h.md) structure
```
RESULT

```c
    [ViewPort](autodocs-2.0/includes-graphics-view-h.md) structure set to all 0's. (1.0,1.1)
    New field added SpritePriorities, initialized to 0x24 (1.2)
```
BUGS

SEE ALSO

```c
    [MakeVPort()](autodocs-2.0/graphics-library-makevport.md) [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md)
```

---

## See Also

- [MakeVPort — graphics.library](../autodocs/graphics.library.md#makevport)
