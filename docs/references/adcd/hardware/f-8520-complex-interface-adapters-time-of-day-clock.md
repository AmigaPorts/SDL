---
title: F 8520 Complex Interface Adapters / Time of Day Clock
manual: hardware
chapter: hardware
section: f-8520-complex-interface-adapters-time-of-day-clock
functions: []
libraries: []
---

# F 8520 Complex Interface Adapters / Time of Day Clock

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

TOD consists of a 24-bit binary counter.  Positive edge transitions on
this pin cause the binary counter to increment.  The TOD pin has a passive
pull-up on it.

A programmable alarm is provided for generating an interrupt at a desired
time. The alarm registers are located at the same addresses as the
corresponding TOD registers.  Access to the alarm is governed by a
 [control register](hardware/f-8520-complex-interface-adapters-control-registers.md)  bit (CRB7).  The alarm is write-only; any read of a TOD
address will read time regardless of the state of the ALARM access bit.

A specific sequence of events must be followed for proper setting and
reading of TOD.  TOD is automatically stopped whenever a write to the
register occurs.  The clock will not start again until after a write to
the  [LSB event](hardware/f-8520-complex-interface-adapters-chip-register-map.md)  register.  This assures that TOD will always start at the
desired time.

Since a carry from one stage to the next can occur at any time with
respect to a read operation, a latching function is included to keep all
TOD information constant during a read sequence. All TOD registers latch
on a read of  [MSB event](hardware/f-8520-complex-interface-adapters-chip-register-map.md)  and remain latched until after a read of
 [LSB event](hardware/f-8520-complex-interface-adapters-chip-register-map.md) . The TOD clock continues to count when the output registers
are latched. If only one register is to be read, there is no carry problem
and the register can be read "on the fly" provided that any read of
 [MSB event](hardware/f-8520-complex-interface-adapters-chip-register-map.md)  is followed by a read of  [LSB Event](hardware/f-8520-complex-interface-adapters-chip-register-map.md)  to disable the latching.

 [Bit Names for Write Time/Alarm or Read Time](hardware/f-time-of-day-clock-bit-names-for-write-time-alarm-or-read.md) 

