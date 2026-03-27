---
title: 5 / Producing High-quality Sound / Noise Reduction
manual: hardware
chapter: hardware
section: 5-producing-high-quality-sound-noise-reduction
functions: []
libraries: []
---

# 5 / Producing High-quality Sound / Noise Reduction

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To reduce noise levels and produce an accurate sound, try to use the full
range of -128 to 127 when you represent a waveform. This reduces how much
noise (quantization error) will be added to the signal by using more bits
of precision. Quantization noise is caused by the introduction of
round-off error. If you are trying to reproduce a signal, such as a sine
wave, you can represent the  [amplitude](hardware/5-audio-hardware-introducing-sound-generation.md)  of each sample with only so many
digits of accuracy. The difference between the real number and your
approximation is round-off error, or noise.

By doubling the  [amplitude](hardware/5-audio-hardware-introducing-sound-generation.md) , you create half as much noise because the
size of the steps of the wave form stays the same and is therefore a
smaller fraction of the amplitude.

In other words, if you try to represent a waveform using, for example, a
range of only +3 to -3, the size of the error in the output would be
considerably larger than if you use a range of +127 to -128 to represent
the same signal. Proportionally, the digital value used to represent the
waveform  [amplitude](hardware/5-audio-hardware-introducing-sound-generation.md)  will have a lower error. As you increase the number
of possible sample levels, you decrease the relative size of each step
and, therefore, decrease the size of the error.

To produce quiet sounds, continue to define the waveform using the full
range, but adjust the  [volume](hardware/5-forming-and-playing-a-sound-selecting-the-volume.md) . This maintains the same level of accuracy
(signal-to-noise ratio) for quiet sounds as for loud sounds.

