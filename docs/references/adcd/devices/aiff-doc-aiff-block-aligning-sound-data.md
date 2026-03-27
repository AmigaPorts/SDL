---
title: AIFF.doc / AIFF / Block-Aligning Sound Data
manual: devices
chapter: devices
section: aiff-doc-aiff-block-aligning-sound-data
functions: []
libraries: []
---

# AIFF.doc / AIFF / Block-Aligning Sound Data

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

There may be some applications that, to ensure real time recording and
playback of audio, wish to align sampled sound data with fixed-size
blocks. This alignment can be accomplished with the offset and blockSize
parameters of the Sound Data Chunk, as shown in Figure 7.


        ____________ __________________________________ ____________
       |\\ unused \\|          sample frames           |\\ unused \\|
       |____________|__________________________________|____________|
       <-- offset --><- numSampleFrames sample frames ->

    |   blockSize   |               |               |               |
    |<- bytes     ->|               |               |               |
    |_______________|_______________|_______________|_______________|
       block N-1       block N         block N+1       block N+2

                     Figure 7: Block-Aligned Sound Data
In Figure 7, the first sample frame starts at the beginning of block N.
This is accomplished by skipping the first offset bytes of the soundData.
Note too, that the soundData bytes can extend beyond valid sample frames,
allowing the soundData bytes to end on a block boundary as well.

The blockSize specifies the size in bytes of the block to which you would
align the sound data.  A blockSize of zero indicates that the sound data
does not need to be block-aligned.  Applications that don't care about
block alignment should set the blockSize and offset to zero when creating
Audio IFF files.  Applications that write block-aligned sound data should
set blockSize to the appropriate block size.  Applications that modify an
existing Audio IFF file should try to preserve alignment of the sound
data, although this is not required.  If an application does not preserve
alignment, it should set the blockSize and offset to zero.  If an
application needs to realign sound data to a different sized block, it
should update blockSize and offset accordingly.

