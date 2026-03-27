---
title: F / / Interface Signals / RES - reset input
manual: hardware
chapter: hardware
section: f-interface-signals-res-reset-input
functions: []
libraries: []
---

# F / / Interface Signals / RES - reset input

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A low on the RES pin resets all internal registers.  The port pins are set
as inputs and port registers to zero (although a read of the ports will
return all highs because of passive pull-ups). The timer control registers
are set to zero and the timer latches to all ones.  All other registers
are reset to zero.

