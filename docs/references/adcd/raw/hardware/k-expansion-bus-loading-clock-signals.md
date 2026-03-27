# K / / Expansion Bus Loading / Clock Signals


All clock signals on the bus are in this group.  Many designs are very
sensitive to clock delay, skew, and rise/fall times, so loading on the
clock lines must be kept to a minimum.  These are bussed signals, actively
driven by the backplane, and source terminated with a low value series
resistor. PICs can apply one standard load to each of these signals when
necessary. Zorro II cards have the same clock rules, so there should never
be clocking problems when using either card type in a backplane.


```c
        [/C3](../Hardware_Manual_guide/node02B0.html#line10)       [CDAC](../Hardware_Manual_guide/node02B0.html#line14)        [/C1](../Hardware_Manual_guide/node02B0.html#line6)         [7M](../Hardware_Manual_guide/node02B0.html#line23) 
        [E Clock](../Hardware_Manual_guide/node02B0.html#line18) 
```
