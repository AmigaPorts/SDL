---
title: 7 System Control Hardware / Beam Position Detection
manual: hardware
chapter: hardware
section: 7-system-control-hardware-beam-position-detection
functions: []
libraries: []
---

# 7 System Control Hardware / Beam Position Detection

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Sometimes you might want to synchronize the 680x0 processor to the video
beam that is creating the screen display. In some cases, you may also wish
to update a part of the display memory after the system has already
accessed the data from the memory for the display area.

The address for accessing the beam counter is provided so that you can
determine the value of the video beam counter and perform certain
operations based on the beam position.

   NOTE:
   -----
   The Copper is already capable of watching the display position
   for you and doing certain register-based operations automatically.
   Refer to the  [Copper Interrupts](hardware/7-setting-and-clearing-bits-copper-interrupt.md)  section and

```c
    [Chapter 2, Coprocessor Hardware](hardware/amiga-hardware-reference-manual-2-coprocessor-hardware.md)  for further information.
```
In addition, when you are using a light pen, this same address is used to
read the  [light pen position](hardware/8-reading-a-light-pen-reading-the-light-pen-registers.md)  rather than the beam position. This is
described fully in Chapter 8, "Interface Hardware."

 [Using the Beam Position Counter](hardware/7-beam-position-detection-using-the-beam-position-counter.md) 

