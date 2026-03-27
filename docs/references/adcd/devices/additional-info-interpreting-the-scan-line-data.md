---
title: Additional Info / Interpreting the Scan Line Data
manual: devices
chapter: devices
section: additional-info-interpreting-the-scan-line-data
functions: []
libraries: []
---

# Additional Info / Interpreting the Scan Line Data

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

If the ILBM is not HAM or HALFBRITE, then after parsing and uncompacting
if necessary, you will have N planes of pixel data.  Color register used
for each pixel is specified by looking at each pixel thru the planes.
I.e., if you have 5 planes, and the bit for a particular pixel is set in
planes 0 and 3:


       PLANE     4 3 2 1 0
       PIXEL     0 1 0 0 1
then that pixel uses color register binary 01001 = 9

The RGB value for each color register is stored in the CMAP chunk of the
ILBM, starting with register 0, with each register's RGB value stored as
one byte of R, one byte G, and one byte of B, with each component scaled
to 8-bits.  (ie. 4-bit Amiga R, G, and B components are each stored in the
high nibble of a byte.  The low nibble may also contain valid data if the
color was stored with 8-bit-per-gun color resolution).


BUT - if the picture is HAM or HALFBRITE, it is interpreted differently.

```c
                        ===    =========
```
Hopefully, if the picture is HAM or HALFBRITE, the package that saved it
properly saved a CAMG chunk (look at a hex dump of your file with ACSII
interpretation - you will see the chunks - they all start with a 4-ASCII-
character chunk ID).  If the picture is 6 planes deep and has no CAMG
chunk, it is probably HAM.   If you see a CAMG chunk, the "CAMG" is
followed by the 32-bit chunk length, and then the 32-bit Amiga Viewmode
flags.

HAM pics with a 16-bit CAMG will have the 0x800 bit set in CAMG ViewModes.
HALBRITE pics will have the 0x80 bit set.

To transport a HAM or HALFBRITE picture to another machine, you must
understand how HAM and HALFBRITE work on the Amiga.

