---
title: ANIM.brush.doc / RIFF
manual: devices
chapter: devices
section: anim-brush-doc-riff
functions: []
libraries: []
---

# ANIM.brush.doc / RIFF

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following description of the method is based on Gary Bonham's
rewording of Jim Kent's RIFF documentation.

Compression/decompression is performed on a plane-by-plane
basis.

Each byte-column of the bitplane is compressed separately.  A
320x200 bitplane would have 40 columns of 200 bytes each.  In
general, the bitplanes are always an even number of bytes wide,
so for instance a 17x20 bitplane would have 4 columns of 20
bytes each.

Each column starts with an op-count followed by a number of
ops.  If the op-count is zero, that's ok, it just means there's
no change in this column from the last frame.  The ops are of
three kinds, and followed by a varying amount of data depending
on which kind:


     1. SKIP - this is a byte with the hi bit clear that   says
        how many rows to move the "dest" pointer forward, ie to
        skip. It is non-zero.

     2. DUMP - this is a byte with the hi bit set.  The hi bit is
        masked off and the remainder is a count of the number of
        bytes of data to XOR directly.  It is followed by the
        bytes to copy.

     3. RUN - this is a 0 byte followed by a count byte, followed
        by a byte value to repeat "count" times, XOR'ing it into
        the destination.
Bear in mind that the data is compressed vertically rather than
horizontally, so to get to the next byte in the destination  you
add the number of bytes per row instead of one.

The Format of DLTA chunks is as described in section 2.2.2 of the Anim
Spec. The encoding for type 5 is described in section 2.2.3 of the Anim
Spec.

