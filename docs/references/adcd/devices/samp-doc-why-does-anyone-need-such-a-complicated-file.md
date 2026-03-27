---
title: SAMP.doc / Why Does Anyone Need Such a Complicated File?
manual: devices
chapter: devices
section: samp-doc-why-does-anyone-need-such-a-complicated-file
functions: []
libraries: []
---

# SAMP.doc / Why Does Anyone Need Such a Complicated File?

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
                 (or "What's wrong with 8SVX anyway?")
```
In a nutshell, 8SVX is not adequate for professional music sampling. First
of all, it is nearly impossible to use multi-sampling (utilizing several,
different samples of any instrument throughout its musical range). This
very reason alone makes it impossible to realistically reproduce a musical
in- strument, as none in existance (aside from an electronic organ) uses
inter- polations of a single wave to create its musical note range.

Also, stretching a sample out over an entire octave range does grotesque
(and VERY unmusical) things to such elements as the overtone structure,
wind/percussive noises, the instrument's amplitude envelope, etc. The 8SVX
format is designed to stretch the playback in exactly this manner.

8SVX ignores MIDI which is the de facto standard of musical data
transmission. 8SVX does not allow storing data for features that are
commonplace to pro- fessional music samplers. Such features are: velocity
sample start, separate filter and envelopes for each sample, separate
sampling rates, and various playback modes like stereo sampling and
panning.

SAMP attempts to remedy all of these problems with a format that can be
used by a program that simulates these professional features in software.
The format was inspired by the capabilities of the following musical
products:


    EMU's                 EMAX, EMULATOR
    SEQUENTIAL CIRCUIT's  PROPHET 2000, STUDIO 440
    ENSONIQ's             MIRAGE
    CASIO's               FZ-1
    OBERHEIM's            DPX
    YAMAHA                TX series
So why does the Amiga need the SAMP format? Because professional
musician's are buying computers. With the firm establishment of MIDI,
musician's are buying and using a variety of sequencers, patch editors,
and scoring programs. It is now common knowledge amoung professional
musicians that the Amiga lags far behind IBM clones, Macintosh, and Atari
ST computers in both music software and hardware support. Both Commodore
and the current crop of short- sighted 3rd party Amiga developers are
pigeon-holing the Amiga as "a video computer". It is important for music
software to exploit whatever capabili- ties the Amiga offers before the
paint and animation programs, genlocks, frame-grabbers, and video
breadboxes are the only applications selling for the Amiga. Hopefully,
this format, with the SAMP disk I/O library will make it possible for
Amiga software to attain the level of professionalism that the other
machines now boast, and the Amiga lacks.

