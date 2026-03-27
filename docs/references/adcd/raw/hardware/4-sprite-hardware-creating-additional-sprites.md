# 4 Sprite Hardware / Creating Additional Sprites


To use additional sprites, you must create a  [data structure](../Hardware_Manual_guide/node00B9.html)  for each one
and arrange the display as shown in the previous section, naming the
pointers  [SPR1PTH and SPR1PTL](../Hardware_Manual_guide/node00BF.html#line3)  for sprite DMA channel 1,
 [SPR2PTH and SPR2PTL](../Hardware_Manual_guide/node00BF.html#line3)  for sprite DMA channel 2, and so on.

   About sprite DMA.
   -----------------
   When you enable sprite DMA for one sprite, you enable DMA for all the
   sprites and place them all in  [automatic mode](../Hardware_Manual_guide/node00C8.html#line86) . Thus, you do not need
   to repeat this step when using additional sprite DMA channels.

Once the sprite DMA channels are enabled, all eight sprite pointers must
be initialized to either a real sprite or a safe null sprite. An
uninitialized sprite could cause spurious sprite video to appear.

Remember that some sprites can become unusable when additional DMA cycles
are allocated to displaying the screen, for example when an extra
 [wide display](../Hardware_Manual_guide/node0085.html#line24)  or  [horizontal scrolling](../Hardware_Manual_guide/node0089.html)  is enabled (see
 [Figure 6-9: DMA Time Slot Allocation](../Hardware_Manual_guide/node02D4.html) ).

Also, recall that each pair of sprites takes its color from different
color registers, as shown in Table 4-3.



                Table 4-3: Color Registers for Sprite Pairs


                    Sprite Numbers    Color Registers
                    --------------    ---------------
                       0 and 1            17 - 19
                       2 and 3            21 - 23
                       4 and 5            25 - 27
                       6 and 7            29 - 31
   Warning:
   --------
   Some sprites become unusable when additional DMA cycles are allocated
   to displaying the screen, e.g. when enabling an extra  [wide display](../Hardware_Manual_guide/node0085.html#line24)  or

```c
    [horizontal scrolling](../Hardware_Manual_guide/node0089.html). (See  [Figure 6-9: DMA Time Slot Allocation](../Hardware_Manual_guide/node02D4.html) .)
```
 [Sprite Priority](../Hardware_Manual_guide/node00C3.html) 

