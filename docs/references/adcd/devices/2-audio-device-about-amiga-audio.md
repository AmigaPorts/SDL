---
title: 2 Audio Device / About Amiga Audio
manual: devices
chapter: devices
section: 2-audio-device-about-amiga-audio
functions: []
libraries: []
---

# 2 Audio Device / About Amiga Audio

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Most personal computers that produce sound have hardware designed for one
specific synthesis technique. The Amiga computer uses a very general
method of digital sound synthesis that is quite similar to the method used
in digital hi-fi components and state-of-the-art keyboard and drum
synthesizers.

For programs that can afford the memory, playing sampled sounds gives you
a simple and very CPU-efficient method of sound synthesis.  A sampled
sound is a table of numbers which represents a sound digitally. When the
sound is played back by the Amiga, the table is fed by a DMA channel into
one of the four digital-to-analog converters in the custom chips. The
digital-to-analog converter converts the samples into voltages that can be
played through amplifiers and loudspeakers, reproducing the sound.

On the Amiga you can create sound data in many other ways. For instance,
you can use trigonometric functions in your programs to create the more
traditional sounds - sine waves, square waves, or triangle waves - by
using tables that describe their shapes. Then you can combine these waves
for richer sound effects by adding the tables together. Once the data are
entered, you can modify them with techniques described below. For
information about the limitations of the audio hardware and suggestions
for improving system efficiency and sound quality, refer to the Amiga
[Hardware Reference Manual](hardware/5-audio-hardware-producing-high-quality-sound.md).

Some commands enable your program to co-reside with other programs using
the audio device at the same time. Programs can co-reside because the
audio device handles allocation of audio channels and arbitrates among
programs competing for the same resources.  When properly used, this
allows many programs to use the audio device simultaneously.

The audio device commands help isolate the programmer from the
idiosyncrasies of the custom chip hardware and make it easier to use. But
you can also produce sound on the Amiga by directly accessing the hardware
registers if you temporarily lock out other users first.  For certain
types of sound synthesis, this is more CPU-efficient.

 [Definitions](devices/2-about-amiga-audio-definitions.md) 

