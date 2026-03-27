---
title: ILBM IFF Interleaved Bitmap / Appendix C. IFF Hints
manual: devices
chapter: devices
section: ilbm-iff-interleaved-bitmap-appendix-c-iff-hints
functions: []
libraries: []
---

# ILBM IFF Interleaved Bitmap / Appendix C. IFF Hints

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Hints on ILBM files from Jerry Morrison, Oct 1988.  How to avoid some
pitfalls when reading ILBM files:

  * Don't ignore the BitMapHeader.masking field.  A bitmap with a mask

```c
    (such as a partially-transparent DPaint brush or a DPaint picture with
    a stencil) will read as garbage if you don't de-interleave the mask.
```
  * Don't assume all images are compressed.  Narrow images aren't usually

    run-compressed since that would actually make them longer.
  * Don't assume a particular image size.  You may encounter overscan

    pictures and PAL pictures.
There's a better way to read a [BODY](devices/standard-body-data-chunk-body.md) than the example IFF code.  The
GetBODY routine should call a GetScanline routine once per scan line,
which calls a GetRow routine for each bitplane in the file.  This in turn
calls a GetUnpackedBytes routine, which calls a GetBytes routine as needed
and unpacks the result.  (If the picture is uncompressed, GetRow calls
GetBytes directly.) Since theunpacker knows how many packed bytes to read,
this avoids juggling buffers for a memory-to-memory UnPackBytes routine.

Caution: If you make many AmigaDOS calls to read or write a few bytes at a
time, performance will be mud! AmigaDOS has a high overhead per call, even
with RAM disk.  So use buffered read/write routines.

Different hardware display devices have different color resolutions:


    Device        R:G:B bits    maxColor
    -------       ----------    --------
    Mac SE            1              1
    IBM EGA       2:2:2              3
    Atari ST      3:3:3              7
    Amiga         4:4:4             15
    CD-I          5:5:5             31
    IBM VGA       6:6:6             63
    Mac II        8:8:8            255
An ILBM [CMAP](devices/standard-properties-cmap.md) defines 8 bits of Red, Green and Blue (i.e., 8:8:8 bits of
R:G:B). When displaying on hardware which has less color resolution, just
take the high order bits.  For example, to convert ILBM's 8-bit Red to the
Amiga's 4-bit Red, right shift the data by 4 bits  (R4 := R8 >> 4).

To convert hardware colors to ILBM colors, the ILBM specification says
just set the high bits (R8 := R4 << 4).  But you can transmit higher
contrast to foreign display devices by scaling the data [0..maxColor] to
the full range [0..255].  In other words, R8 := (Rn x 255) ÷ maxColor.
(Example #1:  EGA color 1:2:3 scales to 85:170:255.  Example #2:  Amiga
15:7:0 scales to 255:119:0).  This makes a big difference where maxColor
is less than 15.  In the extreme case, Mac SE white (1) should be
converted to ILBM white (255), not to ILBM gray (128).

 [CGA and EGA subtleties](devices/appendix-c-iff-hints-cga-and-ega-subtleties.md) 
 [24-bit ILBMs](devices/ilbm-iff-interleaved-bitmap-24-bit-ilbms.md) 

