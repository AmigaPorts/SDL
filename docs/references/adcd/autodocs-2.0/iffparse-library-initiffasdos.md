---
title: iffparse.library/InitIFFasDOS
manual: autodocs-2.0
chapter: autodocs-2.0
section: iffparse-library-initiffasdos
functions: [Open]
libraries: [dos.library]
---

# iffparse.library/InitIFFasDOS

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    InitIFFasDOS -- Initialize an [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) as a DOS stream.
```
SYNOPSIS

```c
    InitIFFasDOS (iff)
                  a0

    struct [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) *iff;
```
FUNCTION

```c
    The function initializes the given [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) to operate on DOS
    streams.  The iff_Stream field will need to be initialized as a BPTR
    returned from the DOS function [Open()](autodocs-2.0/dos-library-open.md).
```
INPUTS

```c
    iff     - pointer to [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md) struct.
```
RESULT

EXAMPLE

NOTES

BUGS

SEE ALSO

---

## See Also

- [Open — dos.library](../autodocs/dos.library.md#open)
