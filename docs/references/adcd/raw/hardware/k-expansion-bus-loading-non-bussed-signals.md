# K / / Expansion Bus Loading / Non-bussed Signals


The non-bussed, or slot specific, signals are involved with only one slot
on the bus (e.g., each slot has its own copy).  As a result, the drive
requirements are much less for these signals.  The backplane provides
pullups or pulldowns, as required by the specific signal.


```c
        [/CFGINn](../Hardware_Manual_guide/node02B2.html#line17)   [/CFGOUTn](../Hardware_Manual_guide/node02B2.html#line17)   [/BRn](../Hardware_Manual_guide/node02B3.html#line12)        [/BGn](../Hardware_Manual_guide/node02B3.html#line12) 
        [SenseZ3](../Hardware_Manual_guide/node02B2.html#line33)   [/SLAVEn](../Hardware_Manual_guide/node02B2.html#line3) 
```
