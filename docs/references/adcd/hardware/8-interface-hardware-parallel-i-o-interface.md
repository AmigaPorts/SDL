---
title: 8 Interface Hardware / Parallel I/O Interface
manual: hardware
chapter: hardware
section: 8-interface-hardware-parallel-i-o-interface
functions: []
libraries: []
---

# 8 Interface Hardware / Parallel I/O Interface

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The general-purpose bi-directional  [parallel interface](hardware/e-explanation-of-i-o-connectors-parallel-interface.md)  is a 25-pin
connector on the back panel of the computer. This connector is generally
used for a parallel printer.

For each data byte written to the parallel port register, the hardware
automatically generates a pulse on the data ready pin.  The acknowledge
pulse from the parallel device is hooked up to an interrupt. For pin
connections and timing, see  [Appendix E](hardware/amiga-hardware-reference-manual-e-i-o-connectors-and.md)  and  [Appendix F](hardware/amiga-hardware-reference-manual-f-8520-complex-interface.md) .

