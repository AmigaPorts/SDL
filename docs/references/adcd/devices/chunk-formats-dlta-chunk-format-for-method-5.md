---
title: Chunk Formats / DLTA Chunk / Format for method 5
manual: devices
chapter: devices
section: chunk-formats-dlta-chunk-format-for-method-5
functions: []
libraries: []
---

# Chunk Formats / DLTA Chunk / Format for method 5

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

In this method the same 16 pointers are used as in option 4. The first 8
are pointers to the data for up to 8 planes. The second set of 8 are not
used but were retained for several reasons.  First to be somewhat
compatible with code for option 4 (although this has not proven to be of
any benefit) and second, to allow extending the format for more bitplanes
(code has been written for up to 12 planes).

Compression/decompression is performed on a plane-by-plane basis. For each
plane, compression can be handled by the skip.c code (provided Public
Domain by Jim Kent) and decompression can be handled by unvscomp.asm (also
provided Public Domain by Jim Kent).

Compression/decompression is performed on a plane-by-plane basis. The
following description of the method is taken directly from Jim Kent's code
with minor re-wording.  Please refer to Jim's code (skip.c and
unvscomp.asm) for more details:

Each column of the bitplane is compressed separately. A 320x200 bitplane
would have 40 columns of 200 bytes each. Each column starts with an
op-count followed by a number of ops.  If the op-count is zero, that's ok,
it just means there's no change in this column from the last frame. The
ops are of three classes, and followed by a varying amount of data
depending on which class:

  1. Skip ops - this is a byte with the hi bit clear that
     says how many rows to move the "dest" pointer forward,
     ie to skip. It is non-zero.
  2. Uniq ops - this is a byte with the hi bit set.  The hi
     bit is masked down and the remainder is a count of the
     number of bytes of data to copy literally.  It's of
     course followed by the data to copy.
  3. Same ops - this is a 0 byte followed by a count byte,

     followed by a byte value to repeat count times.
Do bear in mind that the data is compressed vertically rather than
horizontally, so to get to the next byte in the destination we add the
number of bytes per row instead of one!

