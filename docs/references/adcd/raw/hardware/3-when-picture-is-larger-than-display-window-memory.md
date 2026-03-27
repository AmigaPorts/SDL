# 3 / / When Picture is Larger than Display Window / Memory Allocation


For larger memory pictures, you need to allocate more memory. Here is a
formula for calculating memory requirements in general:


     bytes per line * lines in playfield * # of bitplanes
The number of bytes must be even.  Thus, if the wide playfield described
in this section is formed from two bitplanes, it requires:


```c
            80 * 200 * 2 = 32,000 bytes of memory
```
Recall that this is the memory requirement for the playfield alone. You
need more memory for any  [sprites](../Hardware_Manual_guide/node00B9.html) ,  [animation](../Hardware_Manual_guide/node011D.html#line45) ,  [audio](../Hardware_Manual_guide/node00DA.html) , or application
programs you are using.

The amount of Chip memory is one of the basic constraints on the size of
playfields.  For instance, a playfield 2000 by 2000 pixels with five
bitplanes would exceed even the two megabytes of Chip memory possible on
an Amiga 3000.  Another constraint on playfield size is the bit plane
modulos which limit the width (but not the height) of a playfield to
262,144 pixels.

As a practical matter, the blitter size registers also limit the size of
playfields (unless the 680x0 CPU is used for drawing operations).  With
the original chip set the largest area the blitter can draw in is 1008 by
1024.  With the Enhanced Chip Set (ECS), the largest area the blitter can
draw in is increased to 16368 by 16384 pixels.  For more information on
ECS and  [blitter limits](../Hardware_Manual_guide/node00AA.html)  refer to Appendix C, Enhanced Chip Set.

