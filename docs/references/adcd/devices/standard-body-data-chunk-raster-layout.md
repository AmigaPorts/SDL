---
title: Standard BODY Data Chunk / Raster Layout
manual: devices
chapter: devices
section: standard-body-data-chunk-raster-layout
functions: []
libraries: []
---

# Standard BODY Data Chunk / Raster Layout

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Raster scan proceeds left-to-right (increasing X) across scan lines, then
top-to-bottom (increasing Y) down columns of scan lines.  The coordinate
system is in units of pixels, where (0,0) is the upper left corner.

The raster is typically organized as bitplanes in memory.  The
corresponding bits from each plane, taken together, make up an index into
the color map which gives a color value for that pixel.  The first
bitplane, plane 0, is the low order bit of these color indexes.

A scan line is made of one "row" from each bitplane.  A row is one plane's
bits for one scan line, but padded out to a word (2 byte) boundary (not
necessarily the first word boundary).  Within each row, successive bytes
are displayed in order and the most significant bit of each byte is
displayed first.

A "mask" is an optional "plane" of data the same size (w, h) as a
bitplane. It tells how to "cut out" part of the image when painting it
onto another image.  "One" bits in the mask mean "copy the corresponding
pixel to the destination".  "Zero" mask bits mean "leave this destination
pixel alone".  In other words, "zero" bits designate transparent pixels.

The rows of the different bitplanes and mask are interleaved in the file
(see below).  This localizes all the information pertinent to each scan
line.  It makes it much easier to transform the data while reading it to
adjust the image size or depth.  It also makes it possible to scroll a big
image by swapping rows directly from the file without the need for
random-access to all the bitplanes.

