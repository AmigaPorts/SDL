---
title: A / IFF Third Party Public Form and Chunk Specification / 8SVX.CHAN.PAN.doc
manual: devices
chapter: devices
section: a-iff-third-party-public-form-and-chunk-specification-8svx
functions: []
libraries: []
---

# A / IFF Third Party Public Form and Chunk Specification / 8SVX.CHAN.PAN.doc

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Stereo chunks for 8SVX form


                     SMUS.CHAN and SMUS.PAN Chunks
            Stereo imaging in the "8SVX" IFF 8-bit Sample Voice
            ---------------------------------------------------
                 Registered by David Jones, Gold Disk Inc.
There are two ways to create stereo imaging when playing back a digitized
sound. The first relies on the original sound being created with a stereo
sampler: two different samples are digitized simultaneously, using right
and left inputs. To play back this type of sample while maintaining the
stereo imaging, both channels must be set to the same volume. The second
type of stereo sound plays the identical information on two different
channels at different volumes. This gives the sample an absolute position
in the stereo field. Unfortunately, there are currently a number of
methods for doing this currently implemented on the Amiga, none truly
adhering to any type of standard. What I have tried to to is provide a way
of doing this consistently, while retaining compatibility with existing
(non-standard) systems. Introduced below are two optional data chunks,
CHAN and PAN. CHAN deals with sounds sampled in stereo, and PAN with
samples given stereo characteristics after the fact.

 [Optional Data Chunk CHAN](devices/8svx-chan-pan-doc-optional-data-chunk-chan.md) 
 [Optional Data Chunk PAN](devices/8svx-chan-pan-doc-optional-data-chunk-pan.md) 

