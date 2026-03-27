---
title: A / IFF Third Party Public Form and Chunk Specification / AIFF.doc
manual: devices
chapter: devices
section: a-iff-third-party-public-form-and-chunk-specification-aiff
functions: []
libraries: []
---

# A / IFF Third Party Public Form and Chunk Specification / AIFF.doc

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Audio 1-32 bit samples (Mac,AppleII,Synthia Pro)

provided by Steve Milne and Matt Deatherage, Apple Computer, Inc.



           AIFF: Audio Interchange File Format File
The Audio Interchange File Format (Audio IFF) provides a standard for
storing sampled sounds.  The format is quite flexible, allowing the
storage of monaural or multichannel sampled sounds at a variety of sample
rates and sample widths.

Audio IFF conforms to the "EA IFF 85: Standard for Interchange Format
Files" developed by Electronic Arts.

Audio IFF is primarily an interchange format, although application
designers should find it flexible enough to use as a data storage format
as well.  If an application does choose to use a different storage format,
it should be able to convert to and from the format defined in this
document.  This ability to convert will facilitate the sharing of sound
data between applications.

Audio IFF is the result of several meetings held with music developers
over a period of ten months during 1987 and 1988.  Apple Computer greatly
appreciates the comments and cooperation provided by all developers who
helped define this standard.

Another "EA IFF 85" sound storage format is "8SVX IFF 8-bit Sampled
Voice", by Electronic Arts.  '8SVX', which handles eight-bit monaural
samples, is intended mainly for storing sound for playback on personal
computers.  Audio IFF is intended for use with a larger variety of
computers, sampled sound instruments, sound software applications, and
high fidelity recording devices.

 [Data Types](devices/aiff-doc-aiff-data-types.md)                              [The Marker Chunk](devices/aiff-doc-aiff-the-marker-chunk.md) 
 [Constants](devices/aiff-doc-aiff-constants.md)                               [The Instrument Chunk](devices/aiff-doc-aiff-the-instrument-chunk.md) 
 [Data Organization](devices/aiff-doc-aiff-data-organization.md)                       [The MIDI Data Chunk](devices/aiff-doc-aiff-the-midi-data-chunk.md) 
 [Referring to Audio IFF](devices/aiff-doc-aiff-referring-to-audio-iff.md)                  [Audio Recording Chunk](devices/aiff-doc-aiff-the-audio-recording-chunk.md) 
 [File Structure](devices/aiff-doc-aiff-file-structure.md)                          [Application Specific Chunk](devices/aiff-doc-aiff-the-application-specific-chunk.md) 
 [Storage of AIFF on Other Platforms](devices/aiff-doc-aiff-storage-of-aiff-on-apple-and-other-platforms.md)      [The Comments Chunk](devices/aiff-doc-aiff-the-comments-chunk.md) 
 [Local Chunk Types](devices/aiff-doc-aiff-local-chunk-types.md)                       [Text Chunks](devices/aiff-doc-aiff-the-text-chunks-name-author-copyright.md) 
 [Sample Points and Sample Frames](devices/aiff-doc-aiff-sample-points-and-sample-frames.md)         [Chunk Precedence](devices/aiff-doc-aiff-chunk-precedence.md) 
 [Block Aligning Sound Data](devices/aiff-doc-aiff-block-aligning-sound-data.md)               [Further Reference](devices/aiff-doc-aiff-further-reference.md) 

