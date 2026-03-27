---
title: AIFF.doc / AIFF / The MIDI Data Chunk
manual: devices
chapter: devices
section: aiff-doc-aiff-the-midi-data-chunk
functions: []
libraries: []
---

# AIFF.doc / AIFF / The MIDI Data Chunk

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The MIDI Data Chunk can be used to store MIDI data.  Please refer to
Musical Instrument Digital Interface Specification 1.0, available from the
International MIDI Association, for more details on MIDI.

The primary purpose of this chunk is to store MIDI System Exclusive
messages, although other types of MIDI data can be stored in the block as
well.  As more instruments come to market, they will likely have
parameters that have not been included in the Audio IFF specification.
The MIDI System Exclusive messages for these instruments may contain many
parameters that are not included in the Instrument Chunk.  For example, a
new sampling instrument may have more than the two loops defined in the
Instrument Chunk.  These loops will likely be represented in the MIDI
System Exclusive message for the new machine.  This MIDI System Exclusive
message can be stored in the MIDI Data Chunk.

```c
    #define		MIDIDataID   'MIDI' /* ckID for MIDI Data Chunk */

    typedef struct {
```
	ID		ckID;
	long		ckSize;

	unsigned char	MIDIdata[];

```c
    } MIDIDataChunk;
```
The ckID is always 'MIDI'.  ckSize of the data portion of the chunk, in
bytes. It does not include the 8 bytes used by ckID and ckSize.

The MIDIData field contains a stream of MIDI data.

The MIDI Data Chunk is optional.  Any number of MIDI Data Chunks may exist
in a FORM AIFF.  If MIDI System Exclusive messages for several instruments
are to be stored in a FORM AIFF, it is better to use one MIDI Data Chunk
per instrument than one big MIDI Data Chunk for all of the instruments.

