---
title: Standard Data and Property Chunks / Set MIDI Channel SEvent
manual: devices
chapter: devices
section: standard-data-and-property-chunks-set-midi-channel-sevent
functions: []
libraries: []
---

# Standard Data and Property Chunks / Set MIDI Channel SEvent

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [SEvent](devices/standard-data-and-property-chunks-data-chunk-trak.md) SID_MIDI_Chnl is for recorder programs to record the
set-MIDI-channel low level event.  The data byte contains a MIDI channel
number.  Other programs should use [instrument registers](devices/background-instrument-registers.md) instead.

