# A Register Summary / AUDxPER


                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
AUDxPER    0A6      W      P( [E](../Hardware_Manual_guide/node00AC.html#line30) )  Audio channel x Period


```c
                 This register contains the period (rate) of
                 audio channel x DMA data transfer.
                 The minimum period is 124 color clocks. This means
                 that the smallest number that should be placed in
                 this register is 124 decimal.  This corresponds to
                 a maximum sample frequency of 28.86 khz.
```
