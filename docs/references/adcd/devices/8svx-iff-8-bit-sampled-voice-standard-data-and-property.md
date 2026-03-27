---
title: 8SVX IFF 8-Bit Sampled Voice / Standard Data and Property Chunks
manual: devices
chapter: devices
section: 8svx-iff-8-bit-sampled-voice-standard-data-and-property
functions: []
libraries: []
---

# 8SVX IFF 8-Bit Sampled Voice / Standard Data and Property Chunks

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[FORM 8SVX](devices/8svx-iff-8-bit-sampled-voice-introduction.md) stores all the waveform data in one body chunk "[BODY](devices/standard-data-and-property-chunks-data-chunk-body.md)".  It
stores playback parameters in the required header chunk "[VHDR](devices/standard-data-and-property-chunks-required-property-vhdr.md)".  "VHDR"
and any optional property chunks "[NAME](devices/standard-data-and-property-chunks-optional-text-chunks.md)", "[(c)](devices/standard-data-and-property-chunks-optional-text-chunks.md) ", and "[AUTH](devices/standard-data-and-property-chunks-optional-text-chunks.md)" must all
appear before the BODY chunk.  Any of these properties may be shared over
a LIST of FORMs 8SVX by putting them in a PROP 8SVX.  [See "[EA IFF 85](devices/a-quick-introduction-to-iff-what-is-iff.md)"
Standard for Interchange Format Files.]

 [Background](devices/standard-data-and-property-chunks-background.md) 
 [Required Property VHDR](devices/standard-data-and-property-chunks-required-property-vhdr.md) 
 [Optional Text Chunks](devices/standard-data-and-property-chunks-optional-text-chunks.md) 
 [Optional Data Chunks ATAK and RLSE](devices/standard-data-and-property-chunks-optional-data-chunks-atak.md) 
 [Data Chunk BODY](devices/standard-data-and-property-chunks-data-chunk-body.md) 
 [Other Chunks](devices/standard-data-and-property-chunks-other-chunks.md) 

