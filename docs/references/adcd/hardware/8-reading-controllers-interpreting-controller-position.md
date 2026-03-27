---
title: 8 / / Reading Controllers / Interpreting Controller Position
manual: hardware
chapter: hardware
section: 8-reading-controllers-interpreting-controller-position
functions: []
libraries: []
---

# 8 / / Reading Controllers / Interpreting Controller Position

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Interpreting the position of the proportional controller normally requires
some preliminary work during the  [vertical blanking](hardware/7-setting-and-clearing-bits-vertical-blanking-interrupt.md)  interval.

During  [vertical blanking](hardware/7-setting-and-clearing-bits-vertical-blanking-interrupt.md) , you write a value into an address called
 [POTGO](hardware/8-controller-port-interface-digital-i-o-on-the-controller.md) . For a standard X-Y joystick, this value is hex 0001. Writing to
this register starts the operation of some special hardware that reads the
potentiometer values and sets the values contained in the  [POT registers](hardware/8-reading-controllers-proportional-controller-registers.md) 
(described below) to zero.

The read circuitry stays in a reset state for the first seven or eight
horizontal video scan lines. Following the reset interval, the circuit
allows a charge to begin building up on a timing capacitor whose charge
rate will be controlled by the position of the external controller
resistance. For each horizontal scan line thereafter, the circuit compares
the charge on the timing capacitor to a preset value. If the charge is
below the preset, the  [POT counter](hardware/8-reading-controllers-proportional-controller-registers.md)  is incremented. If the charge is above
the preset, the counter value will be held until the next  [POTGO](hardware/8-controller-port-interface-digital-i-o-on-the-controller.md)  is
issued.


```c
     [Figure 8-5: Effects of Resistance on Charging Rate](hardware/hard-pics-8-5-pic.md) 
```
You normally issue  [POTGO](hardware/8-controller-port-interface-digital-i-o-on-the-controller.md)  at the beginning of a video screen, then read
the values in the  [POT registers](hardware/8-reading-controllers-proportional-controller-registers.md)  during the next  [vertical blanking](hardware/7-setting-and-clearing-bits-vertical-blanking-interrupt.md) 
period, just before issuing  [POTGO](hardware/8-controller-port-interface-digital-i-o-on-the-controller.md)  again.

Nothing in the system prevents the counters from overflowing (wrapping
past a count of 255). However, the system is designed to insure that the
counter cannot overflow within the span of a single screen. This allows
you to know for certain whether an overflow is indicated by the controller.

