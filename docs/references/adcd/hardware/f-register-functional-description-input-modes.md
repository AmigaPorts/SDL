---
title: F / Register Functional Description / Input Modes
manual: hardware
chapter: hardware
section: f-register-functional-description-input-modes
functions: []
libraries: []
---

# F / Register Functional Description / Input Modes

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Control bits (CRA5, CRB5-6) allow selection of the clock used to decrement
the timer.  [Timer A](hardware/f-register-functional-description-interval-timers-timer-a-b.md)  can count 02 clock pulses or external pulses applied
to the CNT pin.   [Timer B](hardware/f-register-functional-description-interval-timers-timer-a-b.md)  can count 02 pulses, external CNT pulses,
 [timer A](hardware/f-register-functional-description-interval-timers-timer-a-b.md)  underflow pulses, or  [timer A](hardware/f-register-functional-description-interval-timers-timer-a-b.md)  underflow pulses while the CNT
pin is held high.

The timer latch is loaded into the timer on any timer underflow, on a
force load, or following a write to the high byte of the pre- scalar while
the timer is stopped.  If the timer is running, a write to the high byte
will load the timer latch but not the counter.

