---
title: F / / Interval Timers (Timer A, Timer B) / Toggle/pulse
manual: hardware
chapter: hardware
section: f-interval-timers-timer-a-timer-b-toggle-pulse
functions: []
libraries: []
---

# F / / Interval Timers (Timer A, Timer B) / Toggle/pulse

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A control bit (CRx2) selects the output applied to  [port B](hardware/f-register-functional-description-i-o-ports-pra-prb-ddra.md)  while the PB
on/off bit is ON.  On every timer underflow, the output can either toggle
or generate a single positive pulse of one cycle duration.  The toggle
output is set high whenever the timer is started, and set low by  [RES](hardware/f-interface-signals-res-reset-input.md) .

