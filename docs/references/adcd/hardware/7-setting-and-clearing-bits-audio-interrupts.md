---
title: 7 / / Setting and Clearing Bits / Audio Interrupts
manual: hardware
chapter: hardware
section: 7-setting-and-clearing-bits-audio-interrupts
functions: []
libraries: []
---

# 7 / / Setting and Clearing Bits / Audio Interrupts

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Bits 10 - 7, AUD3 - 0, are assigned to the audio channels. They are called
AUD3, AUD2, AUD1, and AUD0 and are assigned to channels 3, 2, 1, and 0,
respectively.

This  [level 4 interrupt](hardware/7-setting-and-clearing-bits-figure-7-4-interrupt-priorities.md)  signals "audio block done." When the audio DMA is
operating in  [automatic mode](hardware/5-audio-hardware-the-audio-state-machine.md) , this interrupt occurs when the last word in
an audio data stream has been accessed. In  [manual mode](hardware/5-audio-hardware-using-direct-non-dma-audio-output.md) , it occurs when
the  [audio data register](hardware/a-register-summary-audxdat.md)  is ready to accept another word of data.

See Chapter 5, "Audio Hardware," for more information about
 [interrupt generation and timing](hardware/5-audio-hardware-the-audio-state-machine.md) .

