---
title: 5 Audio Hardware / Using Direct (Non-DMA) Audio Output
manual: hardware
chapter: hardware
section: 5-audio-hardware-using-direct-non-dma-audio-output
functions: []
libraries: []
---

# 5 Audio Hardware / Using Direct (Non-DMA) Audio Output

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

It is possible to create sound by writing audio data one word at a time to
the audio output addresses, instead of setting up a list of audio data in
memory. This method of controlling the output is more processor-intensive
and is therefore not recommended.

To use direct audio output, do not enable the DMA for the audio channel
you wish to use; this changes the timing of the  [interrupts](hardware/7-setting-and-clearing-bits-audio-interrupts.md) . The normal
 [interrupt](hardware/7-setting-and-clearing-bits-audio-interrupts.md)  occurs after a data address has been read; in direct audio
output, the  [interrupt](hardware/7-setting-and-clearing-bits-audio-interrupts.md)  occurs after one data word has been output.

Unlike in the DMA-controlled automatic data output, in direct audio
output, if you do not write a new set of data to the output addresses
before two sampling intervals have elapsed, the audio output will cease
changing. The last value remains as an output of the
 [digital-to-analog converter](hardware/5-audio-hardware-introducing-sound-generation.md) .

The  [volume](hardware/5-forming-and-playing-a-sound-selecting-the-volume.md)  and  [period registers](hardware/5-selecting-the-data-output-rate-specifying-the-period-value.md)  are set as usual.

