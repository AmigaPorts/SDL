# A Register Summary / DSKPTH, DSKPTL


                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
DSKPTH     020      W      A( [E](../Hardware_Manual_guide/node00AB.html#line4) ) Disk pointer (high 3 bits,
```c
                                      high 5 bits if ECS)
```
DSKPTL     022      W       A     Disk pointer (low 15 bits)


                 This pair of registers contains the 18-bit
                 address of disk DMA data. These address registers
                 must be initialized by the processor or Copper
                 before disk DMA is enabled.
