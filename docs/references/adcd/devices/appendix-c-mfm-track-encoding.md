---
title: Appendix C / MFM Track Encoding
manual: devices
chapter: devices
section: appendix-c-mfm-track-encoding
functions: []
libraries: []
---

# Appendix C / MFM Track Encoding

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When data is MFM encoded, the encoding is performed on the basis of a data
block-size. In the sector encoding described above, there are bytes
individually encoded; three segments of 4 bytes of data each, treated as
longwords; one segment of 16 bytes treated as a block; two segments of
longwords for the header and data checksums; and the data area of 512
bytes treated as a block.

When the data is encoded, the odd bits are encoded first, then the even
bits of the block.

The procedure is: Make a block of bytes formed from all odd bits of the
block, encode as MFM.  Make a block of bytes formed from all even bits of
the block, encode as MFM.  Even bits are shifted left one bit position
before being encoded.

The raw MFM data that must be presented to the disk controller will be
twice as large as the unencoded data.  The relationship is:

 1 -> 01
 0 -> 10    ;if following a 0
 0 -> 00    ;if following a 1

With clever manipulation, the blitter can be used to encode and decode the
MFM.

