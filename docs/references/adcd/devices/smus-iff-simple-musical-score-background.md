---
title: SMUS IFF Simple Musical Score / Background
manual: devices
chapter: devices
section: smus-iff-simple-musical-score-background
functions: []
libraries: []
---

# SMUS IFF Simple Musical Score / Background

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Here's some background information on score representation in general and
design choices for [SMUS](devices/smus-iff-simple-musical-score-introduction.md).

First, we'll borrow some terminology from the Structured Sound Synthesis
Project.  [See the [SSSP reference](devices/smus-iff-simple-musical-score-introduction-references.md).]  A "musical note" is one kind of
scheduled event.  Its properties include an event duration, an event
delay, and a timbre object.  The event duration tells the scheduler how
long the note should last. The event delay tells how long after starting
this note to wait before starting the next event.  The timbre object
selects sound driver data for the note; an "instrument" or "timbre".  A
"rest" is a sort of a null event.  Its only property is an event delay.

 [Classical Event Durations](devices/background-classical-event-durations.md) 
 [Tracks](devices/background-tracks.md) 
 [Instrument Registers](devices/background-instrument-registers.md) 
 [MIDI Instruments](devices/background-midi-instruments.md) 

