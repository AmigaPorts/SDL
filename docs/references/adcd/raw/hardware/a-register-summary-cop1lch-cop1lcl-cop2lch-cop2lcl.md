# A Register Summary / COP1LCH, COP1LCL, COP2LCH, COP2LCL


                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
COP1LCH    080      W      A( [E](../Hardware_Manual_guide/node00AB.html#line4) ) Copper first location register
```c
                                      (high 3 bits, high 5 bits if ECS)
```
COP1LCL    082      W       A     Copper first location register
```c
                                      (low 15 bits)
```
COP2LCH    084      W      A( [E](../Hardware_Manual_guide/node00AB.html#line4) ) Copper second location register
```c
                                      (high 3 bits, high 5 bits if ECS)
```
COP2LCL    086      W       A     Copper second location register

```c
                                      (low 15 bits)

                 These registers contain the jump addresses
                 described above.
```
