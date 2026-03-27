---
title: AIFF / The Marker Chunk / Marker Chunk Format
manual: devices
chapter: devices
section: aiff-the-marker-chunk-marker-chunk-format
functions: []
libraries: []
---

# AIFF / The Marker Chunk / Marker Chunk Format

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The format for the data within a Marker Chunk is shown below.

```c
    #define	MarkerID 	'MARK'	/* ckID for Marker Chunk */

    typedef  struct {
```
	ID				ckID;
	long				ckSize;

	unsigned short		numMarkers;
	Marker			Markers [];

```c
    } MarkerChunk;
```
The ckID is always 'MARK'.  The ckSize is the size of the data portion of
the chunk in bytes.  It does not include the 8 bytes used by ckID and
ckSize.

The numMarkers field is the number of markers in the Marker Chunk.  If
numMarkers is non-zero, it is followed by the markers themselves.  Because
all fields in a marker are an even number of bytes, the length of any
marker will always be even.  Thus, markers are packed together with no
unused bytes between them.  The markers need not be ordered in any
particular manner.

The Marker Chunk is optional.  No more than one Marker Chunk can appear in
a FORM AIFF.

