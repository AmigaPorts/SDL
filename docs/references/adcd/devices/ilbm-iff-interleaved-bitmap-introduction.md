---
title: ILBM IFF Interleaved Bitmap / Introduction
manual: devices
chapter: devices
section: ilbm-iff-interleaved-bitmap-introduction
functions: []
libraries: []
---

# ILBM IFF Interleaved Bitmap / Introduction

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[EA IFF 85](devices/a-quick-introduction-to-iff-what-is-iff.md) is Electronic Arts' standard for interchange format files.
"ILBM" is a format for a 2 dimensional raster graphics image, specifically
an InterLeaved bitplane BitMap image with color map.  An ILBM is an IFF
"data section" or "[FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md) type", which can be an IFF file or a part of one.
ILBM allows simple, highly portable raster graphic storage.

An ILBM is an archival representation designed for three uses.  First, a
stand- alone image that specifies exactly how to display itself
(resolution, size, color map, etc.).  Second, an image intended to be
merged into a bigger picture which has its own depth, color map, and so
on.  And third, an empty image with a color map selection or "palette" for
a paint program.  ILBM is also intended as a building block for composite
IFF [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md)s like "animation sequences" and "structured graphics".  Some uses
of ILBM will be to preserve as much information as possible across
disparate environments.  Other uses will be to store data for a single
program or highly cooperative programs while maintaining subtle details.
So we're trying to accomplish a lot with this one format.

This memo is the IFF supplement for FORM ILBM.  Section 2 defines the
purpose and format of property chunks bitmap header "[BMHD](devices/standard-properties-bmhd.md)", color map
"[CMAP](devices/standard-properties-cmap.md)", hotspot "[GRAB](devices/standard-properties-grab.md)", destination merge data "[DEST](devices/standard-properties-dest.md)", sprite information
"[SPRT](devices/standard-properties-sprt.md)", and Commodore Amiga viewport mode "[CAMG](devices/standard-properties-camg.md)".  Section 3 defines the
standard data [chunk](devices/primitive-data-types-chunks.md) "[BODY](devices/standard-body-data-chunk-body.md)".  These are the "standard" [chunk](devices/primitive-data-types-chunks.md)s.  Section 4
defines the non- standard data chunks.  Additional specialized chunks like
texture pattern can be added later.  The ILBM syntax is summarized in
[Appendix A](devices/ilbm-iff-interleaved-bitmap-appendix-a-ilbm-regular.md) as a regular expression and in [Appendix B](devices/ilbm-iff-interleaved-bitmap-appendix-b-ilbm-box-diagram.md) as a box diagram.
[Appendix C](devices/ilbm-iff-interleaved-bitmap-appendix-c-iff-hints.md) explains the optional run encoding scheme.  [Appendix D](devices/ilbm-iff-interleaved-bitmap-appendix-d-byterun1-run-encoding.md) names
the committee responsible for this FORM ILBM standard.

Details of the raster layout are given in part 3, [Standard Data Chunk](devices/standard-body-data-chunk-raster-layout.md).
Some elements are based on the Commodore Amiga hardware but generalized
for use on other computers.  An alternative to ILBM would be appropriate
for computers with true color data in each pixel, though the wealth of
available ILBM images makes import and export important.

 [Reference](devices/ilbm-iff-interleaved-bitmap-reference.md) 

