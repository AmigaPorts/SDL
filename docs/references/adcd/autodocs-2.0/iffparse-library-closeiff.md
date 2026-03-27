---
title: iffparse.library/CloseIFF
manual: autodocs-2.0
chapter: autodocs-2.0
section: iffparse-library-closeiff
functions: [CloseIFF, InitIFF, OpenIFF]
libraries: [iffparse.library]
---

# iffparse.library/CloseIFF

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CloseIFF -- Close an IFF context.
SYNOPSIS

```c
    CloseIFF (iff)
              a0

    struct [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) *iff;
```
FUNCTION

```c
    Completes an IFF read or write operation by closing the IFF context
    established for this [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) struct.  The [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) struct itself
    is left ready for re-use and a new context can be opened with
    [OpenIFF()](autodocs-2.0/iffparse-library-openiff.md).  This function can be used for cleanup if a read or write
    fails partway through.

    As part of its cleanup operation, CloseIFF() calls the client-
    supplied stream hook vector.  The [IFFStreamCmd](autodocs-2.0/includes-libraries-iffparse-h.md) packet will be set
    as follows:

            sc_Command:     IFFCMD_CLEANUP
            sc_Buf:         (Not applicable)
            sc_NBytes:      (Not applicable)

    This operation is NOT permitted to fail;  any error code returned
    will be ignored (best to return 0, though).  DO NOT write to this
    structure.
```
INPUTS

```c
    iff     - pointer to [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) struct previously opened with
              [OpenIFF()](autodocs-2.0/iffparse-library-openiff.md).
```
RESULT

EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [OpenIFF()](autodocs-2.0/iffparse-library-openiff.md), [InitIFF()](autodocs-2.0/iffparse-library-initiff.md)
```

---

## See Also

- [CloseIFF — iffparse.library](../autodocs/iffparse.library.md#closeiff)
- [InitIFF — iffparse.library](../autodocs/iffparse.library.md#initiff)
- [OpenIFF — iffparse.library](../autodocs/iffparse.library.md#openiff)
