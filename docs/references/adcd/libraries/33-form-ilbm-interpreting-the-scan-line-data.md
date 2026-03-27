---
title: 33 / / FORM ILBM / Interpreting the Scan Line Data
manual: libraries
chapter: libraries
section: 33-form-ilbm-interpreting-the-scan-line-data
functions: []
libraries: []
---

# 33 / / FORM ILBM / Interpreting the Scan Line Data

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

If the [ILBM](libraries/33-iffparse-library-iff-form-specifications.md) is not HAM or HALFBRITE, then after parsing and uncompacting
if necessary, you will have N planes of pixel data.  Color register used
for each pixel is specified by looking at each pixel thru the planes. For
instance, if you have 5 planes, and the bit for a particular pixel is set
in planes 0 and 3:


        PLANE     4 3 2 1 0
        PIXEL     0 1 0 0 1
then that pixel uses color register binary 01001 = 9.

The RGB value for each color register is stored in the [CMAP](libraries/33-form-ilbm-interpreting-ilbms.md) chunk of the
[ILBM](libraries/33-iffparse-library-iff-form-specifications.md), starting with register 0, with each register's RGB value stored as
one byte of R, one byte G, and one byte of B, with each component left
justified in the byte.  (ie. Amiga R, G, and B components are each stored
in the high nibble of a byte)

But, if the picture is HAM or HALFBRITE, it is interpreted differently.
Hopefully, if the picture is HAM or HALFBRITE, the package that saved it
properly saved a [CAMG](libraries/33-form-ilbm-interpreting-ilbms.md) chunk (look at a hex dump of your file with ASCII
interpretation - you will see the chunks - they all start with a
4-ASCII-char chunk ID).  If the picture is 6 planes deep and has no CAMG
chunk, it is probably HAM.   If you see a CAMG chunk, the `CAMG' is
followed by the 32-bit chunk length, and then the 32-bit Amiga view mode
flags.

HAM pictures will have the 0x800 bit set in [CAMG](libraries/33-form-ilbm-interpreting-ilbms.md) chunk ViewModes. HALBRITE
pictures will have the 0x80 bit set.  See the [graphics library](libraries/graphics-libraries.md) chapters or
the Amiga [Hardware](hardware/amiga-hardware-reference-manual-contents.md) Reference Manual for more information on HAM and
HALFBRITE modes.

