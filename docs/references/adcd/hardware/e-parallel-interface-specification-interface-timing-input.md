---
title: E / / Parallel Interface Specification / Interface Timing, Input Cycle
manual: hardware
chapter: hardware
section: e-parallel-interface-specification-interface-timing-input
functions: []
libraries: []
---

# E / / Parallel Interface Specification / Interface Timing, Input Cycle

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
           PA<7:0>___ _________________________________________ __
           PB<7:0>___X_________________________________________X__
                     |<-- T1 --->|
                                 |               T2 -->|<----->|
                  _______________V         ____________|__________
           [ACK*](hardware/e-parallel-interface-specification-pin-assignment-j8.md)                  |________|            |
             Input data ready    |<- T3 ->|            |
                                 |<-- T4 --->|
                  ___________________________|<- T5 -->|__________
           [DRDY*](hardware/e-parallel-interface-specification-pin-assignment-j8.md)                             |_________|
             Input data acknowledge

                   Microseconds
                   Min Typ Max
                   --- --- ---
               T1:  0  -x- upc         Input data setup time.
               T2: nsp -x- upc         Input data hold time.
               T3: nsp -x- upc         Input data ready width.
               T4: upc -x- upc         Input data ready to data
                                         acknowledge delay.
               T5: nsp 1.4 nsp         Input data acknowledge width.


                   nsp = not specified
                   upc = under program control
```
