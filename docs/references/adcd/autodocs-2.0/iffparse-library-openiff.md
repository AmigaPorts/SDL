---
title: iffparse.library/OpenIFF
manual: autodocs-2.0
chapter: autodocs-2.0
section: iffparse-library-openiff
functions: [CloseIFF, InitIFF, OpenIFF]
libraries: [iffparse.library]
---

# iffparse.library/OpenIFF

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    OpenIFF -- Prepare an [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) to read or write a new IFF stream.
```
SYNOPSIS

```c
    error = OpenIFF (iff, rwmode)
     d0              a0     d0

    LONG             error;
    struct [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) *iff;
    LONG             rwmode;
```
FUNCTION

```c
    Initializes an [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) struct for a new read or write.  The
    direction of the I/O is given by the value of rwmode, which can be
    either IFFF_READ or IFFF_WRITE.

    As part of its initialization procedure, OpenIFF() calls the client-
    supplied stream hook vector.  The [IFFStreamCmd](autodocs-2.0/includes-libraries-iffparse-h.md) packet will contain
    the following:

            sc_Command:     IFFCMD_INIT
            sc_Buf:         (Not applicable)
            sc_NBytes:      (Not applicable)

    This operation is permitted to fail.  DO NOT write to this structure.
```
INPUTS

```c
    iff     - pointer to [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) struct.
    rwmode  - IFFF_READ or IFFF_WRITE
```
RESULT

    error   - contains an error code or 0 if successful.
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [CloseIFF()](autodocs-2.0/iffparse-library-closeiff.md), [InitIFF()](autodocs-2.0/iffparse-library-initiff.md)
```

---

## See Also

- [CloseIFF — iffparse.library](../autodocs/iffparse.library.md#closeiff)
- [InitIFF — iffparse.library](../autodocs/iffparse.library.md#initiff)
- [OpenIFF — iffparse.library](../autodocs/iffparse.library.md#openiff)
