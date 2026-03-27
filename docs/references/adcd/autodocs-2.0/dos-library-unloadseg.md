---
title: dos.library/UnLoadSeg
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-unloadseg
functions: [LoadSeg]
libraries: [dos.library]
---

# dos.library/UnLoadSeg

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    UnLoadSeg -- Unload a seglist previously loaded by [LoadSeg()](autodocs-2.0/dos-library-loadseg.md)
```
SYNOPSIS

```c
    success = UnLoadSeg( seglist )
    D0                     D1

    BOOL UnLoadSeg(BPTR)
```
FUNCTION

```c
    Unload a seglist loaded by [LoadSeg()](autodocs-2.0/dos-library-loadseg.md).  'seglist' may be zero.
    Overlaid segments will have all needed cleanup done, including
    closing files.
```
INPUTS

    seglist - BCPL pointer to a segment identifier
RESULTS

    success - returns 0 if a NULL seglist was passed or if it failed
              to close an overlay file.  NOTE: this function returned
              a random value before V36!
SEE ALSO

```c
    [LoadSeg()](autodocs-2.0/dos-library-loadseg.md), [InternalLoadSeg()](autodocs-2.0/dos-library-internalloadseg.md), [InternalUnLoadSeg()](autodocs-2.0/dos-library-internalunloadseg.md)
```

---

## See Also

- [LoadSeg — dos.library](../autodocs/dos.library.md#loadseg)
