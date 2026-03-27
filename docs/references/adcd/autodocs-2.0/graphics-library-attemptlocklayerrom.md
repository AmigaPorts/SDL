---
title: graphics.library/AttemptLockLayerRom
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-attemptlocklayerrom
functions: [LockLayerRom, UnlockLayerRom]
libraries: [graphics.library]
---

# graphics.library/AttemptLockLayerRom

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

                       *
NAME

```c
    AttemptLockLayerRom -- Attempt to Lock [Layer](autodocs-2.0/includes-graphics-clip-h.md) structure
                                     by rom(gfx lib) code
```
SYNOPSIS

```c
    gotit = AttemptLockLayerRom( layer )
     d0                           a5

    BOOL AttempLockLayerRom( struct [Layer](autodocs-2.0/includes-graphics-clip-h.md) * );
```
FUNCTION

```c
    Query the current state of the lock on this [Layer](autodocs-2.0/includes-graphics-clip-h.md). If it is
    already locked then return FALSE, could not lock. If the
    [Layer](autodocs-2.0/includes-graphics-clip-h.md) was not locked then lock it and return TRUE.
    This call does not destroy any registers.
    This call nests so that callers in this chain will not lock
    themselves out.
```
INPUTS

```c
    layer - pointer to [Layer](autodocs-2.0/includes-graphics-clip-h.md) structure
```
RESULT

```c
    gotit - TRUE or FALSE depending on whether the [Layer](autodocs-2.0/includes-graphics-clip-h.md) was
            successfully locked by the caller.
```
SEE ALSO

```c
    [LockLayerRom()](autodocs-2.0/graphics-library-locklayerrom.md) [UnlockLayerRom()](autodocs-2.0/graphics-library-unlocklayerrom.md)
```

---

## See Also

- [LockLayerRom — graphics.library](../autodocs/graphics.library.md#locklayerrom)
- [UnlockLayerRom — graphics.library](../autodocs/graphics.library.md#unlocklayerrom)
