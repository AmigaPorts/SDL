---
title: 5 / Producing High-quality Sound / Low-Pass Filter
manual: hardware
chapter: hardware
section: 5-producing-high-quality-sound-low-pass-filter
functions: []
libraries: []
---

# 5 / Producing High-quality Sound / Low-Pass Filter

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The system includes a low-pass filter that eliminates
 [aliasing distortion](hardware/5-producing-high-quality-sound-aliasing-distortion.md)  as described above. This filter becomes active
around 4 KHz and gradually begins to attenuate (cut off) the signal.
Generally, you cannot clearly hear frequencies higher than 7 KHz.
Therefore, you get the most complete frequency response in the frequency
range of 0 - 7 KHz. If you are making frequencies from 0 to 7 KHz, you
should select a sampling rate no less than 14 KHz, which corresponds to a
 [sampling period](hardware/5-forming-and-playing-a-sound-selecting-the-data-output-rate.md)  in the range 124 to 256.

At a  [sampling period](hardware/5-forming-and-playing-a-sound-selecting-the-data-output-rate.md)  around 320, you begin to lose the higher frequency
values between 0 KHz and 7 KHz, as shown in Table 5-6.




```c
          Table 5-6: Sampling Rate and Frequency Relationship


                            Sampling    Sampling    Maximum Output
                             Period    Rate (KHz)   Frequency (KHz)
                            --------   ----------   ---------------
     Maximum sampling rate    124         29              7
     Minimum sampling rate    256         14              7
       for 7 KHz output
     Sampling rate too low    320         11              4
       for 7 KHz output
```
In A2000's with 2 layer motherboards and later A500 models there is a
control bit that allows the audio output to bypass the low pass filter.
This control bit is the same output bit of the  [8520 CIA](hardware/amiga-hardware-reference-manual-f-8520-complex-interface.md)  that controls
the brightness of the red "power" LED (CIA A $BFE001 - Bit 1: /LED).
Bypassing the filter allows for improved sound in some applications, but
an external filter with an appropriate cutoff frequency may be required.

