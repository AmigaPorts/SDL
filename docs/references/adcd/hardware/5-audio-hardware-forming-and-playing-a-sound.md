---
title: 5 Audio Hardware / Forming and Playing a Sound
manual: hardware
chapter: hardware
section: 5-audio-hardware-forming-and-playing-a-sound
functions: []
libraries: []
---

# 5 Audio Hardware / Forming and Playing a Sound

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This section shows you how to create a simple, steady sound and play it.
Many basic concepts that apply to all sound generation on the Amiga are
introduced in this section.

To produce a steady tone, follow these basic steps:

   1. Decide which channel to use.
   2. Define the waveform and create the sample table in memory.
   3. Set registers telling the system where to find the data and the
      length of the data.
   4. Select the volume at which the tone is to be played.
   5. Select the sampling period, or output rate of the data.
   6. Select an audio channel and start up the DMA.

 [Deciding Which Channel to Use](hardware/5-forming-and-playing-a-sound-deciding-which-channel-to-use.md)          [Playing the Waveform](hardware/5-forming-and-playing-a-sound-playing-the-waveform.md) 
 [Creating the Waveform Data](hardware/5-forming-and-playing-a-sound-creating-the-waveform-data.md)             [Stopping the Audio Dma](hardware/5-forming-and-playing-a-sound-stopping-the-audio-dma.md) 
 [Telling the System About the Data](hardware/5-forming-and-playing-a-sound-telling-the-system-about-the.md)      [Audio Summary](hardware/5-forming-and-playing-a-sound-audio-summary.md) 
 [Selecting the Volume](hardware/5-forming-and-playing-a-sound-selecting-the-volume.md)                   [Audio Example](hardware/hard-examples-sinewave-asm.md) 
 [Selecting the Data Output Rate](hardware/5-forming-and-playing-a-sound-selecting-the-data-output-rate.md) 

