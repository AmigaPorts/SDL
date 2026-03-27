---
title: FTXT IFF Formatted / Standard Data and Property Chunks
manual: devices
chapter: devices
section: ftxt-iff-formatted-standard-data-and-property-chunks
functions: []
libraries: []
---

# FTXT IFF Formatted / Standard Data and Property Chunks

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The main contents of a [FORM FTXT](devices/ftxt-iff-formatted-text-introduction.md) is in its character stream "[CHRS](devices/standard-data-and-property-chunks-data-chunk-chrs.md)" chunks.
Formatting property chunks may also appear.  The only formatting property
yet defined is "[FONS](devices/standard-data-and-property-chunks-property-chunk-fons.md)", a font specifier.  A FORM FTXT with no CHRS
represents an empty text stream.  A FORM FTXT may contain nested IFF
[FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md)s, [LIST](devices/a-quick-introduction-to-iff-advanced-topics.md)s, or [CAT](devices/a-quick-introduction-to-iff-advanced-topics.md) s, although a "stripping" reader (see section 3) will
ignore them.

 [Character Sets](devices/standard-data-and-property-chunks-character-set.md) 
 [Control Sequences](devices/standard-data-and-property-chunks-control-sequences.md) 
 [Data Chunk CHRS](devices/standard-data-and-property-chunks-data-chunk-chrs.md) 
 [Property Chunk FONS](devices/standard-data-and-property-chunks-property-chunk-fons.md) 
 [Future Properties](devices/standard-data-and-property-chunks-future-properties.md) 
 [Positioning Units](devices/standard-data-and-property-chunks-positioning-units.md) 

