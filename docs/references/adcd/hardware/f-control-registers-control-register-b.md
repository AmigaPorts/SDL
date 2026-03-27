---
title: F / Control Registers / Control Register B
manual: hardware
chapter: hardware
section: f-control-registers-control-register-b
functions: []
libraries: []
---

# F / Control Registers / Control Register B

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   CONTROL REGISTER B:

  BIT  NAME     FUNCTION
  ---  ----     --------
   0   [START](hardware/f-interval-timers-timer-a-timer-b-start-stop.md)    1 = start Timer B, 0 = stop Timer B.
```c
                    This bit is automatically reset (= 0) when
                    underflow occurs during one-shot mode.
```
   1   [PBON](hardware/f-interval-timers-timer-a-timer-b-pb-on-off.md)     1 = Timer B output on PB7, 0 = PB7 is normal
                    operation.
   2   [OUTMODE](hardware/f-interval-timers-timer-a-timer-b-toggle-pulse.md)  1 = toggle, 0 = pulse.
   3   [RUNMODE](hardware/f-interval-timers-timer-a-timer-b-one-shot-continuous.md)  1 = one-shot mode, 0 = continuous mode.
   4   [LOAD](hardware/f-interval-timers-timer-a-timer-b-force-load.md)     1 = force load (this is a strobe input, there is no
```c
                    data storage;  bit 4 will always read back a
                    zero and writing a 0 has no effect.)
```
  6,5  [INMODE](hardware/f-register-functional-description-input-modes.md)   Bits CRB6 and CRB5 select one of four possible

                input modes for Timer B, as follows:

                CRB6  CRB5   Mode Selected
                ----  ----   ---------------------------------------
                 0     0     Timer B counts 02 pulses
                 0     1     Timer B counts positive CNT transitions
                 1     0     Timer B counts Timer A underflow pulses
                 1     1     Timer B counts Timer A underflow pulses
                               while CNT pin is held high.
   7   [ALARM](hardware/f-8520-complex-interface-adapters-time-of-day-clock.md)     1 = writing to TOD registers sets Alarm

```c
                 0 = writing to TOD registers sets TOD clock.
                     Reading TOD registers always reads TOD clock,
                     regardless of the state of the Alarm bit.
```
