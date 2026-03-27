---
title: Background / Classical Event Durations
manual: devices
chapter: devices
section: background-classical-event-durations
functions: []
libraries: []
---

# Background / Classical Event Durations

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[SMUS](devices/smus-iff-simple-musical-score-introduction.md) is geared for "classical" scores, not free-form performances.  So its
event durations are classical (whole note, dotted quarter rest, etc.).
SMUS can tie notes together to build a "note event" with an unusual event
duration. The set of useful classical durations is very small.  So SMUS
needs only a handful of bits to encode an event duration.  This is very
compact.  It's also very easy to display in Common Music Notation (CMN).

