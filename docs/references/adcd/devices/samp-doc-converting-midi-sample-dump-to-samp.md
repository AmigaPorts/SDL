---
title: SAMP.doc / Converting Midi Sample Dump to SAMP
manual: devices
chapter: devices
section: samp-doc-converting-midi-sample-dump-to-samp
functions: []
libraries: []
---

# SAMP.doc / Converting Midi Sample Dump to SAMP

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

SEMANTICS: When MIDI literature talks about a sample, usually it means a
collection of many sample points that make up what we call "a wave".
Therefore, a Midi Sample Dump sends all the sample data that makes up ONE
wave. A SAMP file is designed to hold up to 255 of these waves (midi
dumps).

The Midi Sample Dump specifies playback rate only in terms of a sample
PERIOD in nanoseconds. SAMP also expresses playback in terms of samples
per second (frequency). The Amiga needs to see its period rounded to the
nearest microsecond. If you take the sample period field of a Midi sample
Dump (the 8th, 9th, and 10th bytes of the Dump Header LSB first) which we
will call MidiSamplePer, and the Rate of a SAMP file, here is the
relationship:

   Rate = (1/MidiSamplePer) x 10E9

Also the number of samples (wave's length) in a Midi Sample Dump (the
11th, 12th, and 13th bytes of the Dump header) is expressed in WORDS.
SAMP's WaveSize is expressed in the number of BYTES. (For the incredibly
stupid), the relationship is:

   WaveSize = MidiSampleLength x 2

A Midi sample dump's LoopStart point and LoopEnd point are also in WORDS
as versus the SAMP equivalents expressed in BYTES.

A Midi sample dump's sample number can be 0 to 65535. A SAMP file can hold
up to 255 waves, and their numbers in the playmap must be 1 to 255. (A
single, Midi Sample Dump only sends info on one wave.) When recieving a
Midi Sample Dump, just store the sample number (5th and 6th bytes of the
Dump Header LSB first) in SAMP's MidiSampNum field. Then forget about this
number until you need to send the wave back to the Midi instrument from
whence it came.

A Midi Dump's loop type can be forward, or forward/backward. Amiga
hardware supports forward only. You should store the Midi Dump's LoopType
byte here, but ignore it otherwise until/unless Amiga hardware supports
"reading audio data" in various ways. If so, then the looptype is as
follows:


```c
    forward = 0, backward/forward = 1
```
A Midi Dump's sample format byte is the same as SAMP's.

