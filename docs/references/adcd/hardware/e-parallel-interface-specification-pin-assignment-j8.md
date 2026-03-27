---
title: E / / Parallel Interface Specification / Pin Assignment (J8)
manual: hardware
chapter: hardware
section: e-parallel-interface-specification-pin-assignment-j8
functions: []
libraries: []
---

# E / / Parallel Interface Specification / Pin Assignment (J8)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME    DIR   NOTES
   ----    ---   ------------------------
   DRDY*    O    Output-data-ready signal to parallel device in
```c
                 output mode, used in conjunction with ACK* (pin 10)
                 for a two-line asynchronous handshake.  Functions
                 as input data accepted from Amiga in input mode
                 (similar to ACK* in output mode).  See  [timing diagrams](hardware/e-parallel-interface-specification-interface-timing-output.md) 
                 in the following section.
```
   D0      I/O   +
   D1      I/O   |
   D2      I/O   |
   D3      I/O   | D0-D7 comprise an eight-bit bidirectional bus
   D4      I/O   | for communication with parallel devices,
   D5      I/O   | nominally, a printer.
   D6      I/O   |
   D7      I/O   +
   ACK*     I    Output-data-acknowledge from parallel device in
```c
                 output mode, used in conjunction with DRDY* (pin 1)
                 for a two-line asynchronous handshake.  Functions as
                 input-data-ready from parallel device in input mode
                 (similar to DRDY* in output mode).
                 See  [timing diagrams](hardware/e-parallel-interface-specification-interface-timing-output.md) .  The 8520 can be programmed to
                 conditionally generate a level 2 interrupt to the
                 680x0 whenever the ACK* input goes active.
```
   BUSY    I/O   This is a general purpose I/O pin also connected to a
```c
                 serial data I/O pin (serial clock on pin 12).
                 Note: Nominally used to indicate printer buffer full.
```
   POUT    I/O   This is a general purpose I/O pin to a
```c
                 serial clock I/O pin (serial data on pin 11).
                 Note: Nominally used to indicate printer paper out.
```
   SEL     I/O   This is a general purpose I/O pin.

                 Note:  nominally a select output from the parallel
                 device to the Amiga.  On the A500/A2000 also shared
                 with RS232 "ring indicator" signal.
   RESET*   O    Amiga system reset

