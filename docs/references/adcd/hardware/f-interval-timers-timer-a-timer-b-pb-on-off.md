---
title: F / / Interval Timers (Timer A, Timer B) / PB on/off
manual: hardware
chapter: hardware
section: f-interval-timers-timer-a-timer-b-pb-on-off
functions: []
libraries: []
---

# F / / Interval Timers (Timer A, Timer B) / PB on/off

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A control bit (CRx1) allows the timer output to appear on a  [port B](hardware/f-register-functional-description-i-o-ports-pra-prb-ddra.md) 
output line (PB6 for timer A and PB7 for timer B).  This function
overrides the  [DDRB](hardware/f-register-functional-description-i-o-ports-pra-prb-ddra.md)  control bit and forces the appropriate PB line to
become an output.

