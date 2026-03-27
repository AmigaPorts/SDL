---
title: layers.library/UnlockLayer
manual: autodocs-2.0
chapter: autodocs-2.0
section: layers-library-unlocklayer
functions: [UnlockLayer]
libraries: [layers.library]
---

# layers.library/UnlockLayer

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    UnlockLayer -- Unlock layer and allow graphics routines to use it.
SYNOPSIS

```c
    UnlockLayer( l )
                 a0

    void UnlockLayer( struct [Layer](autodocs-2.0/includes-graphics-clip-h.md) *);
```
FUNCTION

```c
    When finished changing the ClipRects or whatever you were
    doing with this layer you must call UnlockLayer() to allow
    other tasks to proceed with graphic output to the layer.
```
INPUTS

    l - pointer to a layer
BUGS

SEE ALSO

```c
    [graphics/layers.h](autodocs-2.0/includes-graphics-layers-h.md), [graphics/clip.h](autodocs-2.0/includes-graphics-clip-h.md)
```

---

## See Also

- [UnlockLayer — layers.library](../autodocs/layers.library.md#unlocklayer)
