---
title: 33 / The Structure of IFF Files / Chunks: The Building Blocks of IFF
manual: libraries
chapter: libraries
section: 33-the-structure-of-iff-files-chunks-the-building-blocks-of
functions: []
libraries: []
---

# 33 / The Structure of IFF Files / Chunks: The Building Blocks of IFF

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[IFF](libraries/33-iffparse-library-the-structure-of-iff-files.md) files contain various types and amounts of data grouped in data
chunks, each starting with a four-letter ASCII identifier (the chunk ID)
followed by a 32-bit length count (the chunk size).  The identifier and
length count make it possible for IFF readers to skip over chunks that
they don't understand or don't care about, and extract only the
information they need.  It may be helpful to think of these chunks as the
building blocks of an IFF file (Figure 33-1).




          Figure 33-1: The Chunk - The Building Block of IFF
                       ________________________
                      |                        |
                      |  `CKID' Size           |
                      |------------------------|
                      |  data data data data   |
                      |  data data data data   |
                      |  data data data ...    |
                      |________________________|
The `CKID' (chunk ID) characters of a real chunk will be a four letter
identifier such as `BODY' or `CMAP', specifying the type and format of
data stored in the chunk.  Most chunks contain a simple defined grouping
of byte, word, and long variables similar to the contents of a C
structure.  Others such as sound sample and bitmap image body chunks,
contain a stream of compressed data.

Chunk writing is fairly straightforward with the one caveat that all
chunks must be word-aligned.  Therefore an odd-length chunk must be
followed by a pad byte of zero (which is not counted in the size of the
chunk).  When chunks are nested, the enclosing chunk must state the total
size of its composite contents (including any pad bytes).


```c
    About Chunk Length.
    -------------------
    Every [IFF](libraries/33-iffparse-library-the-structure-of-iff-files.md) data chunk begins with a 4-character identifier field
    followed by a 32-bit size field (these 8 bytes are sometimes referred
    to as the chunk header).  The size field is a count of the rest of
    the data bytes in the chunk, not including any pad byte.  Hence,
    the total space occupied by a chunk is given by its size field
    (rounded to the nearest even number) + 8 bytes for the chunk header.
```
