---
title: 5 / Producing High-quality Sound / Sampling Rate
manual: hardware
chapter: hardware
section: 5-producing-high-quality-sound-sampling-rate
functions: []
libraries: []
---

# 5 / Producing High-quality Sound / Sampling Rate

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

If you need high precision in your frequency output, you may find that the
frequency you wish to produce is somewhere between two available sampling
rates, but not close enough to either rate for your requirements. In those
cases, you may have to adjust the length of the audio data table in
addition to altering the sampling rate.

For higher frequencies, you may also need to use audio data tables that
contain more than one full cycle of the audio waveform to reproduce the
desired frequency more accurately, as illustrated in Figure 5-4.


```c
     [Figure 5-4: Waveform with Multiple Cycles](hardware/hard-pics-5-4-pic.md) 
```
