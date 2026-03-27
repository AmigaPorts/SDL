---
title: graphics.library/NewRegion
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-newregion
functions: [NewRegion]
libraries: [graphics.library]
---

# graphics.library/NewRegion

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    NewRegion -- Get an empty region.
SYNOPSIS

```c
    region = NewRegion()
      d0

    struct [Region](autodocs-2.0/includes-graphics-regions-h.md) *NewRegion();
```
FUNCTION

```c
    Create a [Region](autodocs-2.0/includes-graphics-regions-h.md) structure, initialize it to empty, and return
    a pointer it.
```
RESULTS

```c
    region - pointer to initialized region. If it could not allocate
            required memory region = NULL.
```
INPUTS

    none
BUGS

SEE ALSO

```c
    [graphics/regions.h](autodocs-2.0/includes-graphics-regions-h.md)
```

---

## See Also

- [NewRegion — graphics.library](../autodocs/graphics.library.md#newregion)
