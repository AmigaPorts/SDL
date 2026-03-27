---
title: dos.library/InternalUnLoadSeg
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-internalunloadseg
functions: [Close, LoadSeg, UnLoadSeg]
libraries: [dos.library]
---

# dos.library/InternalUnLoadSeg

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    InternalUnLoadSeg -- Unloads a seglist loaded with [InternalLoadSeg()](autodocs-2.0/dos-library-internalloadseg.md)
                         (V36)
```
SYNOPSIS

```c
    success = InternalUnLoadSeg(seglist,FreeFunc)
      D0                          D1       A1

    BOOL InternalUnLoadSeg(BPTR,void (*)(STRPTR,ULONG))
```
FUNCTION

```c
    Unloads a seglist using freefunc to free segments.  Freefunc is called
    as for [InternalLoadSeg](autodocs-2.0/dos-library-internalloadseg.md).  NOTE: will call [Close()](autodocs-2.0/dos-library-close.md) for overlaid
    seglists.
```
INPUTS

    seglist  - Seglist to be unloaded
    FreeFunc - Function called to free memory
RESULT

```c
    success - returns whether everything went OK (since this may close
              files).  Also returns FALSE if seglist was NULL.
```
BUGS

    Really should use tags
SEE ALSO

```c
    [LoadSeg()](autodocs-2.0/dos-library-loadseg.md), [UnLoadSeg()](autodocs-2.0/dos-library-unloadseg.md), [InternalLoadSeg()](autodocs-2.0/dos-library-internalloadseg.md), NewUnLoadSeg(), [Close()](autodocs-2.0/dos-library-close.md)
```

---

## See Also

- [Close — dos.library](../autodocs/dos.library.md#close)
- [LoadSeg — dos.library](../autodocs/dos.library.md#loadseg)
- [UnLoadSeg — dos.library](../autodocs/dos.library.md#unloadseg)
