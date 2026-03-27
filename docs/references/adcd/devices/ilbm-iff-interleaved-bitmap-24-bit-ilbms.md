---
title: ILBM IFF Interleaved Bitmap / 24-bit ILBMs
manual: devices
chapter: devices
section: ilbm-iff-interleaved-bitmap-24-bit-ilbms
functions: []
libraries: []
---

# ILBM IFF Interleaved Bitmap / 24-bit ILBMs

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When storing deep images as ILBMs (such as images with 8 bits each of R,G,
and B), the bits for each pixel represent an absolute RGB value for that
pixel rather than an index into a limited color map.  The order for saving
the bits is critical since a deep ILBM would not contain the usual [CMAP](devices/standard-properties-cmap.md) of
RGB values (such a [CMAP](devices/standard-properties-cmap.md) would be too large and redundant).

To interpret these "deep" ILBMs, it is necessary to have a standard order
in which the bits of the R, G, and B values will be stored.  A number of
different orderings have already been used in deep ILBMs, so it was
necessary to us chose one of these orderings as a standard.

The following bit ordering has been chosen as the default bit ordering for
deep ILBMs.

Default standard deep ILBM bit ordering:
saved first -----------------------------------------------> saved last
R0 R1 R2 R3 R4 R5 R6 R7 G0 G1 G2 G3 G4 G5 G6 G7 B0 B1 B2 B3 B4 B5 B6 B7

One other existing deep bit ordering that you may encounter is the 21-bit
NewTek format.

NewTek deep ILBM bit ordering:
saved first ------------------------------------------------> saved last
R7 G7 B7 R6 G6 B6 R5 G5 B5 R4 G4 B4 R3 G3 B3 R2 G2 B2 R1 G1 B1 R0 G0 B0

Note that you may encounter CLUT chunks in deep ILBM's.  See the
[Third Party Specs](devices/a-iff-third-party-public-form-and-chunk-specification-ilbm-5.md) appendix for more information on CLUT chunks.

