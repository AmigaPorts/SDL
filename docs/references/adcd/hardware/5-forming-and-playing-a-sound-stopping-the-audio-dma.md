---
title: 5 / Forming and Playing a Sound / Stopping the Audio Dma
manual: hardware
chapter: hardware
section: 5-forming-and-playing-a-sound-stopping-the-audio-dma
functions: []
libraries: []
---

# 5 / Forming and Playing a Sound / Stopping the Audio Dma

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You can stop the channel by writing a 0 into the  [AUDxEN](hardware/5-forming-and-playing-a-sound-playing-the-waveform.md)  bit at any time.
However, you cannot resume the output at the same point in the waveform by
just writing a 1 in the bit again. Enabling an audio channel almost always
starts the data output again from the top of the list of data pointed to
by the  [location registers](hardware/5-forming-and-playing-a-sound-telling-the-system-about-the.md)  for that channel. If the channel is disabled
for a very short time (less than two  [sampling periods](hardware/5-forming-and-playing-a-sound-selecting-the-data-output-rate.md) ) it may stay on
and thus continue from where it left off.

The following example shows how to stop audio DMA for one channel.

STOPAUDCHAN0:

```c
        LEA     CUSTOM,a0
        MOVE.W  #(DMAF_AUD0),[DMACON](hardware/7-system-control-hardware-dma-control.md)(a0)
```
