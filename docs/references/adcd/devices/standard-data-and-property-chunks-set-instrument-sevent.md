---
title: Standard Data and Property Chunks / Set Instrument SEvent
manual: devices
chapter: devices
section: standard-data-and-property-chunks-set-instrument-sevent
functions: []
libraries: []
---

# Standard Data and Property Chunks / Set Instrument SEvent

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

One of the running state variables of every track is an instrument number.
An instrument number is the array index of an "instrument register", which
in turn points to an instrument.  (See "[Instrument Registers](devices/background-instrument-registers.md)", in section
2.) This is like a color number in a bitmap; a reference to a color
through a "color register".

The initial setting for each track's instrument number is the track
number. Track 1 is set to instrument 1, etc.  Each time the score is
played, every track's instrument number should be reset to the track
number.

The [SEvent](devices/standard-data-and-property-chunks-data-chunk-trak.md) SID_Instrument changes the instrument number for a track, that
is, which instrument plays the following notes.  Its SEvent.data field is
an instrument register number in the range 0 through 255.  If a program
doesn't implement the SID_Instrument event, each track is fixed to one
instrument.

