---
title: layers.library/NewLayerInfo
manual: autodocs-2.0
chapter: autodocs-2.0
section: layers-library-newlayerinfo
functions: [NewLayerInfo]
libraries: [layers.library]
---

# layers.library/NewLayerInfo

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    NewLayerInfo -- Allocate and Initialize full [Layer_Info](autodocs-2.0/includes-graphics-layers-h.md) structure.
```
SYNOPSIS

```c
    result = NewLayerInfo()
    d0

    struct [Layer_Info](autodocs-2.0/includes-graphics-layers-h.md) *NewLayerInfo( void );
```
FUNCTION

```c
    Allocate memory required for full [Layer_Info](autodocs-2.0/includes-graphics-layers-h.md) structure.
    Initialize [Layer_Info](autodocs-2.0/includes-graphics-layers-h.md) structure in preparation to use
    other layer operations on this list of layers.
    Make the [Layer_Info](autodocs-2.0/includes-graphics-layers-h.md) unlocked (open).
```
INPUTS

    None
RESULT

```c
    result- pointer to [Layer_Info](autodocs-2.0/includes-graphics-layers-h.md) structure if successful
            NULL if not enough memory
```
BUGS

SEE ALSO

```c
    [graphics/layers.h](autodocs-2.0/includes-graphics-layers-h.md)
```

---

## See Also

- [NewLayerInfo — layers.library](../autodocs/layers.library.md#newlayerinfo)
