---
title: dos.library/LoadSeg
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-loadseg
functions: [CreateNewProc, LoadSeg, UnLoadSeg]
libraries: [dos.library]
---

# dos.library/LoadSeg

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    LoadSeg -- Scatterload a loadable file into memory
SYNOPSIS

```c
    seglist = LoadSeg( name )
    D0                 D1

    BPTR LoadSeg(STRPTR)
```
FUNCTION

```c
    The file 'name' should be a load module produced by the linker.
    LoadSeg() scatterloads the CODE, DATA and BSS segments into memory,
    chaining together the segments with BPTR's on their first words.
    The end of the chain is indicated by a zero.  There can be any number
    of segments in a file.  All necessary relocation is handled by
    LoadSeg().

    In the event of an error any blocks loaded will be unloaded and a
    NULL result returned.

    If the module is correctly loaded then the output will be a pointer
    at the beginning of the list of blocks. Loaded code is unloaded via
    a call to [UnLoadSeg()](autodocs-2.0/dos-library-unloadseg.md).
```
INPUTS

    name - pointer to a null-terminated string
RESULTS

    seglist - BCPL pointer to a seglist
SEE ALSO

```c
    [UnLoadSeg()](autodocs-2.0/dos-library-unloadseg.md), [InternalLoadSeg()](autodocs-2.0/dos-library-internalloadseg.md), [InternalUnLoadSeg()](autodocs-2.0/dos-library-internalunloadseg.md), [CreateProc()](autodocs-2.0/dos-library-createproc.md),
    [CreateNewProc()](autodocs-2.0/dos-library-createnewproc.md), [NewLoadSeg()](autodocs-2.0/dos-library-newloadseg.md).
```

---

## See Also

- [CreateNewProc — dos.library](../autodocs/dos.library.md#createnewproc)
- [LoadSeg — dos.library](../autodocs/dos.library.md#loadseg)
- [UnLoadSeg — dos.library](../autodocs/dos.library.md#unloadseg)
