---
title: AIFF / The Instrument Chunk / Looping
manual: devices
chapter: devices
section: aiff-the-instrument-chunk-looping
functions: []
libraries: []
---

# AIFF / The Instrument Chunk / Looping

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Sound data can be looped, allowing a portion of the sound to be repeated
in order to lengthen the sound.  The structure below describes a loop.

```c
    typedef struct {
```
	short	PlayMode;
	MarkerId beginLoop;
	MarkerId endLoop;

```c
    } Loop;
```
A loop is marked with two points, a begin position and an end position.
There are two ways to play a loop, forward looping and forward/backward
looping. In the case of forward looping, playback begins at the beginning
of the sound, continues past the begin position and continues to the end
position, at which point playback starts again at the begin position.  The
segment between the begin and end positions, called the loop segment, is
played repeatedly until interrupted by a user action, such as the release
of a key on a sampling instrument.


                   ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___
    sample frames |   |   |   |<--- loop segment ---->|   |   |   |
                  |___|___|___|___|___|___|___|___|___|___|___|___|
                              ^                       ^
                        begin position           end position

                        Figure 9: Sample Frame Looping
With forward/backward looping, the loop segment is first played from the
begin position to the end position, and then played backwards from the end
position to the begin position.  This flip-flop pattern is repeated over
and over again until interrupted.

The playMode specifies which type of looping is to be performed:

	#define NoLooping		0
	#define ForwardLooping		1
	#define ForwardBackwardLooping  2

If NoLooping is specified, then the loop points are ignored during
playback.

The beginLoop is a marker id that marks the begin position of the loop
segment.

The endLoop marks the end position of a loop.  The begin position must be
less than the end position.  If this is not the case, then the loop
segment has zero or negative length and no looping takes place.

