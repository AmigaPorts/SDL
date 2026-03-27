---
title: graphics.library/FreeGBuffers
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-freegbuffers
functions: [GetGBuffers]
libraries: [graphics.library]
---

# graphics.library/FreeGBuffers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    FreeGBuffers -- Deallocate memory obtained by GetGBufers.
SYNOPSIS

```c
    FreeGBuffers(anOb, rp, db)
                 A0    A1  D0

    void FreeGBuffers(struct [AnimOb](autodocs-2.0/includes-graphics-gels-h.md) *, struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *, BOOL);
```
FUNCTION

```c
    For each sequence of each component of the [AnimOb](autodocs-2.0/includes-graphics-gels-h.md),
    deallocate memory for:
        SaveBuffer
        BorderLine
        CollMask and ImageShadow (point to same buffer)
        if db is set (user had used double-buffering) deallocate:
            [DBufPacket](autodocs-2.0/includes-graphics-gels-h.md)
            BufBuffer
```
INPUTS

```c
    anOb = pointer to the [AnimOb](autodocs-2.0/includes-graphics-gels-h.md) structure
    rp   = pointer to the current [RastPort](autodocs-2.0/includes-graphics-rastport-h.md)
    db   = double-buffer indicator (set TRUE for double-buffering)
```
RESULT

BUGS

SEE ALSO

```c
    [GetGBuffers()](autodocs-2.0/graphics-library-getgbuffers.md)  [graphics/gels.h](autodocs-2.0/includes-graphics-gels-h.md)  [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)
```

---

## See Also

- [GetGBuffers — graphics.library](../autodocs/graphics.library.md#getgbuffers)
