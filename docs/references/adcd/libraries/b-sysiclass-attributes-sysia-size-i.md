---
title: B / sysiclass / Attributes: SYSIA_Size (I)
manual: libraries
chapter: libraries
section: b-sysiclass-attributes-sysia-size-i
functions: []
libraries: []
---

# B / sysiclass / Attributes: SYSIA_Size (I)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This attribute identifies which image size to use for the object.  This
generalizes Intuition's older concept of two different system image
dimensions.  There are three possible values for this attribute:


    SYSISIZE_MEDRES  Meant for Hires, non-interlaced 640x200/256 display.
    SYSISIZE_HIRES   Meant for Hires, interlaced 640x400/512 display.
    SYSISIZE_LOWRES  Meant for Lores 320x200/256 display.
These sizes do not apply to all of the glyphs consistently.  See the chart
below for image dimensions (width x height) according to the SYSIA_Size
and the glyph type.  An 'H' for the height means the glyph allows its
height to be specified with [IA_Height](libraries/b-imageclass-attributes-ia-left-ia-top-ia-width-ia-height.md).



    SYSISIZE        LOWRES      SYSISIZE_MEDRES  SYSISIZE_HIRES
    --------        ------      ---------------  --------------
    DEPTHIMAGE      18 x H          24 x H          24 x H
    ZOOMIMAGE       18 x H          24 x H          24 x H
    SIZEIMAGE       13 x 11         18 x 10         18 x 10
    CLOSEIMAGE      15 x H          20 x H          20 x H
    SDEPTHIMAGE     17 x H          23 x H          23 x H

    LEFTIMAGE       16 x 11         16 x 10         23 x 22
    RIGHTIMAGE      16 x 11         16 x 10         23 x 22
    UPIMAGE         13 x 11         18 x 11         23 x 22
    DOWNIMAGE       13 x 11         18 x 11         23 x 22

    CHECKIMAGE      26 x 11         26 x 11         26 x 11
    MXIMAGE         17 x 9          17 x 9          17 x 9
