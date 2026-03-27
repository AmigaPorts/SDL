---
title: Standard Data and Property Chunks / More SEvents To Be Defined
manual: devices
chapter: devices
section: standard-data-and-property-chunks-more-sevents-to-be-defined
functions: []
libraries: []
---

# Standard Data and Property Chunks / More SEvents To Be Defined

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

More [SEvent](devices/standard-data-and-property-chunks-data-chunk-trak.md)s can be defined in the future.  The sID codes 133 through 143
and 160 through 254 are reserved for future needs.  Caution: sID codes
must be allocated by a central "clearinghouse" to avoid conflicts.

The following [SEvent](devices/standard-data-and-property-chunks-data-chunk-trak.md) types are under consideration and should not yet be
used.

Issue: A "change tempo" [SEvent](devices/standard-data-and-property-chunks-data-chunk-trak.md) changes tempo during a score.  Changing the
tempo affects all tracks, not just the track containing the change tempo
event.

One possibility is a "scale tempo" [SEvent](devices/standard-data-and-property-chunks-data-chunk-trak.md) SID_ScaleTempo that rescales the
global tempo:

	currentTempo := globalTempo * (data + 1) / 128

This can scale the global tempo (in the [SHDR](devices/standard-data-and-property-chunks-required-property-shdr.md)) anywhere from x1/128 to x2
in roughly 1% increments.

An alternative is two events SID_SetHTempo and SID_SetLTempo.
SID_SetHTempo gives the high byte and SID_SetLTempo gives the low byte of
a new tempo setting, in 128ths quarter note/minute.  SetHTempo
automatically sets the low byte to 0, so the SetLTempo event isn't needed
for coarse settings.  In this scheme, the [SHDR](devices/standard-data-and-property-chunks-required-property-shdr.md)'s tempo is simply a
starting tempo.

An advantage of SID_ScaleTempo is that the playback program can just alter
the global tempo to adjust the overall performance time and still easily
implement tempo variations during the score.  But the "set tempo" [SEvent](devices/standard-data-and-property-chunks-data-chunk-trak.md)
may be simpler to generate.

Issue: The events SID_BeginRepeat and SID_EndRepeat define a repeat span
for one track.  The span of events between a BeginRepeat and an EndRepeat
is played twice.  The SEvent.data field in the BeginRepeat event could
give an iteration count, 1 through 255 times or 0 for "repeat forever". 

Repeat spans can be nested.  All repeat spans automatically end at the end
of the track.

An event SID_Ending begins a section like "first ending" or "second
ending". The SEvent.data field gives the ending number.  This SID_Ending
event only applies to the innermost repeat group.  (Consider generalizing
it.)

A more general alternative is a "subtrack" or "subscore" event.  A
"subtrack" event is essentially a "subroutine call" to another series of
[SEvent](devices/standard-data-and-property-chunks-data-chunk-trak.md)s.  This is a nice way to encode all the possible variations
of repeats, first endings, codas, and such.

To define a subtrack, we must demark its start and end.  One possibility
is to define a relative branch-to-subtrack event SID_BSR and a
return-from-subtrack event SID_RTS.  The 8-bit data field in the SID_BSR
event can reach as far as 512 [SEvent](devices/standard-data-and-property-chunks-data-chunk-trak.md)s.  A second possibility is to call a
subtrack by index number, with an IFF chunk outside the [TRAK](devices/standard-data-and-property-chunks-data-chunk-trak.md) defining the
start and end of all subtracks. This is very general since a portion of
one subtrack can be used as another subtrack.  It also models the tape
recording practice of first "laying down a track" and then selecting
portions of it to play and repeat.  To embody the music theory idea of
playing a sequence like "ABBA", just compose the "main" track entirely of
subtrack events.  A third possibility is to use a numbered subtrack chunk
"STRK" for each subroutine.

