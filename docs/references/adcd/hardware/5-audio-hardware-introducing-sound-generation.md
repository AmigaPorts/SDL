---
title: 5 Audio Hardware / Introducing Sound Generation
manual: hardware
chapter: hardware
section: 5-audio-hardware-introducing-sound-generation
functions: []
libraries: []
---

# 5 Audio Hardware / Introducing Sound Generation

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Sound travels through air to your ear drums as a repeated cycle of air
pressure variations, or sound waves. Sounds can be represented as graphs
that model how the air pressure varies over time. The attributes of a
sound, as you hear it, are related to the shape of the graph. If the
waveform is regular and repetitive, it will sound like a tone with steady
pitch (highness or lowness), such as a single musical note. Each
repetition of a waveform is called a cycle of the sound. If the waveform
is irregular, the sound will have little or no pitch, like a loud clash or
rushing water. How often the waveform repeats (its frequency) has an
effect upon its pitch; sounds with higher frequencies are higher in pitch.
Humans can hear sounds that have a frequency of between 20 and 20,000
cycles per second. The amplitude of the waveform (highest point on the
graph), is related to the perceived loudness of the sound. Finally, the
general shape of the waveform determines its tone quality, or timbre.
Figure 5-1 shows a particular kind of waveform, called a sine wave, that
represents one cycle of a simple tone.


```c
     [Figure 5-1: Sine Waveform](hardware/hard-pics-5-1-pic.md) 
```
In electronic sound recording and output devices, the attributes of sounds
are represented by the parameters of amplitude and frequency.  Frequency
is the number of cycles per second, and the most common unit of frequency
is the Hertz (Hz), which is 1 cycle per second.  Large values, or high
frequencies, are measured in kilohertz (KHz) or megahertz (MHz).

Frequency is strongly related to the perceived pitch of a sound.  When
frequency increases, pitch rises. This relationship is exponential. An
increase from 100 Hz to 200 Hz results in a large rise in pitch, but an
increase from 1,000 Hz to 1,100 Hz is hardly noticeable. Musical pitch is
represented in octaves. A tone that is one octave higher than another has
a frequency twice as high as that of the first tone, and its perceived
pitch is twice as high.

The second parameter that defines a waveform is its amplitude. In an
electronic circuit, amplitude relates to the voltage or current in the
circuit. When a signal is going to a speaker, the amplitude is expressed
in watts. Perceived sound intensity is measured in decibels (db). Human
hearing has a range of about 120 db; 1 db is the faintest audible sound.
Roughly every 10 db corresponds to a doubling of sound, and 1 db is the
smallest change in amplitude that is noticeable in a moderately loud
sound. Volume, which is the amplitude of the sound signal which is output,
corresponds logarithmically to decibel level.

The frequency and amplitude parameters of a sine wave are completely
independent. When sound is heard, however, there is interaction between
loudness and pitch. Lower-frequency sounds decrease in loudness much
faster than high-frequency sounds.

The third attribute of a sound, timbre, depends on the presence or absence
of overtones, or harmonics. Any complex waveform is actually a mixture of
sine waves of different amplitudes, frequencies, and phases (the starting
point of the waveform on the time axis). These component sine waves are
called harmonics. A square waveform, for example, has an infinite number
of harmonics.

In summary, all steady sounds can be described by their frequency, overall
amplitude, and relative harmonic amplitudes. The audible equivalents of
these parameters are pitch, loudness, and timbre, respectively. Changing
sound is a steady sound whose parameters change over time.

In electronic production of sound, an analog device, such as a tape
recorder, records sound waveforms and their cycle frequencies as a
continuously variable representation of air pressure. The tape recorder
then plays back the sound by sending the waveforms to an amplifier where
they are changed into analog voltage waveforms. The amplifier sends the
voltage waveforms to a loudspeaker, which translates them into air
pressure vibrations that the listener perceives as sound.

A computer cannot store analog waveform information. In computer
production of sound, a waveform has to be represented as a finite string
of numbers. This transformation is made by dividing the time axis of the
graph of a single waveform into equal segments, each of which represents a
short enough time so the waveform does not change a great deal. Each of
the resulting points is called a sample. These samples are stored in
memory, and you can play them back at a frequency that you determine. The
computer feeds the samples to a digital-to-analog converter (DAC), which
changes them into an analog voltage waveform. To produce the sound, the
analog waveforms are sent first to an amplifier, then to a loudspeaker.

Figure 5-2 shows an example of a sine wave, a square wave, and a triangle
wave, along with a table of samples for each.

```c
               [Figure 5-2: Digitized Amplitude Values](hardware/hard-pics-5-2-pic.md) 

                 TIME    SINE    SQUARE   TRIANGLE
                 ----    ----    ------   --------
                   0        0      100        0
                   1       39      100       20
                   2       75      100       40
                   3      103      100       60
                   4      121      100       80
                   5      127      100      100
                   6      121      100       80
                   7      103      100       60
                   8       75      100       40
                   9       39      100       20
                  10        0     -100        0
                  11      -39     -100      -20
                  12      -75     -100      -40
                  13     -103     -100      -60
                  14     -121     -100      -80
                  15     -127     -100     -100
                  16     -121     -100      -80
                  17     -103     -100      -60
                  18      -75     -100      -40
                  19      -39     -100      -20
```
   Note:
   -----
   The illustrations are not to scale and there are fewer dots in the
   wave forms than there are samples in the table. The amplitude axis
   values 127 and -128 represent the high and low limits on relative
   amplitude.


 [The Amiga Sound Hardware](hardware/5-introducing-sound-generation-the-amiga-sound-hardware.md) 

