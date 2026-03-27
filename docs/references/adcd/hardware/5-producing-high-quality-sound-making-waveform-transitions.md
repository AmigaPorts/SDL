---
title: 5 / Producing High-quality Sound / Making Waveform Transitions
manual: hardware
chapter: hardware
section: 5-producing-high-quality-sound-making-waveform-transitions
functions: []
libraries: []
---

# 5 / Producing High-quality Sound / Making Waveform Transitions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To avoid unpleasant sounds when you change from one waveform to another,
you need to make the transitions smooth. You can avoid "clicks" by making
sure the waveforms start and end at approximately the same value. You can
avoid "pops" by starting a waveform only at a zero-crossing point. You can
avoid "thumps" by arranging the average  [amplitude](hardware/5-audio-hardware-introducing-sound-generation.md)  of each wave to be
about the same value. The average  [amplitude](hardware/5-audio-hardware-introducing-sound-generation.md)  is the sum of the bytes in
the waveform divided by the number of bytes in the waveform.

