# A Register Summary / AUDxLCH, AUDxLCL


                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
AUDxLCH    0A0      W      A( [E](../Hardware_Manual_guide/node00AB.html#line4) )  Audio channel x location (high 3 bits,
```c
                                       5 bits if ECS)
```
AUDxLCL    0A2      W       A      Audio channel x location (low 15 bits)


```c
                 This pair of registers contains the 18 bit starting
                 address (location) of audio channel x (x=0,1,2,3) DMA
                 data. This is not a pointer register and therefore needs
                 to be reloaded only if a different memory location is to
                 be outputted.
```
