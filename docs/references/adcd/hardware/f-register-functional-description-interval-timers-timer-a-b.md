---
title: F / Register Functional Description / Interval Timers (Timer A, B)
manual: hardware
chapter: hardware
section: f-register-functional-description-interval-timers-timer-a-b
functions: []
libraries: []
---

# F / Register Functional Description / Interval Timers (Timer A, B)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Each interval timer consists of a 16-bit read-only timer counter and a
16-bit write-only timer latch.  Data written to the timer is latched into
the timer latch, while data read from the timer is the present contents of
the timer counter.

The latch is also called a prescalar in that it represents the countdown
value which must be counted before the timer reaches an underflow (no more
counts) condition.  This latch (prescalar) value is a divider of the input
clocking frequency. The timers can be used independently or linked for
extended operations.  Various timer operating modes allow generation of
long time delays, variable width pulses, pulse trains, and variable
frequency waveforms.  Utilizing the CNT input, the timers can count
external pulses or measure frequency, pulse width, and delay times of
external signals.

Each timer has an associated  [control register](hardware/f-8520-complex-interface-adapters-control-registers.md) , providing independent
control over each of the following functions:

 [Start/Stop](hardware/f-interval-timers-timer-a-timer-b-start-stop.md)        [One-shot/continuous](hardware/f-interval-timers-timer-a-timer-b-one-shot-continuous.md) 
 [PB on/off](hardware/f-interval-timers-timer-a-timer-b-pb-on-off.md)         [Force load](hardware/f-interval-timers-timer-a-timer-b-force-load.md) 
 [Toggle/pulse](hardware/f-interval-timers-timer-a-timer-b-toggle-pulse.md) 

