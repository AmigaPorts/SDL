---
title: E / / Serial Interface Specification / Timing
manual: hardware
chapter: hardware
section: e-serial-interface-specification-timing
functions: []
libraries: []
---

# E / / Serial Interface Specification / Timing

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Maximum operating frequency is 19.2 KHz.  Refer to EIA standard RS-232-C
for operating and installation specifications.  A rate of 31.25 KHz will
be supported through the use of a MIDI adapter.

Modem control signals ( [CTS, RTS, DTR, DSR, CD](hardware/e-serial-interface-specification-pin-assignment-j6.md) ) are completely under
software control.  The modem control lines have no hardware affect on and
are completely asynchronous to  [TXD and RXD](hardware/e-serial-interface-specification-pin-assignment-j6.md) .

