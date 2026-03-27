---
title: Primitive Data Types / Alignment
manual: devices
chapter: devices
section: primitive-data-types-alignment
functions: []
libraries: []
---

# Primitive Data Types / Alignment

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

All data objects larger than a byte are aligned on even byte addresses
relative to the start of the file.  This may require padding.  Pad bytes
are to be written as zeros, but don't count on that when reading.

This means that every odd-length "chunk" must be padded so that the next
one will fall on an even boundary.  Also, designers of structures to be
stored in chunks should include pad fields where needed to align every
field larger than a byte.  For best efficiency, long word data should be
arranged on long word (4 byte) boundaries.  Zeros should be stored in all
the pad bytes.

Justification: Even-alignment causes a little extra work for files that
are used only on certain processors but allows 68000 programs to construct
and scan the data in memory and do block I/O.  Any 16-bit or greater CPU
will have faster access to aligned data.  You just add an occasional pad
field to data structures that you're going to block read/write or else
stream read/write an extra byte.  And the same source code works on all
processors.  Unspecified alignment, on the other hand, would force 68000
programs to (dis)assemble word and long word data one byte at a time.
Pretty cumbersome in a high level language.  And if you don't
conditionally compile that step out for other processors, you won't gain
anything.

