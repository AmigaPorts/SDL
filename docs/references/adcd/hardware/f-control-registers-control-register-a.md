---
title: F / Control Registers / Control Register A
manual: hardware
chapter: hardware
section: f-control-registers-control-register-a
functions: []
libraries: []
---

# F / Control Registers / Control Register A

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

  BIT  NAME     FUNCTION
  ---  ----     --------
   0   [START](hardware/f-interval-timers-timer-a-timer-b-start-stop.md)    1 = start Timer A, 0 = stop Timer A.
```c
                    This bit is automatically reset (= 0) when
                    underflow occurs during one-shot mode.
```
   1   [PBON](hardware/f-interval-timers-timer-a-timer-b-pb-on-off.md)     1 = Timer A output on PB6, 0 = PB6 is normal operation.
   2   [OUTMODE](hardware/f-interval-timers-timer-a-timer-b-toggle-pulse.md)  1 = toggle, 0 = pulse.
   3   [RUNMODE](hardware/f-interval-timers-timer-a-timer-b-one-shot-continuous.md)  1 = one-shot mode, 0 = continuous mode.
   4   [LOAD](hardware/f-interval-timers-timer-a-timer-b-force-load.md)     1 = force load (this is a strobe input, there is no
```c
                    data storage;  bit 4 will always read back a zero
                    and writing a 0 has no effect.)
```
   5   [INMODE](hardware/f-register-functional-description-input-modes.md)   1 = Timer A counts positive CNT transitions,
```c
                0 = Timer A counts 02 pulses.
```
   6   [SPMODE](hardware/f-8520-complex-interface-adapters-serial-shift-register-sdr.md)   1 = Serial port=output (CNT is the source of the shift
```c
                    clock)
                0 = Serial port=input  (external shift clock is
                    required)
```
   7   UNUSED

