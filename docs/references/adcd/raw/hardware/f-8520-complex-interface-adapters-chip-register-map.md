# F 8520 Complex Interface Adapters / Chip Register Map


Each 8520 has 16 registers that you may read or write.  Here is the list
of registers and the access address of each within the memory space
dedicated to the 8520:

                       Register
   RS3  RS2  RS1  RS0  #(hex)  NAME      MEANING
   -----------------------------------------------------------------
```c
    0    0    0    0     0     pra       [Peripheral data register A](../Hardware_Manual_guide/node0131.html) 
    0    0    0    1     1     prb       [Peripheral data register B](../Hardware_Manual_guide/node0131.html) 
    0    0    1    0     2     ddra      Data  [direction register A](../Hardware_Manual_guide/node0131.html) 
    0    0    1    1     3     ddrb      [Direction register B](../Hardware_Manual_guide/node0131.html) 
    0    1    0    0     4     talo      [Timer A](../Hardware_Manual_guide/node0133.html)  low register
    0    1    0    1     5     tahi      [Timer A](../Hardware_Manual_guide/node0133.html)  high register
    0    1    1    0     6     tblo      [Timer B](../Hardware_Manual_guide/node0133.html)  low register
    0    1    1    1     7     tbhi      [Timer B](../Hardware_Manual_guide/node0133.html)  high register
    1    0    0    0     8     todlow    [Event LSB](../Hardware_Manual_guide/node013C.html#line10) 
    1    0    0    1     9     todmid    [Event 8-15](../Hardware_Manual_guide/node013D.html) 
    1    0    1    0     A     todhi     [Event MSB](../Hardware_Manual_guide/node013C.html#line16) 
    1    0    1    1     B               No connect
    1    1    0    0     C     sdr       [Serial data register](../Hardware_Manual_guide/node0130.html#line6) 
    1    1    0    1     D     icr       [Interrupt control register](../Hardware_Manual_guide/node0142.html) 
    1    1    1    0     E     cra       [Control register A](../Hardware_Manual_guide/node0145.html) 
    1    1    1    1     F     crb       [Control register B](../Hardware_Manual_guide/node0145.html) 
```
   -----------------------------------------------------------------

