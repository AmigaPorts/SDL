---
title: Additional Info / Interpreting ILBMs
manual: devices
chapter: devices
section: additional-info-interpreting-ilbms
functions: []
libraries: []
---

# Additional Info / Interpreting ILBMs

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

ILBM is a fairly simple IFF FORM.  All you really need to deal with to
extract the image are the following chunks:

(Note - Also watch for AUTH Author chunks and (c) Copyright chunks
 and preserve any copyright information if you rewrite the ILBM)

   BMHD - info about the size, depth, compaction method

```c
          (See interpreted hex dump above)
```
   CAMG - optional Amiga viewmodes chunk
```c
          Most HAM and HALFBRITE ILBMs should have this chunk.  If no
          CAMG chunk is present, and image is 6 planes deep, assume
          HAM and you'll probably be right.  Some Amiga viewmodes
          flags are HIRES=0x8000, LACE=0x4, HAM=0x800, HALFBRITE=0x80.
```
	  Note that new Amiga 2.0 ILBMs may have more complex 32-bit
	  numbers (modeid) stored in the CAMG.  However, the bits
	  described above should get you a compatible old viewmode.

   CMAP - RGB values for color registers 0 to n
```c
          (each component left justified in a byte)
```
	  If a deep ILBM (like 12 or 24 planes), there should be no CMAP
	  and instead the BODY planes are interpreted as the bits of RGB
	  in the order R0...Rn G0...Gn B0...Bn

   BODY - The pixel data, stored in an interleaved fashion as follows:

```c
          (each line individually compacted if BMHD Compression = 1)
             plane 0 scan line 0
             plane 1 scan line 0
             plane 2 scan line 0
             ...
             plane n scan line 0
             plane 0 scan line 1
             plane 1 scan line 1
             etc.
```
