---
title: dos.library/NewLoadSeg
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-newloadseg
functions: [LoadSeg, UnLoadSeg]
libraries: [dos.library]
---

# dos.library/NewLoadSeg

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    NewLoadSeg -- Improved version of [LoadSeg](autodocs-2.0/dos-library-loadseg.md) for stacksizes (V36)
```
SYNOPSIS

```c
    seglist = NewLoadSeg(file, tags)
    D0                    D1    D2

    BPTR NewLoadSeg(STRPTR, struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) *)

    seglist = NewLoadSegTagList(file, tags)
    D0                           D1    D2

    BPTR NewLoadSegTagList(STRPTR, struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) *)

    seglist = NewLoadSegTags(file, ...)

    BPTR NewLoadSegTags(STRPTR, ...)
```
FUNCTION

```c
    Does a [LoadSeg](autodocs-2.0/dos-library-loadseg.md) on a file, and takes additional actions based on the
    tags supplied.

    Clears unused portions of Code and Data hunks (as well as BSS hunks).
    (This also applies to [InternalLoadSeg()](autodocs-2.0/dos-library-internalloadseg.md) and [LoadSeg()](autodocs-2.0/dos-library-loadseg.md)).

    NOTE to overlay users: NewLoadSeg() does NOT return seglist in
    both D0 and D1, as [LoadSeg](autodocs-2.0/dos-library-loadseg.md) does.  The current ovs.asm uses [LoadSeg()](autodocs-2.0/dos-library-loadseg.md),
    and assumes returns are in D1.  We will support this for [LoadSeg()](autodocs-2.0/dos-library-loadseg.md)
    ONLY.
```
INPUTS

    file - Filename of file to load
    tags - pointer to tagitem array
RESULT

    seglist - Seglist loaded, or NULL
BUGS

    No tags are currently defined.
SEE ALSO

```c
    [LoadSeg()](autodocs-2.0/dos-library-loadseg.md), [UnLoadSeg()](autodocs-2.0/dos-library-unloadseg.md), [InternalLoadSeg()](autodocs-2.0/dos-library-internalloadseg.md), [InternalUnLoadSeg()](autodocs-2.0/dos-library-internalunloadseg.md)
```

---

## See Also

- [LoadSeg — dos.library](../autodocs/dos.library.md#loadseg)
- [UnLoadSeg — dos.library](../autodocs/dos.library.md#unloadseg)
