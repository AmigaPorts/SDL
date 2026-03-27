---
title: Standard Data and Property Chunks / Background
manual: devices
chapter: devices
section: standard-data-and-property-chunks-background
functions: []
libraries: []
---

# Standard Data and Property Chunks / Background

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

There are two ways to use [FORM 8SVX](devices/8svx-iff-8-bit-sampled-voice-introduction.md): as a one-shot sampled sound or as a
sampled musical instrument that plays "notes".  Storing both kinds of
sounds in the same kind of [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md) makes it easy to play a one-shot sound as
an instrument or an instrument as a one-note sound.

A one-shot sound is a series of audio data samples with a nominal playback
rate and amplitude.  The recipient program can optionally adjust or
modulate the amplitude and playback data rate.

For musical instruments, the idea is to store a sampled (or
pre-synthesized) waveform that will be parameterized by pitch, duration,
and amplitude to play each "note".  The creator of the [FORM 8SVX](devices/8svx-iff-8-bit-sampled-voice-introduction.md) can
supply a waveform per octave over a range of octaves for this purpose.
The intent is to perform a pitch by selecting the closest octave's
waveform and scaling the playback data rate. An optional "one-shot"
waveform supplies an arbitrary startup transient, then a "repeat" waveform
is iterated as long as necessary to sustain the note.

A [FORM 8SVX](devices/8svx-iff-8-bit-sampled-voice-introduction.md) can also store an envelope to modulate the waveform.
Envelopes are mostly useful for variable-duration notes but could be used
for one-shot sounds, too.

The [FORM 8SVX](devices/8svx-iff-8-bit-sampled-voice-introduction.md) standard has some restrictions.  For example, each octave of
data must be twice as long as the next higher octave.  Most sound driver
software and hardware imposes additional restrictions.  E.g., the Amiga
sound hardware requires an even number of samples in each one-shot and
repeat waveform.

