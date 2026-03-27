---
title: A Register Summary / AUDxDAT
manual: hardware
chapter: hardware
section: a-register-summary-audxdat
functions: []
libraries: []
---

# A Register Summary / AUDxDAT

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
AUDxDAT    0AA      W       P      Audio channel x data


```c
                 This register is the audio channel x (x=0,1,2,3)
                 DMA data buffer.  It contains 2 bytes of data that
                 are each 2's complement and are outputted
                 sequentially (with digital-to-analog conversion)
                 to the audio output pins.  (LSB = 3 MV)  The DMA
                 controller automatically transfers data to this
                 register from RAM.  The processor can also write
                 directly to this register.  When the DMA data is
                 finished (words outputted=length) and the data in
                 this register has been used, an audio channel
                 interrupt request is set.
```
