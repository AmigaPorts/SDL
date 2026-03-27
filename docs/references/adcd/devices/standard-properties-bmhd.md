---
title: Standard Properties / BMHD
manual: devices
chapter: devices
section: standard-properties-bmhd
functions: []
libraries: []
---

# Standard Properties / BMHD

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The required property "BMHD" holds a BitMapHeader as defined in the
following documentation.  It describes the dimensions of the image, the
encoding used, and other data necessary to understand the [BODY](devices/standard-body-data-chunk-body.md) to
follow.


typedef UBYTE Masking;     /* Choice of masking technique. */

#define mskNone                0
#define mskHasMask             1
#define mskHasTransparentColor 2
#define mskLasso               3

typedef UBYTE Compression;    /* Choice of compression algorithm
   applied to the rows of all source and mask planes.  "cmpByteRun1"
   is the byte run encoding described in [Appendix C](devices/ilbm-iff-interleaved-bitmap-appendix-c-iff-hints.md).  Do not compress
   across rows! */
#define cmpNone        0
#define cmpByteRun1    1

typedef struct {
  UWORD       w, h;             /* raster width & height in pixels      */
  WORD        x, y;             /* pixel position for this image        */
  UBYTE       nPlanes;          /* # source bitplanes                   */
  Masking     masking;
  Compression compression;
  UBYTE       pad1;             /* unused; ignore on read, write as 0   */
  UWORD       transparentColor; /* transparent "color number" (sort of) */
  UBYTE       xAspect, yAspect; /* pixel aspect, a ratio width : height */
  WORD        pageWidth, pageHeight; /* source "page" size in pixels    */


```c
    } BitMapHeader;
```
Fields are filed in the order shown.  The UBYTE fields are byte-packed
(the C compiler must not add pad bytes to the structure).

The fields w and h indicate the size of the image rectangle in pixels.
Each row of the image is stored in an integral number of 16 bit words.
The number of words per row is words=((w+15)/16) or Ceiling(w/16).  The
fields x and y indicate the desired position of this image within the
destination picture. Some reader programs may ignore x and y.  A safe
default for writing an ILBM is (x, y) = (0, 0).

The number of source bitplanes in the [BODY](devices/standard-body-data-chunk-body.md) chunk is stored in nPlanes.  An
ILBM with a [CMAP](devices/standard-properties-cmap.md) but no BODY and nPlanes = 0 is the recommended way to
store a color map.

Note: Color numbers are color map index values formed by pixels in the
destination bitmap, which may be deeper than nPlanes if a [DEST](devices/standard-properties-dest.md) chunk calls
for merging the image into a deeper image.

The field masking indicates what kind of masking is to be used for this
image. The value mskNone designates an opaque rectangular image.  The
value mskHasMask means that a mask plane is interleaved with the bitplanes
in the [BODY](devices/standard-body-data-chunk-body.md) chunk (see below).  The value mskHasTransparentColor indicates
that pixels in the source planes matching transparentColor are to be
considered "transparent". (Actually, transparentColor isn't a "color
number" since it's matched with numbers formed by the source bitmap rather
than the possibly deeper destination bitmap.  Note that having a
transparent color implies ignoring one of the color registers.  The value
mskLasso indicates the reader may construct a mask by lassoing the image
as in MacPaint(tm).  To do this, put a 1 pixel border of transparentColor
around the image rectangle.  Then do a seed fill from this border.  Filled
pixels are to be transparent.

Issue: Include in an appendix an algorithm for converting a transparent
color to a mask plane, and maybe a lasso algorithm.

A code indicating the kind of data compression used is stored in
compression. Beware that using data compression makes your data unreadable
by programs that don't implement the matching decompression algorithm.  So
we'll employ as few compression encodings as possible.  The run encoding
byteRun1 is documented in [Appendix C](devices/ilbm-iff-interleaved-bitmap-appendix-c-iff-hints.md).

The field pad1 is a pad byte reserved for future use.  It must be set to 0
for consistency.

The transparentColor specifies which bit pattern means "transparent".
This only applies if masking is mskHasTransparentColor or mskLasso.
Otherwise, transparentColor should be 0 (see above).

The pixel aspect ratio is stored as a ratio in the two fields xAspect and
yAspect.  This may be used by programs to compensate for different aspects
or to help interpret the fields w, h, x, y, pageWidth, and pageHeight,
which are in units of pixels.  The fraction xAspect/yAspect represents a
pixel's width/height.  It's recommended that your programs store proper
fractions in the BitMapHeader, but aspect ratios can always be correctly
compared with the test:

	xAspect * yDesiredAspect = yAspect * xDesiredAspect

Typical values for aspect ratio are width : height = 10 : 11  for an Amiga
320 x 200 display and 1 : 1 for a Macintosh(tm) display.

The size in pixels of the source "page" (any raster device) is stored in
pageWidth and pageHeight, e.g., (320, 200) for a low resolution Amiga
display. This information might be used to scale an image or to
automatically set the display format to suit the image.  Note that the
image can be larger than the page.

