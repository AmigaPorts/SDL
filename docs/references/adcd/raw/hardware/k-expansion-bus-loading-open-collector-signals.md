# K / / Expansion Bus Loading / Open Collector Signals


Many of the bus signals are shared via open collector or open drain
outputs rather than via tri-stated signals; this is of course required for
some  [asynchronous](../Hardware_Manual_guide/node02A5.html)  things like the shared interrupt lines, and it works
well for other types of signals as well.  Of course, a backplane resistor
pulls these lines high, PICs only drive the line low.


```c
        [/OWN](../Hardware_Manual_guide/node02B3.html#line4)      [/BGACK](../Hardware_Manual_guide/node02B3.html#line22)     [/CINH](../Hardware_Manual_guide/node02B5.html#line36)       [/BERR](../Hardware_Manual_guide/node02B1.html#line4) 
        [/DTACK](../Hardware_Manual_guide/node02B5.html#line27)    [/RESET](../Hardware_Manual_guide/node02B1.html#line40)     [/INT2](../Hardware_Manual_guide/node02B1.html#line61)       [/INT6](../Hardware_Manual_guide/node02B1.html#line61) 
        [/HLT](../Hardware_Manual_guide/node02B1.html#line52) 
```
