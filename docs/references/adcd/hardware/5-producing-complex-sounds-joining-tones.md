---
title: 5 / Producing Complex Sounds / Joining Tones
manual: hardware
chapter: hardware
section: 5-producing-complex-sounds-joining-tones
functions: []
libraries: []
---

# 5 / Producing Complex Sounds / Joining Tones

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Tones are joined by writing the  [location](hardware/5-forming-and-playing-a-sound-telling-the-system-about-the.md)  and  [length registers](hardware/5-forming-and-playing-a-sound-telling-the-system-about-the.md) ,
starting the audio output, and rewriting the registers in preparation for
the next audio waveform that you wish to connect to the first one. This is
made easy by the timing of the  [audio interrupts](hardware/7-setting-and-clearing-bits-audio-interrupts.md)  and the existence of
back-up registers. The  [location](hardware/5-forming-and-playing-a-sound-telling-the-system-about-the.md)  and  [length registers](hardware/5-forming-and-playing-a-sound-telling-the-system-about-the.md)  are read by the
DMA channel before audio output begins. The DMA channel then stores the
values in back-up registers.

Once the original registers have been read by the DMA channel, you can
change their values without disturbing the operation you started with the
original register contents. Thus, you can write the contents of these
registers, start an audio output, and then rewrite the registers in
preparation for the next waveform you want to connect to this one.

 [Interrupts](hardware/7-setting-and-clearing-bits-audio-interrupts.md)  occur immediately after the audio DMA channel has read the
 [location](hardware/5-forming-and-playing-a-sound-telling-the-system-about-the.md)  and  [length registers](hardware/5-forming-and-playing-a-sound-telling-the-system-about-the.md)  and stored their values in the back-up
registers. Once the  [interrupt](hardware/7-setting-and-clearing-bits-audio-interrupts.md)  has occurred, you can rewrite the
registers with the location and length for the next waveform segment. This
combination of back-up registers and  [interrupt](hardware/7-setting-and-clearing-bits-audio-interrupts.md)  timing lets you keep one
step ahead of the audio DMA channel, allowing your sound output to be
continuous and smooth.

If you do not rewrite the registers, the current waveform will be
repeated. Each time the  [length counter](hardware/5-audio-hardware-the-audio-state-machine.md)  reaches zero, both the  [location](hardware/5-forming-and-playing-a-sound-telling-the-system-about-the.md) 
and  [length registers](hardware/5-forming-and-playing-a-sound-telling-the-system-about-the.md)  are reloaded with the same values to continue the
audio output.

 [Audio DMA Example](hardware/5-joining-tones-audio-dma-example.md) 

