---
title: 27 / / Performing Data Move Operations / Clearing a Memory Area
manual: libraries
chapter: libraries
section: 27-performing-data-move-operations-clearing-a-memory-area
functions: []
libraries: []
---

# 27 / / Performing Data Move Operations / Clearing a Memory Area

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

For memory that is accessible to the blitter (that is, internal Chip
memory), the most efficient way to clear a range of memory is to use the
blitter. You use the blitter to clear a block of memory with the statement:


```c
    BltClear(memblock, bytecount, flags);
```
The memblock argument is a pointer to the location of the first byte to be
cleared and bytecount is the number of bytes to set to zero.  In general
the flags variable should be set to one to wait for the blitter operation
to complete.  Refer to the Amiga ROM Kernel Manual: [Includes and Autodocs](autodocs-2.0/graphics-library-bltclear.md)
for other details about the flag argument.

