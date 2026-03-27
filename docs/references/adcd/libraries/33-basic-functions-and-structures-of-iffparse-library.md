---
title: 33 / / Basic Functions and Structures of IFFParse Library
manual: libraries
chapter: libraries
section: 33-basic-functions-and-structures-of-iffparse-library
functions: [AllocIFF, FreeIFF]
libraries: [iffparse.library]
---

# 33 / / Basic Functions and Structures of IFFParse Library

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The structures and flags of the IFFParse library are defined in the
include files <libraries/[iffparse.h](autodocs-2.0/includes-libraries-iffparse-h.md)> and <libraries/[iffparse.i](autodocs-2.0/includes-libraries-iffparse-i.md)>.  [IFF](libraries/33-iffparse-library-the-structure-of-iff-files.md)
files are manipulated through a structure called an [IFFHandle](autodocs-2.0/includes-libraries-iffparse-h.md).  Only some
of the fields in the IFFHandle are publicly documented.  The rest are
managed internally by IFFParse.  This handle is passed to all IFFParse
functions, and contains the current parse state and position in the file.
An IFFHandle is obtained by calling [AllocIFF()](autodocs-2.0/iffparse-library-allociff.md), and freed through
[FreeIFF()](autodocs-2.0/iffparse-library-freeiff.md).  This is the only legal way to obtain and dispose of an
IFFHandle.

The public portion of if IFFHandle is defined as follows:


```c
    /*
     * Structure associated with an active IFF stream.
     * "iff_Stream" is a value used by the client's read/write/seek
     * functions - it will not be accessed by the library itself and
     * can have any value (could even be a pointer or a BPTR).
     */
    struct IFFHandle {
            ULONG   iff_Stream;
            ULONG   iff_Flags;
            LONG    iff_Depth;      /*  Depth of context stack.  */
            /*  There are private fields hiding here.  */
    };
```

---

## See Also

- [AllocIFF — iffparse.library](../autodocs/iffparse.library.md#allociff)
- [FreeIFF — iffparse.library](../autodocs/iffparse.library.md#freeiff)
