---
title: SMUS IFF Simple Musical Score / Introduction
manual: devices
chapter: devices
section: smus-iff-simple-musical-score-introduction
functions: []
libraries: []
---

# SMUS IFF Simple Musical Score / Introduction

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This is a reference manual for the data interchange format "SMUS", which
stands for Simple MUsical Score.  "[EA IFF 85](devices/a-quick-introduction-to-iff-what-is-iff.md)" is Electronic Arts' standard
for interchange format files.  A [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md) or "data section") such as FORM SMUS
can be an IFF file or a part of one.  [See "[EA IFF 85](devices/a-quick-introduction-to-iff-what-is-iff.md)" Electronic Arts
Interchange File Format.]

SMUS is a practical data format for uses like moving limited scores
between programs and storing theme songs for game programs.  The format
should be geared for easy read-in and playback.  So FORM SMUS uses the
compact time encoding of Common Music Notation (half notes, dotted quarter
rests, etc.). The SMUS format should also be structurally simple.  So it
has no provisions for fancy notational information needed by graphical
score editors or the more general timing (overlapping notes, etc.) and
continuous data (pitch bends, etc.) needed by performance-oriented MIDI
recorders and sequencers.  Complex music programs may wish to save in a
more complete format, but still import and export SMUS when requested.

A SMUS score can say which "instruments" are supposed play which notes.
But the score is independent of whatever output device and driver software
is used to perform the notes.  The score can contain device- and
driver-dependent instrument data, but this is just a cache.  As long as a
SMUS file stays in one environment, the embedded instrument data is very
convenient.  When you move a SMUS file between programs or hardware
configurations, the contents of this cache usually become useless.

Like all IFF formats, SMUS is a filed or "archive" format.  It is
completely independent of score representations in working memory, editing
operations, user interface, display graphics, computation hardware, and
sound hardware. Like all IFF formats, SMUS is extensible.

SMUS is not an end-all musical score format.  Other formats may be more
appropriate for certain uses.  (We'd like to design an general-use IFF
score format "GSCR".  FORM GSCR would encode fancy notational data and
performance data.  There would be a SMUS to/from GSCR converter.)

Section 2 gives important [background](devices/smus-iff-simple-musical-score-background.md) information.  Section 3 details the
SMUS components by defining the required property score header "[SHDR](devices/standard-data-and-property-chunks-required-property-shdr.md)", the
optional text properties name "NAME", copyright "(c) ", and author "AUTH",
optional text annotation "ANNO", the optional instrument specifier "INS1",
and the track data chunk "[TRAK](devices/standard-data-and-property-chunks-data-chunk-trak.md)".  Section 4 defines some chunks for
particular programs to store [private information](devices/smus-iff-simple-musical-score-private-chunks.md).  These are "standard"
chunks; specialized chunks for future needs can be added later.  [Appendix](devices/smus-iff-simple-musical-score-appendix-a-quick-reference.md)
A is a quick-reference summary. [Appendix B](devices/smus-iff-simple-musical-score-appendix-b-smus-example.md) is an example box diagram.
[Appendix C](devices/smus-iff-simple-musical-score-appendix-c-standards-committee.md) names the committee responsible for this standard.

 [References](devices/smus-iff-simple-musical-score-introduction-references.md) 

