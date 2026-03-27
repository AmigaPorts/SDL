---
title: A Quick Introduction to IFF / What is IFF?
manual: devices
chapter: devices
section: a-quick-introduction-to-iff-what-is-iff
functions: []
libraries: []
---

# A Quick Introduction to IFF / What is IFF?

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

IFF, the "Interchange File Format" standard, encourages multimedia
interchange between different programs and different computers.  It
supports long-lived, extensible data.  It's great for composite files like
a page layout file that includes photos, an animation file that includes
music, and a library of sound effects.

IFF is a 2-level standard.  The first layer is the "wrapper" or "envelope"
structure for all IFF files.  Technically, it's the syntax.  The second
layer defines particular IFF file types such as [ILBM](devices/ilbm-iff-interleaved-bitmap-introduction.md) (standard raster
pictures), ANIM (animation), [SMUS](devices/smus-iff-simple-musical-score-introduction.md) (simple musical score), and [8SVX](devices/8svx-iff-8-bit-sampled-voice-introduction.md) (8-bit
sampled audio voice).

IFF is also a design idea: programs should use interchange formats for
their everyday storage.

This way, users rarely need converters and import/export commands to
change software releases, application programs, or hardware.

