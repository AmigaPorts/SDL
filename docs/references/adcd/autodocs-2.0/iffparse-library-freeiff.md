---
title: iffparse.library/FreeIFF
manual: autodocs-2.0
chapter: autodocs-2.0
section: iffparse-library-freeiff
functions: [AllocIFF, CloseIFF]
libraries: [iffparse.library]
---

# iffparse.library/FreeIFF

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    FreeIFF -- Deallocate an [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) struct.
```
SYNOPSIS

```c
    FreeIFF (iff)
             a0

    struct [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) *iff;
```
FUNCTION

```c
    Deallocates all resources associated with this [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) struct.  The
    struct MUST have already been closed with [CloseIFF()](autodocs-2.0/iffparse-library-closeiff.md).
```
INPUTS

```c
    iff     - pointer to [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) struct to free.
```
RESULT

EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [AllocIFF()](autodocs-2.0/iffparse-library-allociff.md), [CloseIFF()](autodocs-2.0/iffparse-library-closeiff.md)
```

---

## See Also

- [AllocIFF — iffparse.library](../autodocs/iffparse.library.md#allociff)
- [CloseIFF — iffparse.library](../autodocs/iffparse.library.md#closeiff)
