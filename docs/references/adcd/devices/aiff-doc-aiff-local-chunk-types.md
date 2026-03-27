---
title: AIFF.doc / AIFF / Local Chunk Types
manual: devices
chapter: devices
section: aiff-doc-aiff-local-chunk-types
functions: []
libraries: []
---

# AIFF.doc / AIFF / Local Chunk Types

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The formats of the different local chunk types found within a FORM AIFF
are described in the following sections, as are their ckIDs.

There are two types of chunks:  required and optional.  The Common Chunk
is required.  The Sound Data chunk is required if the sampled sound has a
length greater than zero.  All other chunks are optional.  All
applications that use FORM AIFF must be able to read the required chunks
and can choose to selectively ignore the optional chunks.  A program that
copies a FORM AIFF should copy all the chunks in the FORM AIFF, even those
it chooses not to interpret.

 [The Common Chunk](devices/aiff-local-chunk-types-the-common-chunk.md) 
 [Sound Data Chunk](devices/aiff-local-chunk-types-sound-data-chunk.md) 

