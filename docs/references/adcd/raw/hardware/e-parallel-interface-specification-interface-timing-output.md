# E / / Parallel Interface Specification / Interface Timing Output Cycle




```c
           PA<7:0>___ _________________________________________ __
           PB<7:0>___X_________________________________________X__
                     |<-- T1 --->|                             |
                                 |        |<-------- T2 ------>|
                  _______________V        V________________________
           [DRDY*](../Hardware_Manual_guide/node0102.html)                 |________|
             Output data ready   |<- T3 ->|
                                 |<--- T4 --->|
                  ____________________________|<- T5 -->|__________
           [ACK*](../Hardware_Manual_guide/node0102.html#line17)                               |_________|
             Output data acknowledge

                   Microseconds
                   Min Typ Max
                   --- --- ---
               T1: 4.3 -x- 5.3         Output data setup to ready delay.
               T2: nsp -x- upc         Output data hold time.
               T3: nsp 1.4 nsp         Output data ready width.
               T4:  0  -x- upc         Ready to acknowledge delay.
               T5: nsp -x- upc         Acknowledge width.

                   nsp = not specified
                   upc = under program control
```
