---
title: ILBM IFF Interleaved Bitmap / Standard Properties
manual: devices
chapter: devices
section: ilbm-iff-interleaved-bitmap-standard-properties
functions: []
libraries: []
---

# ILBM IFF Interleaved Bitmap / Standard Properties

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

ILBM has several defined property [chunk](devices/primitive-data-types-chunks.md)s that act on the main data chunks.
The required property "[BMHD](devices/standard-properties-bmhd.md)" and any optional properties must appear
before any "[BODY](devices/standard-body-data-chunk-body.md)" chunk.  (Since an ILBM has only one BODY chunk, any
following properties would be superfluous.)  Any of these properties may
be shared over a [LIST](devices/a-quick-introduction-to-iff-advanced-topics.md) of several ILBMs by putting them in a PROP ILBM (See
the EA IFF 85 document).

 [BMHD](devices/standard-properties-bmhd.md) 
 [CMAP](devices/standard-properties-cmap.md) 
 [GRAB](devices/standard-properties-grab.md) 
 [DEST](devices/standard-properties-dest.md) 
 [SPRT](devices/standard-properties-sprt.md) 
 [CAMG](devices/standard-properties-camg.md) 

