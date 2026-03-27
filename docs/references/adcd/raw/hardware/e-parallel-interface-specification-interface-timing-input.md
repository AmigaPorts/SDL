# E / / Parallel Interface Specification / Interface Timing, Input Cycle




```c
           PA<7:0>___ _________________________________________ __
           PB<7:0>___X_________________________________________X__
                     |<-- T1 --->|
                                 |               T2 -->|<----->|
                  _______________V         ____________|__________
           [ACK*](../Hardware_Manual_guide/node0102.html#line17)                  |________|            |
             Input data ready    |<- T3 ->|            |
                                 |<-- T4 --->|
                  ___________________________|<- T5 -->|__________
           [DRDY*](../Hardware_Manual_guide/node0102.html)                             |_________|
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
