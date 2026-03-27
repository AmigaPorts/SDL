---
title: graphics.library/GetGBuffers
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-getgbuffers
functions: [FreeGBuffers]
libraries: [graphics.library]
---

# graphics.library/GetGBuffers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    GetGBuffers -- Attempt to allocate ALL buffers of an entire [AnimOb](autodocs-2.0/includes-graphics-gels-h.md).
```
SYNOPSIS

```c
    status = GetGBuffers(anOb, rp, db)
    D0                   A0    A1  D0

    BOOL GetGBuffers(struct [AnimOb](autodocs-2.0/includes-graphics-gels-h.md) *, struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *, BOOL);
```
FUNCTION

```c
    For each sequence of each component of the [AnimOb](autodocs-2.0/includes-graphics-gels-h.md), allocate memory for:
        SaveBuffer
        BorderLine
        CollMask and ImageShadow (point to same buffer)
        if db is set TRUE (user wants double-buffering) allocate:
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

```c
    status = TRUE if the memory allocations were all successful, else FALSE
```
BUGS

    If any of the memory allocations fail it does not free the partial
    allocations that did succeed.
SEE ALSO

```c
    [FreeGBuffers()](autodocs-2.0/graphics-library-freegbuffers.md) [graphics/gels.h](autodocs-2.0/includes-graphics-gels-h.md)
```

---

## See Also

- [FreeGBuffers — graphics.library](../autodocs/graphics.library.md#freegbuffers)
