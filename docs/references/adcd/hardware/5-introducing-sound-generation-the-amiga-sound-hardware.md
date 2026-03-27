---
title: 5 / Introducing Sound Generation / The Amiga Sound Hardware
manual: hardware
chapter: hardware
section: 5-introducing-sound-generation-the-amiga-sound-hardware
functions: []
libraries: []
---

# 5 / Introducing Sound Generation / The Amiga Sound Hardware

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Amiga has four hardware sound channels. You can independently program
each of the channels to produce complex sound effects. You can also attach
channels so that one channel  [modulates](hardware/5-producing-complex-sounds-modulating-sound.md)  the sound of another or combine
two channels for stereo effects.

Each audio channel includes an eight-bit  [digital-to-analog converter](hardware/5-audio-hardware-introducing-sound-generation.md) 
driven by a direct memory access (DMA) channel. The audio DMA can retrieve
two data samples during each horizontal video scan line. For simple,
steady tones, the DMA can automatically play a waveform repeatedly; you
can also program all kinds of complex sound effects.

There are two methods of basic sound production on the Amiga -- automatic
(DMA) sound generation and  [direct (non-DMA)](hardware/5-audio-hardware-using-direct-non-dma-audio-output.md)  sound generation. When you
use automatic sound generation, the system retrieves data automatically by
direct memory access.

