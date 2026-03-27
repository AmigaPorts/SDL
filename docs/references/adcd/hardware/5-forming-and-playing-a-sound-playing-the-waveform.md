---
title: 5 / Forming and Playing a Sound / Playing the Waveform
manual: hardware
chapter: hardware
section: 5-forming-and-playing-a-sound-playing-the-waveform
functions: []
libraries: []
---

# 5 / Forming and Playing a Sound / Playing the Waveform

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

After you have defined the audio data  [location](hardware/5-forming-and-playing-a-sound-telling-the-system-about-the.md) ,  [length](hardware/5-forming-and-playing-a-sound-telling-the-system-about-the.md) ,  [volume](hardware/5-forming-and-playing-a-sound-selecting-the-volume.md)  and
 [period](hardware/5-forming-and-playing-a-sound-selecting-the-data-output-rate.md) , you can play the waveform by starting the DMA for that audio
channel. This starts the output of sound. Once started, the DMA continues
until you specifically stop it. Thus, the waveform is played over and over
again, producing the steady tone. The system uses the value in the
 [location registers](hardware/5-forming-and-playing-a-sound-telling-the-system-about-the.md)  each time it replays the waveform.

For any audio DMA to occur (or any other DMA, for that matter), the
DMAEN bit in  [DMACON](hardware/7-system-control-hardware-dma-control.md)  must be set. When both DMAEN and AUDxEN are set, the
DMA will start for channel x. All these bits and their meanings are shown
in table 5-3.




```c
         Table 5-3: DMA and Audio Channel Enable Bits


              [DMACON](hardware/7-system-control-hardware-dma-control.md)  Register
             ---------------

          Bit     Name      Function
          ---     ----      --------
         15       [SET/CLR](hardware/7-setting-and-clearing-bits-set-and-clear.md)   When this bit is written as a 1, it
                            sets any bit in DMACONW for which
                            the corresponding bit position is
                            also a 1, leaving all other bits alone.

          9       DMAEN     Only while this bit is a 1 can
                            any direct memory access occur.

          3       AUD3EN    Audio channel 3 enable.
          2       AUD2EN    Audio channel 2 enable.
          1       AUD1EN    Audio channel 1 enable.
          0       AUD0EN    Audio channel 0 enable.
```
For example, if you are using channel 0, then you write a 1 into bit 9 to
enable DMA and a 1 into bit 0 to enable the audio channel, as shown below.

BEGINCHAN0:

```c
        LEA     CUSTOM,a0
        MOVE.W  #(DMAF_SETCLR!DMAF_AUD0!DMAF_MASTER),[DMACON](hardware/7-system-control-hardware-dma-control.md)(a0)
```
