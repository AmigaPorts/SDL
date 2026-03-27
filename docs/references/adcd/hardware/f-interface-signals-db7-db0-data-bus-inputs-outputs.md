---
title: F / / Interface Signals / DB7-DB0 - data bus inputs/outputs
manual: hardware
chapter: hardware
section: f-interface-signals-db7-db0-data-bus-inputs-outputs
functions: []
libraries: []
---

# F / / Interface Signals / DB7-DB0 - data bus inputs/outputs

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The eight data bus output pins transfer information between the 8520 and
the system data bus.  These pins are high impedance inputs unless  [CS](hardware/f-interface-signals-cs-chip-select-input.md)  is
low and  [R/W](hardware/f-interface-signals-r-w-read-write-input.md)  and 02 are high, to read the device.  During this read, the
data bus output buffers are enabled, driving the data from the selected
register onto the system data bus.

