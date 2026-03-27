---
title: AIFF / The Instrument Chunk / The Instrument Chunk Format
manual: devices
chapter: devices
section: aiff-the-instrument-chunk-the-instrument-chunk-format
functions: []
libraries: []
---

# AIFF / The Instrument Chunk / The Instrument Chunk Format

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The format of the data within an Instrument Chunk is described below.

   #define             InstrumentID  'INST' /*ckID for Instruments Chunk */

   typedef struct {
```c
       ID              ckID;
       long            ckSize;

       char            baseNote;
       char            detune;
       char            lowNote;
       char            highNote;
       char            lowvelocity;
       char            highvelocity;
       short           gain;
       Loop            sustainLoop;
       Loop            releaseLoop;
```
   } InstrumentChunk;

The ckID is always 'INST'.  ckSize is the size of the data portion of the
chunk, in bytes.  For the Instrument Chunk, ckSize is always 20.

The baseNote is the note at which the instrument plays back the sound data
without pitch modification.  Units are MIDI (MIDI is an acronym for
Musical Instrument Digital Interface) note numbers, and are in the range 0
through 127.  Middle C is 60.

The detune field determines how much the instrument should alter the pitch
of the sound when it is played back.  Units are in cents (1/100 of a
semitone) and range from -50 to +50.  Negative numbers mean that the pitch
of the sound should be lowered, while positive numbers mean that it should
be raised.

The lowNote and highNote fields specify the suggested range on a keyboard
for playback of the sound data.  The sound data should be played if the
instrument is requested to play a note between the low and high,
inclusive.  The base note does not have to be within this range.  Units
for lowNote and highNote are MIDI note values.

The lowVelocity and highVelocity fields specify the suggested range of
velocities for playback of the sound data.  The sound data should be
played if the note-on velocity is between low and high velocity,
inclusive.  Units are MIDI velocity values, 1 (lowest velocity) through
127 (highest velocity).

The gain is the amount by which to change the gain of the sound when it is
played.  Units are decibels.  For example, 0db means no change, 6db means
double the value of each sample point, while -6db means halve the value of
each sample point.

The sustainLoop field specifies a loop that is to be played when an
instrument is sustaining a sound.

The releaseLoop field specifies a loop that is to be played when an
instrument is in the release phase of playing back a sound.  The release
phase usually occurs after a key on an instrument is released.

The Instrument Chunk is optional.  No more than one Instrument Chunk can
appear in a FORM AIFF.

ASIF Note:    The Apple IIGS Sampled Instrument Format also defines a

              chunk with ID of 'INST', which is not the same as the Audio
              IFF Instrument Chunk.  A good way to tell the two chunks
              apart in generic IFF-style readers is by the ckSize fields.
              The Audio IFF Instrument Chunk's ckSize field is always 20,
              whereas the Apple IIGS Sampled Instrument Format Instrument
              Chunk's ckSize field, for structural reasons, can never be
              20.
