---
title: Standard Properties / CMAP
manual: devices
chapter: devices
section: standard-properties-cmap
functions: []
libraries: []
---

# Standard Properties / CMAP

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The optional (but encouraged) property "CMAP" stores color map data as
triplets of red, green, and blue intensity values.  The n color map
entries ("color registers") are stored in the order 0 through n-1,
totaling 3n bytes. Thus n is the ckSize/3.  Normally, n would equal
2^(nPlanes).

A CMAP chunk contains a ColorMap array as defined below.  Note that these
typedefs assume a C compiler that implements packed arrays of 3-byte
elements.


```c
    typedef struct {
        UBYTE red, green, blue;           /* color intensities 0..255 */
        } ColorRegister;                  /* size = 3 bytes           */

    typedef ColorRegister ColorMap[n];    /* size = 3n bytes          */
```
The color components red, green, and blue represent fractional intensity
values in the range 0 through 255 256ths.  White is (255, 255, 255) and
black is (0, 0, 0).  If your machine has less color resolution, use the
high order bits.  Shift each field right on reading (or left on writing)
and assign it to (from) a field in a local packed format like Color4,
below.  This achieves automatic conversion of images across environments
with different color resolutions.  On reading an ILBM, use defaults if the
color map is absent or has fewer color registers than you need.  Ignore
any extra color registers. (See [Appendix E](devices/ilbm-iff-interleaved-bitmap-appendix-e-standards-committee.md) for a better way to write
colors)

The example type Color4 represents the format of a color register in
working memory of an Amiga computer, which has 4 bit video DACs.  (The
":4" tells smarter C compilers to pack the field into 4 bits.)


```c
    typedef struct {
        unsigned pad1 :4, red :4, green :4, blue :4;
        } Color4;                /*   Amiga RAM format.  Not filed.  */
```
Remember that every [chunk](devices/primitive-data-types-chunks.md) must be padded to an even length, so a color map
with an odd number of entries would be followed by a 0 byte, not included
in the ckSize.

