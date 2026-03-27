---
title: SMUS IFF Simple Musical Score / Standard Data and Property Chunks
manual: devices
chapter: devices
section: smus-iff-simple-musical-score-standard-data-and-property
functions: []
libraries: []
---

# SMUS IFF Simple Musical Score / Standard Data and Property Chunks

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A FORM [SMUS](devices/smus-iff-simple-musical-score-introduction.md) contains a required property "[SHDR](devices/standard-data-and-property-chunks-required-property-shdr.md)" followed by any number of
parallel "track" data chunks "[TRAK](devices/standard-data-and-property-chunks-data-chunk-trak.md)".  Optional property chunks such as
"NAME", copyright "(c) ", and instrument reference "INS1" may also appear.
Any of the properties may be shared over a [LIST](devices/a-quick-introduction-to-iff-advanced-topics.md) of FORMs [SMUS](devices/smus-iff-simple-musical-score-introduction.md) by putting
them in a [PROP](devices/a-quick-introduction-to-iff-advanced-topics.md) [SMUS](devices/smus-iff-simple-musical-score-introduction.md).  [See the IFF reference.]

 [Required Property SHDR](devices/standard-data-and-property-chunks-required-property-shdr.md) 
 [Optional Text Chunks](devices/standard-data-and-property-chunks-optional-text-chunks-2.md) 
 [Optional Property INS1](devices/standard-data-and-property-chunks-optional-property-ins1.md) 
 [Obsolete Property INST](devices/standard-data-and-property-chunks-obsolete-property-inst.md) 
 [Data Chunk TRAK](devices/standard-data-and-property-chunks-data-chunk-trak.md) 
 [Note and Rest Events](devices/standard-data-and-property-chunks-note-and-rest-sevents.md) 
 [Set Instrument SEvent](devices/standard-data-and-property-chunks-set-instrument-sevent.md) 
 [Set Timesignature SEvent](devices/standard-data-and-property-chunks-set-time-signature-sevent.md) 
 [Key Signature SEvent](devices/standard-data-and-property-chunks-key-signature-sevent.md) 
 [Dynamic Mark SEvent](devices/standard-data-and-property-chunks-dynamic-mark-sevent.md) 
 [Set MIDI Channel SEvent](devices/standard-data-and-property-chunks-set-midi-channel-sevent.md) 
 [Set MIDI Preset SEvent](devices/standard-data-and-property-chunks-set-midi-preset-sevent.md) 
 [Instant Music Private SEvents](devices/standard-data-and-property-chunks-instant-music-private.md) 
 [End-Mark SEvents](devices/standard-data-and-property-chunks-end-mark-sevent.md) 
 [More SEvents To Be Defined](devices/standard-data-and-property-chunks-more-sevents-to-be-defined.md) 

