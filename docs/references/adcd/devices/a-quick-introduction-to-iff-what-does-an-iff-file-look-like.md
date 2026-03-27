---
title: A Quick Introduction to IFF / What does an IFF file look like?
manual: devices
chapter: devices
section: a-quick-introduction-to-iff-what-does-an-iff-file-look-like
functions: []
libraries: []
---

# A Quick Introduction to IFF / What does an IFF file look like?

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

IFF is based on data blocks called "chunk"s. Here's an example color map
chunk:

                         +------------------+ in an ILBM file, CMAP means
          char typeID[4] | "CMAP"           | "color map"
                         |------------------+
  unsigned long dataSize |  48              | 48 data bytes

                         |------------------+
             char data[] |  0,0,0,255,      | 16 3-byte color values:
                         |  255,255,255...  | black, white, ....
                         +------------------+

                         +------------------+ in an ILBM file, CMAP means
                         | "CMAP"           | "color map"
                         |------------------+
                         |  48              | 48 data bytes
                         |------------------+
                         |  0,0,0,255,      | 16 3-byte color values:
                         |  255,255,255...  | black, white, ....
                         +------------------+
A chunk is made of a 4-character type identifier, a 32 bit data byte
count, and the data bytes. It's like a Macintosh "resource" with a 32-bit
size.

Fine points:

 o Every 16- and 32-bit number is stored in 68000 byte order - highest

    byte first.
   An Intel CPU must reverse the 2- or 4-byte sequence of each number.
   This applies to chunk dataSize fields and to numbers inside chunk
   data.  It does not affect character strings and byte data because you
   can't reverse a 1-byte sequence.  But it does affect the 32-bit math
   used in IFF's MakeID macro.  The standard does allow CPU specific byte
   ordering hidden within a chunk itself, but the practice is discouraged.

 o Every 16- and 32-bit number is stored on an even address.

 o Every odd-length chunk must be followed by a 0 pad byte.  This pad

    byte is not counted in dataSize.
 o An ID is made of 4 ASCII characters in the range " " (space, hex 20)

```c
    through "~" (tilde, hex 7E).  Leading spaces are not permitted.
```
 o IDs are compared using a quick 32-bit equality test.  Case matters.

A chunk typically holds a C structure, Pascal record, or an array.  For
example, an [ILBM](devices/ilbm-iff-interleaved-bitmap-introduction.md) picture has a [BMHD](devices/standard-properties-bmhd.md) bitmap header chunk (a structure)
and a [BODY](devices/standard-body-data-chunk-body.md) raster body chunk (an array).

To construct an IFF file, just put a file type ID (like [ILBM](devices/ilbm-iff-interleaved-bitmap-introduction.md)) into a
wrapper chunk called a "FORM" (Think "FILE").  Inside that wrapper place
chunks one after another (with pad bytes as needed).  The chunk size
always tells you how many more bytes you need to skip over to get to the
next chunk.

	          +------------------+
	          |                  |
	          |  "FORM"          |  FORM is a special chunk ID
	          |                  |
	          +------------------+
	          |   24070          |  24070 data bytes
	       -- +------------------+
	       |  |                  |
	       |  |  "ILBM"          |  FORM type is ILBM
	       |  |                  |
	       |  | +--------------+ |
	       |  | |  "BMHD"      | |  A BMHD bitmap header chunk
	       |  | |--------------| |  (20 data bytes)
	       |  | |   20         | |
	       |  | |--------------| |
	       |  | |  320, 200,   | |
	       |  | |  0 ....      | |
	       |  | +--------------+ |
	       |  |                  |
	       |  | +--------------+ |
	       |  | |  "CMAP"      | |  A CMAP color map chunk
	24070 <   | |--------------| |  (21 data bytes = 1 pad)
	bytes  |  | |   21         | |
	       |  | |--------------| |
	       |  | |  0, 0, 0,    | |
	       |  | |  255 ....    | |
	       |  | +--------------+ |
	       |  |   0              |  A pad byte
	       |  | +--------------+ |
	       |  | |  "BODY"      | |
	       |  | |--------------| |  A BODY raster body chunk
	       |  | |  24000       | |  (24000 data bytes)
	       |  | |--------------| |
	       |  | |  0, 0, 0.... | |
	       |  | +--------------+ |
	       -- +------------------+

A FORM always contains one 4-character FORM type ID (a file type, in this
case "[ILBM](devices/ilbm-iff-interleaved-bitmap-introduction.md)") followed by any number of data chunk.  In this example, the
FORM type is "ILBM", which stands for "InterLeaved BitMap".  ([ILBM](devices/ilbm-iff-interleaved-bitmap-introduction.md) is an
IFF standard for bitplane raster pictures.)  This example has 3 chunks.
Note the pad byte after the odd length chunk.

Within FORMs [ILBM](devices/ilbm-iff-interleaved-bitmap-introduction.md), [BMHD](devices/standard-properties-bmhd.md) identifies a bitmap header chunk, [CMAP](devices/standard-properties-cmap.md) a color
map, and [BODY](devices/standard-body-data-chunk-body.md) a raster body.  In general, the chunk IDs in a FORM are
local to the FORM type ID.  The  exceptions are the 4 global chunk IDs
"FORM", [LIST](devices/a-quick-introduction-to-iff-advanced-topics.md), [CAT](devices/a-quick-introduction-to-iff-advanced-topics.md) , and [PROP](devices/a-quick-introduction-to-iff-advanced-topics.md).  (A FORM may contain other FORM
chunks.  E.g., an animation FORM might contain picture FORMs and sound
FORMs.)

