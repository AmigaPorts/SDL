---
title: AIFF / Local Chunk Types / The Common Chunk
manual: devices
chapter: devices
section: aiff-local-chunk-types-the-common-chunk
functions: []
libraries: []
---

# AIFF / Local Chunk Types / The Common Chunk

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Common Chunk describes fundamental parameters of the sampled sound.

```c
    #define	CommonID	'COMM'	/* ckID for Common Chunk */

    typedef struct {
```
	ID		ckID;
	long		ckSize;

	short		numChannels;
	unsigned long	numSampleFrames;
	short		sampleSize;
	extended	sampleRate;

```c
    } CommonChunk;
```
The ckID is always 'COMM'.  The ckSize is the size of the data portion of
the chunk, in bytes.  It does not include the 8 bytes used by ckID and
ckSize. For the Common Chunk, ckSize is always 18.

The numChannels field contains the number of audio channels for the sound.
A value of 1 means monophonic sound, 2 means stereo, and 4 means four
channel sound, etc.  Any number of audio channels may be represented.  For
multichannel sounds, single sample points from each channel are
interleaved. A set of interleaved sample points is called a sample frame.

The actual sound samples are stored in another chunk, the Sound Data
Chunk, which will be described shortly.

Single sample points from each channel are interleaved such that each
sample frame is a sample point from the same moment in time for each
channel available.

The numSampleFrames field contains the number of sample frames.  This is
not necessarily the same as the number of bytes nor the number of
samplepoints in the Sound Data Chunk.  The total number of sample points
in the file is numSampleFrames times numChannels.

The sampleSize is the number of bits in each sample point.  It can be any
number from 1 to 32.  The format of a sample point will be described in
the next section.

The sampleRate field is the sample rate at which the sound is to be played
back in sample frames per second.

One, and only one, Common Chunk is required in every FORM AIFF.

