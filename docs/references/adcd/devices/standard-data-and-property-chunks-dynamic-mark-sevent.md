---
title: Standard Data and Property Chunks / Dynamic Mark SEvent
manual: devices
chapter: devices
section: standard-data-and-property-chunks-dynamic-mark-sevent
functions: []
libraries: []
---

# Standard Data and Property Chunks / Dynamic Mark SEvent

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

An [SEvent](devices/standard-data-and-property-chunks-data-chunk-trak.md) SID_Dynamic represents a dynamic mark like ppp and fff in Common
Music Notation.  Its data field is a MIDI key velocity number 0 through
127. This sets a "volume control" for following notes in the track.  This
"track volume control" is scaled by the overall score volume in the [SHDR](devices/standard-data-and-property-chunks-required-property-shdr.md)
chunk.  The default dynamic level is 127 (full volume).

