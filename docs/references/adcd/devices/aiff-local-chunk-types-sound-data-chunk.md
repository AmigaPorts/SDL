---
title: AIFF / Local Chunk Types / Sound Data Chunk
manual: devices
chapter: devices
section: aiff-local-chunk-types-sound-data-chunk
functions: []
libraries: []
---

# AIFF / Local Chunk Types / Sound Data Chunk

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Sound Data Chunk contains the actual sample frames.

```c
    #define 	SoundDataID	'SSND'	/* ckID for Sound Data Chunk 	*/

    typedef struct {
```
	ID		ckID;
	long		ckSize;

	unsigned long	offset;
	unsigned long	blockSize;
	unsigned char	SoundData [];

```c
    }  SoundDataChunk;
```
The ckID is always 'SSND'.  The ckSize is the size of the data portion of
the chunk, in bytes.  It does not include the 8 bytes used by ckID and
ckSize.

The offset field determines where the first sample frame in the soundData
starts.  The offset is in bytes.  Most applications won't use offset and
should set it to zero.  Use for a non-zero offset is explained in the
Block-Aligning Sound Data section below.

The blockSize is used in conjunction with offset for block-aligning sound
data.  It contains the size in bytes of the blocks that sound data is
aligned to.  As with offset, most applications won't use blockSize and
should set it to zero.  More information on blockSize is in the
Block-Aligning Sound Data section below.

The soundData field contains the sample frames that make up the sound.
The number of sample frames in the soundData is determined by the
numSampleFrames field in the Common Chunk.  Sample points and sample
frames are explained in detail in the next section.

The Sound Data Chunk is required unless the numSampleFrames field in the
Common Chunk is zero.  A maximum of one Sound Data Chunk may appear in a
FORM AIFF.

