---
title: A Quick Introduction to IFF / How to read an IFF file?
manual: devices
chapter: devices
section: a-quick-introduction-to-iff-how-to-read-an-iff-file
functions: []
libraries: []
---

# A Quick Introduction to IFF / How to read an IFF file?

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Example code and modules are provided for reading IFF files using
iffparse.library. However, if you wish to read a non-complex FORM by hand,
the following logic can be used.

Once you have entered the [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md) (for example, the FORM [ILBM](devices/ilbm-iff-interleaved-bitmap-introduction.md) shown above),
stored the FORM length (24070 in the ILBM example) and are positioned on
the first [chunk](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md), you may:

Loop: (Until end-of-file or end-of-form)


```c
        - Read the 4-character identifier of the chunk
        - Read the 32-bit (4 byte) chunklength
        - Decide if you want that chunk
              if yes, read chunklength bytes into destination
              structure or buffer
              if no, seek forward chunklength bytes
        - If chunklength is odd, seek one more byte.
```
Every IFF file is a [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md), [LIST](devices/a-quick-introduction-to-iff-advanced-topics.md), or [CAT](devices/a-quick-introduction-to-iff-advanced-topics.md) chunk.  You can recognize an
IFF file by those first 4 bytes.  ("FORM" is far and away the most common.
We'll get to LIST and CAT below.)  If the file contains a FORM, dispatch
on the FORM type ID to a chunk-reader loop like the one above.

