---
title: 5 / Forming and Playing a Sound / Selecting the Data Output Rate
manual: hardware
chapter: hardware
section: 5-forming-and-playing-a-sound-selecting-the-data-output-rate
functions: []
libraries: []
---

# 5 / Forming and Playing a Sound / Selecting the Data Output Rate

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The pitch of the sound produced by the waveform depends upon its
frequency. To tell the system what frequency to use, you need to specify
the sampling period. The sampling period specifies the number of system
clock  [ticks](hardware/5-audio-hardware-the-equal-tempered-musical-scale.md) , or timing intervals, that should elapse between each sample
(byte of audio data) fed to the  [digital-to-analog converter](hardware/5-audio-hardware-introducing-sound-generation.md)  in the audio
channel. There is a  [period register](hardware/5-selecting-the-data-output-rate-specifying-the-period-value.md)  for each audio channel. The value of
the  [period register](hardware/5-selecting-the-data-output-rate-specifying-the-period-value.md)  is used for count-down purposes; each time the
register counts down to 0, another sample is retrieved from the waveform
data set for output. In units, the period value represents clock ticks per
sample. The minimum period value you should use is 124 ticks per sample
NTSC (123 PAL) and the maximum is 65535. These limits apply to both PAL and
NTSC machines. For high-quality sound, there are other constraints on the
sampling period (see the section called  [Producing High-quality Sound](hardware/5-audio-hardware-producing-high-quality-sound.md) ).

   The period is inversely proportional to the frequency.
   ------------------------------------------------------
   A low period value corresponds to a higher frequency sound and a
   high period value corresponds to a lower frequency sound.

 [Limitations on Selection of Sampling Period](hardware/5-data-output-rate-limitations-on-selection-of-sampling.md) 
 [Specifying the Period Value](hardware/5-selecting-the-data-output-rate-specifying-the-period-value.md) 

