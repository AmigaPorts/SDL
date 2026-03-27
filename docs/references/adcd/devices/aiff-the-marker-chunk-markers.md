---
title: AIFF / The Marker Chunk / Markers
manual: devices
chapter: devices
section: aiff-the-marker-chunk-markers
functions: []
libraries: []
---

# AIFF / The Marker Chunk / Markers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A marker has the following format.

```c
    typedef	short		MarkerId;

    typedef	struct	{
```
		MarkerID	id;
		unsigned long	position;
		pstring		markerName;

```c
    } Marker;
```
The id is a number that uniquely identifies that marker within a FORM
AIFF. The id can be any positive non-zero integer, as long as no other
marker within the same FORM AIFF has the same id.

The marker's position in the sound data is determined by the position
field. Markers conceptually fall between two sample frames.  A marker that
falls before the first sample frame in the sound data is at position zero,
while a marker that falls between the first and second sample frame in the
sound data is at position 1.  Note that the units for position  are sample
frames, not bytes nor sample points.


                              Sample Frames
             ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___
            |   |   |   |   |   |   |   |   |   |   |   |   |
            |___|___|___|___|___|___|___|___|___|___|___|___|
            ^                   ^                           ^
        position 0          position 5                  position 12

                 Figure 8: Sample Frame Marker Positions
The markerName field is a Pascal-style text string containing the name of
the mark.

Note: Some "EA IFF 85" files store strings a C-strings (text bytes
followed by a null terminating character) instead of Pascal-style strings.
Audio IFF uses pstrings because they are more efficiently skipped over
when scanning through chunks.  Using pstrings, a program can skip over a
string by adding the string count to the address of the first character.
C strings require that each character in the string be examined for the
null terminator.

