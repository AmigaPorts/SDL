---
title: A / IFF Third Party Public Form and Chunk Specification / RGBN-RGB8.doc
manual: devices
chapter: devices
section: a-iff-third-party-public-form-and-chunk-specification-rgbn
functions: []
libraries: []
---

# A / IFF Third Party Public Form and Chunk Specification / RGBN-RGB8.doc

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

RGB image forms, Turbo Silver (Impulse)

                    FORM RGBN and FORM RGB8
		    -----------------------

RGBN and RGB8 files are used in Impulse's Turbo Silver and Imagine. They
are almost identical to FORM ILBM's except for the BODY chunk and slight
differences in the BMHD chunk.

A CAMG chunk IS REQUIRED.

The BMHD chunk specfies the number of bitplanes as 13 for type RGBN and 25
for type RGB8, and the compression type as 4.

The FORM RGBN uses 12 bit RGB values, and the FORM RGB8 uses 24 bit RGB
values.

The BODY chunk contains RGB values, a "genlock" bit, and repeat counts. In
Silver, when "genlock" bit is set, a "zero color" is written into the
bitplanes for genlock video to show through. In Diamond and Light24
(Impulse 12 & 24 bit paint programs), the genlock bit is ignored if the
file is loaded as a picture (and the RGB color is used instead), and if
the file is loaded as a brush the genlock bit marks pixels that are not
part of the brush.

For both RGBN and RGB8 body chunks, each RGB value always has a repeat
count.  The values are written in different formats depending on the
magnitude of the repeat count.

 [RGBN BODY Chunk](devices/rgbn-rgb8-doc-rgbn-body-chunk.md) 
 [RGB8 Body Chunk](devices/rgbn-rgb8-doc-rgb8-body-chunk.md) 
 [Sample BODY Code](devices/rgbn-rgb8-doc-sample-body-code.md) 

