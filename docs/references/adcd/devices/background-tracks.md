---
title: Background / Tracks
manual: devices
chapter: devices
section: background-tracks
functions: []
libraries: []
---

# Background / Tracks

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The events in a [SMUS](devices/smus-iff-simple-musical-score-introduction.md) score are grouped into parallel "tracks".  Each track
is a linear stream of events.

Why use tracks?  Tracks serve 4 functions:

  1. Tracks make it possible to encode event delays very compactly.  A

```c
     "classical" score has chorded notes and sequential notes; no
     overlapping notes.  That is, each event begins either simultaneous
     with or immediately following the previous event in that track.  So
     each event delay is either 0 or the same as the event's duration.
     This binary distinction requires only one bit of storage.
```
  2. Tracks represent the "voice tracks" in Common Music Notation.  CMN

```c
     organizes a score in parallel staves, with one or two "voice tracks"
     per staff.  So one or two [SMUS](devices/smus-iff-simple-musical-score-introduction.md) tracks represents a
     CMN staff.
```
  3. Tracks are a good match to available sound hardware.  We can use

     "instrument settings" in a track to store the timbre assignments for
     that track's notes.  The instrument setting may change over the track.

     Furthermore, tracks can help to allocate notes among available output
     channels or performance devices or tape recorder "tracks".  Tracks can
     also help to adapt polyphonic data to monophonic output channels.
  4. Tracks are a good match to simple sound software.  Each track is a

```c
     place to hold state settings like "dynamic mark pp ", "time signature
     3/4", "mute this track", etc., just as it's a context for instrument
     settings.  This is a lot like a text stream with running "font" and
     "face" properties (attributes).  Running state is usually more compact
     than, say, storing an instrument setting in every note event.  It's
     also a useful way to organize "attributes" of notes.  With "running
     track state" we can define new note attributes in an upward- and
     backward-compatible way.

     Running track state can be expanded (run decoded) while loading a
     track into memory or while playing the track.  The runtime track
     state must be reinitialized every time the score is played.
```
Separated vs. interleaved tracks.  Multi-track data could be stored either
as separate event streams or interleaved into one stream.  To interleave
the streams, each event has to carry a "track number" attribute.

If we were designing an editable score format, we might interleave the
streams so that nearby events are stored nearby.  This helps when
searching the data, especially if you can't fit the entire score into
memory at once.  But it takes extra storage for the track numbers and may
take extra work to manipulate the interleaved tracks.

The musical score format FORM [SMUS](devices/smus-iff-simple-musical-score-introduction.md) is intended for simple loading and
playback of small scores that fit entirely in main memory.  So we chose to
store its tracks separately.

There can be up to 255 tracks in a FORM [SMUS](devices/smus-iff-simple-musical-score-introduction.md).  Each track is stored as a
[TRAK](devices/standard-data-and-property-chunks-data-chunk-trak.md) chunk.  The count of tracks (the number of TRAK chunks) is recorded
in the [SHDR](devices/standard-data-and-property-chunks-required-property-shdr.md) chunk at the beginning of the FORM [SMUS](devices/smus-iff-simple-musical-score-introduction.md).  The TRAK chunks
appear in numerical order 1, 2, 3, ....  This is also priority order, most
important track first. A player program that can handle up to N parallel
tracks should read the first N tracks and ignore any others.

The different tracks in a score may have different lengths.  This is true
both of storage length and of playback duration.

