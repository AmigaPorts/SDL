---
title: iffparse.library/AllocIFF
manual: autodocs-2.0
chapter: autodocs-2.0
section: iffparse-library-allociff
functions: [FreeIFF]
libraries: [iffparse.library]
---

# iffparse.library/AllocIFF

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    AllocIFF -- Create a new [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) structure.
```
SYNOPSIS

```c
    iff = AllocIFF ()
    d0

    struct [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) *iff;
```
FUNCTION

```c
    Allocates a new [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) structure and initializes the basic values.
    This function is the only supported way to create an [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md)
    structure since there are private fields that need to be initialized.
```
INPUTS

RESULT

```c
    iff     - pointer to [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) structure or NULL if the allocation
              failed.
```
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [FreeIFF()](autodocs-2.0/iffparse-library-freeiff.md)
```

---

## See Also

- [FreeIFF — iffparse.library](../autodocs/iffparse.library.md#freeiff)
