---
title: Standard BODY Data Chunk / BODY
manual: devices
chapter: devices
section: standard-body-data-chunk-body
functions: []
libraries: []
---

# Standard BODY Data Chunk / BODY

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The source raster  is stored in a "BODY" chunk.  This one [chunk](devices/primitive-data-types-chunks.md) holds all
bitplanes and the optional mask, interleaved by row.

The BitMapHeader, in a [BMHD](devices/standard-properties-bmhd.md) property chunk, specifies the raster's
dimensions w, h, and nPlanes.  It also holds the masking field which
indicates if there is a mask plane and the compression field which
indicates the compression algorithm used.  This information is needed to
interpret the BODY chunk, so the BMHD chunk must appear first.  While
reading an ILBM's BODY, a program may convert the image to another size by
filling (with transparentColor) or clipping.

The BODY's content is a concatenation of scan lines.  Each scan line is a
concatenation of one row of data from each plane in order 0 through
nPlanes-1 followed by one row from the mask (if masking = hasMask ).  If
the BitMapHeader field compression is cmpNone, all h rows are exactly
(w+15)/16 words wide. Otherwise, every row is compressed according to the
specified algorithm and the stored widths depend on the data compression.

Reader programs that require fewer bitplanes than appear in a particular
ILBM file can combine planes or drop the high-order (later) planes.
Similarly, they may add bitplanes and/or discard the mask plane.

Do not compress across rows, and don't forget to compress the mask just
like the bitplanes.  Remember to pad any BODY chunk that contains an odd
number of bytes and skip the pad when reading.

