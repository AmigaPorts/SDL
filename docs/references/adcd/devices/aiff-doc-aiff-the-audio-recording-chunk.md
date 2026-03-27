---
title: AIFF.doc / AIFF / The Audio Recording Chunk
manual: devices
chapter: devices
section: aiff-doc-aiff-the-audio-recording-chunk
functions: []
libraries: []
---

# AIFF.doc / AIFF / The Audio Recording Chunk

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Audio Recording Chunk contains information pertinent to audio
recording devices.


```c
    #define     AudioRecordingID 'AESD'  /* ckID for Audio Recording */
                                         /*  Chunk.                 */
    typedef struct {
        ID                      ckID
        long                    ckSize;

        unsigned char   AESChannelStatusData[24];
    } AudioRecordingChunk;
```
The ckID is always 'AESD'. The ckSize is the size of the data portion of
the chunk, in bytes For the Audio Recording Chunk, ckSize is always 24.

The 24 bytes of AESCChannelStatusData are specified in the "AES
Recommended Practice for Digital Audio Engineering - Serial Transmission
Format for Linearly Represented Digital Audio Data", transmission of
digital audio between audio devices.  This information is duplicated in
the Audio Recording Chunk for convenience.  Of general interest would be
bits 2, 3, and 4 of byte 0, which describe recording emphasis.

The Audio Recording Chunk is optional.  No more than one Audio Recording
Chunk may appear in a FORM AIFF.

