---
title: 33 / Stream Management / Custom Streams
manual: libraries
chapter: libraries
section: 33-stream-management-custom-streams
functions: [Open, Read, Write]
libraries: [dos.library]
---

# 33 / Stream Management / Custom Streams

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A custom stream handler can allow you (and iffparse.library) to use your
compiler's own file I/O functions such as fopen(), fread() and fwrite(),
rather than the lower-level AmigaDOS equivalents [Open()](libraries/33-stream-management-initialization.md), [Read()](autodocs-2.0/dos-library-read.md), and
[Write()](autodocs-2.0/dos-library-write.md).  A custom stream handler could also be used to read or write [IFF](libraries/33-iffparse-library-the-structure-of-iff-files.md)
files from an Exec device or an unusual handler or filesystem.

If you install your own stream handler function, iffparse.library will
call your function whenever it needs to read, write, or seek on your file.
Your stream handler function will then perform these stream actions for
iffparse.library.  See the "[Custom Stream Handlers](libraries/33-advanced-topics-custom-stream-handlers.md)" section for more
information on custom stream handlers.

---

## See Also

- [Open — dos.library](../autodocs/dos.library.md#open)
- [Read — dos.library](../autodocs/dos.library.md#read)
- [Write — dos.library](../autodocs/dos.library.md#write)
