---
title: F / / Interface Signals / CS - chip-select input
manual: hardware
chapter: hardware
section: f-interface-signals-cs-chip-select-input
functions: []
libraries: []
---

# F / / Interface Signals / CS - chip-select input

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The CS input controls the activity of the 8520.  A low level on CS while
02 is high causes the device to respond to signals on the  [R/W](hardware/f-interface-signals-r-w-read-write-input.md)  and address
( [RS](hardware/f-interface-signals-rs3-rs0-address-inputs.md) ) lines.  A high on CS prevents these lines from controlling the 8520.
The CS line is normally activated (low) at 02 by the appropriate address
combination.

