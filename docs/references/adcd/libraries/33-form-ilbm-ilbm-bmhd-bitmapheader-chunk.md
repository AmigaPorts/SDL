---
title: 33 / / FORM ILBM / ILBM.BMHD BitMapHeader Chunk
manual: libraries
chapter: libraries
section: 33-form-ilbm-ilbm-bmhd-bitmapheader-chunk
functions: []
libraries: []
---

# 33 / / FORM ILBM / ILBM.BMHD BitMapHeader Chunk

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The most important chunk in a [FORM ILBM](libraries/33-iffparse-library-iff-form-specifications.md) is the BMHD (BitMapHeader) chunk
which describes the size and compression of the image:


typedef UBYTE Masking;  /* Choice of masking technique - Usually 0. */
#define mskNone                 0
#define mskHasMask              1
#define mskHasTransparentColor  2
#define mskLasso                3

/* Compression algorithm applied to the rows of all source
 * and mask planes. "cmpByteRun1" is byte run encoding.
 * Do not compress across rows!  Compression is usually 1.
 */
typedef UBYTE Compression;
#define cmpNone                 0
#define cmpByteRun1             1

/* The BitMapHeader structure expressed as a C structure */
typedef struct {
```c
    UWORD w, h;                 /* raster width & height in pixels      */
    WORD  x, y;                 /* pixel position for this image        */
    UBYTE nPlanes;              /* # bitplanes (without mask, if any)   */
    Masking     masking;        /* One of the values above.  Usually 0  */
    Compression compression;    /* One of the values above.  Usually 1  */
    UBYTE reserved1;            /* reserved; ignore on read, write as 0 */
    UWORD transparentColor;     /* transparent color number. Usually 0  */
    UBYTE xAspect, yAspect;     /* pixel aspect, a ratio width : height */
    WORD  pageWidth, pageHeight;    /* source "page" size in pixels */
```
} BitMapHeader;

