---
title: iffparse.library/StopOnExit
manual: autodocs-2.0
chapter: autodocs-2.0
section: iffparse-library-stoponexit
functions: [ParseIFF]
libraries: [iffparse.library]
---

# iffparse.library/StopOnExit

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    StopOnExit -- Declare a stop condition for exiting a chunk.
SYNOPSIS

```c
    error = StopOnExit (iff, type, id)
     d0                 a0    d0   d1

    LONG             error;
    struct [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) *iff;
    LONG             type;
    LONG             id;
```
FUNCTION

```c
    Installs an exit handler for the specified chunk which will cause the
    [ParseIFF()](autodocs-2.0/iffparse-library-parseiff.md) function to return control to the caller when this chunk
    is exhausted.  [ParseIFF()](autodocs-2.0/iffparse-library-parseiff.md) will return IFFERR_EOC when the declared
    chunk is about to be popped.  This is only of value when [ParseIFF()](autodocs-2.0/iffparse-library-parseiff.md)
    is called with the IFFPARSE_SCAN control code.
```
INPUTS

```c
    iff     - pointer to [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) struct (need not be open).
    type    - type code for chunk to declare (ex. "ILBM").
    id      - identifier for chunk to declare (ex. "BODY").
```
RESULT

    error   - 0 if successful or an IFFERR_#? error code if not
              successful.
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [ParseIFF()](autodocs-2.0/iffparse-library-parseiff.md)
```

---

## See Also

- [ParseIFF — iffparse.library](../autodocs/iffparse.library.md#parseiff)
