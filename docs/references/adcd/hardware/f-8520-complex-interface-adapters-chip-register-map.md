---
title: F 8520 Complex Interface Adapters / Chip Register Map
manual: hardware
chapter: hardware
section: f-8520-complex-interface-adapters-chip-register-map
functions: []
libraries: []
---

# F 8520 Complex Interface Adapters / Chip Register Map

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Each 8520 has 16 registers that you may read or write.  Here is the list
of registers and the access address of each within the memory space
dedicated to the 8520:

                       Register
   RS3  RS2  RS1  RS0  #(hex)  NAME      MEANING
   -----------------------------------------------------------------
```c
    0    0    0    0     0     pra       [Peripheral data register A](hardware/f-register-functional-description-i-o-ports-pra-prb-ddra.md) 
    0    0    0    1     1     prb       [Peripheral data register B](hardware/f-register-functional-description-i-o-ports-pra-prb-ddra.md) 
    0    0    1    0     2     ddra      Data  [direction register A](hardware/f-register-functional-description-i-o-ports-pra-prb-ddra.md) 
    0    0    1    1     3     ddrb      [Direction register B](hardware/f-register-functional-description-i-o-ports-pra-prb-ddra.md) 
    0    1    0    0     4     talo      [Timer A](hardware/f-register-functional-description-interval-timers-timer-a-b.md)  low register
    0    1    0    1     5     tahi      [Timer A](hardware/f-register-functional-description-interval-timers-timer-a-b.md)  high register
    0    1    1    0     6     tblo      [Timer B](hardware/f-register-functional-description-interval-timers-timer-a-b.md)  low register
    0    1    1    1     7     tbhi      [Timer B](hardware/f-register-functional-description-interval-timers-timer-a-b.md)  high register
    1    0    0    0     8     todlow    [Event LSB](hardware/f-8520-complex-interface-adapters-time-of-day-clock.md) 
    1    0    0    1     9     todmid    [Event 8-15](hardware/f-time-of-day-clock-bit-names-for-write-time-alarm-or-read.md) 
    1    0    1    0     A     todhi     [Event MSB](hardware/f-8520-complex-interface-adapters-time-of-day-clock.md) 
    1    0    1    1     B               No connect
    1    1    0    0     C     sdr       [Serial data register](hardware/f-8520-complex-interface-adapters-register-functional.md) 
    1    1    0    1     D     icr       [Interrupt control register](hardware/f-8520-complex-interface-adapters-interrupt-control.md) 
    1    1    1    0     E     cra       [Control register A](hardware/f-8520-complex-interface-adapters-control-registers.md) 
    1    1    1    1     F     crb       [Control register B](hardware/f-8520-complex-interface-adapters-control-registers.md) 
```
   -----------------------------------------------------------------

