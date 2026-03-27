# A Register Summary / HBSTOP, HBSTRT, HCENTER, HSSTOP, HSSTRT, HTOTAL


                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
HBSTOP     1C6      W      A( [E](../Hardware_Manual_guide/node00A6.html#line42) ) Horizontal line position for HBLANK stop
HBSTRT     1C4      W      A( [E](../Hardware_Manual_guide/node00A6.html#line42) ) Horizontal line position for HBLANK start
HCENTER    1E2      W      A( [E](../Hardware_Manual_guide/node00A6.html#line29) ) Horizontal position for Vsync on interlace
HSSTOP     1C2      W      A( [E](../Hardware_Manual_guide/node00A6.html#line29) ) Horizontal line position for HSYNC stop
HSSTRT     1DE      W      A( [E](../Hardware_Manual_guide/node00A6.html#line29) ) Horizontal sync start (VARHSY)
HTOTAL     1C0      W      A( [E](../Hardware_Manual_guide/node00A6.html#line8) ) Highest number count, horiz. line

```c
                                     (VARBEAMEN=1)
```
