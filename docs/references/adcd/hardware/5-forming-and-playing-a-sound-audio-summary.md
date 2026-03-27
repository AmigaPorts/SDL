---
title: 5 / Forming and Playing a Sound / Audio Summary
manual: hardware
chapter: hardware
section: 5-forming-and-playing-a-sound-audio-summary
functions: []
libraries: []
---

# 5 / Forming and Playing a Sound / Audio Summary

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

These are the steps necessary to produce a steady tone:

   1. Define the waveform.
   2. Create the data set containing the pairs of data samples (data
```c
      words). Normally, a data set contains the definition of one
      waveform.
```
   3. Set the location registers:


```c
          [AUDxLCH](hardware/5-forming-and-playing-a-sound-telling-the-system-about-the.md)  (high three bits)
          [AUDxLCL](hardware/5-forming-and-playing-a-sound-telling-the-system-about-the.md)  (low fifteen bits)
```
   4. Set the length register,  [AUDxLEN](hardware/5-forming-and-playing-a-sound-telling-the-system-about-the.md) , to the number of data words to
```c
      be retrieved before starting at the address currently in  [AUDxLC](hardware/5-forming-and-playing-a-sound-creating-the-waveform-data.md) .
```
   5. Set the volume register,  [AUDxVOL](hardware/5-forming-and-playing-a-sound-selecting-the-volume.md) .
   6. Set the period register,  [AUDxPER](hardware/5-selecting-the-data-output-rate-specifying-the-period-value.md) 
   7. Start the audio DMA by writing a 1 into bit 9,  [DMAEN](hardware/5-forming-and-playing-a-sound-playing-the-waveform.md)  , along with

```c
      a 1 in the  [SET/CLR](hardware/7-setting-and-clearing-bits-set-and-clear.md)  bit and a 1 in the position of the  [AUDxEN](hardware/5-forming-and-playing-a-sound-playing-the-waveform.md)  bit
      of the channel or channels you want to start.
```
