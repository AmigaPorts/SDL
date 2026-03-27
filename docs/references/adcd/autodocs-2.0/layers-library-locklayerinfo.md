---
title: layers.library/LockLayerInfo
manual: autodocs-2.0
chapter: autodocs-2.0
section: layers-library-locklayerinfo
functions: [LockLayerInfo, UnlockLayerInfo]
libraries: [layers.library]
---

# layers.library/LockLayerInfo

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    LockLayerInfo -- Lock the LayerInfo structure.
SYNOPSIS

```c
    LockLayerInfo( li )
                   a0

    void LockLayerInfo( struct [Layer_Info](autodocs-2.0/includes-graphics-layers-h.md) *);
```
FUNCTION

```c
    Before doing an operation that requires the LayerInfo
    structure, make sure that no other task is also using the
    LayerInfo structure.  LockLayerInfo() returns when the
    LayerInfo belongs to this task.  There should be
    an [UnlockLayerInfo](autodocs-2.0/layers-library-unlocklayerinfo.md) for every LockLayerInfo.

    Note: All layer routines presently LockLayerInfo() when they
    start up and [UnlockLayerInfo()](autodocs-2.0/layers-library-unlocklayerinfo.md) as they exit.  Programmers
    will need to use these Lock/Unlock routines if they wish
    to do something with the LayerStructure that is not
    supported by the layer library.
```
INPUTS

```c
    li - pointer to [Layer_Info](autodocs-2.0/includes-graphics-layers-h.md) structure
```
BUGS

SEE ALSO

```c
    [UnlockLayerInfo](autodocs-2.0/layers-library-unlocklayerinfo.md), [graphics/layers.h](autodocs-2.0/includes-graphics-layers-h.md)
```

---

## See Also

- [LockLayerInfo — layers.library](../autodocs/layers.library.md#locklayerinfo)
- [UnlockLayerInfo — layers.library](../autodocs/layers.library.md#unlocklayerinfo)
