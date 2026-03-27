# 4 / Displaying Sprite / Selecting DMA Channel and Setting Pointers


In deciding which DMA channel to use, you should take into consideration
the colors assigned to the sprite and the  [sprites video priority](../Hardware_Manual_guide/node00C3.html) .

The sprite DMA channel uses two pointers to read in sprite  [data](../Hardware_Manual_guide/node00BC.html)  and
 [control words](../Hardware_Manual_guide/node00B9.html#line24) . During the  [vertical blanking](../Hardware_Manual_guide/node0169.html)  interval before the first
display of the sprite, you need to write the sprite's memory address into
these pointers. The pointers for each sprite are called SPRxPTH and
SPRxPTL, where "x" is the number of the sprite DMA channel. SPRxPTH
contains the high three bits of the memory address of the first word in
the sprite and SPRxPTL contains the low sixteen bits. The least
significant bit of SPRxPTL is ignored, as sprite data must be word
aligned. Thus, only fifteen bits of SPRxPTL are used. As usual, you can
write a long word into SPRxPTH.

In the following example the processor initializes the data pointers for
sprite 0. Normally, this is done by the Copper. The sprite is at address
$20000.


```c
     MOVE.L  #$20000,SPR0PTH+CUSTOM  ;Write $20000 to sprite 0 pointer...
```
These pointers are dynamic; they are incremented by the sprite DMA channel
to point first to the  [control words](../Hardware_Manual_guide/node00B9.html#line24) , then to the  [data words](../Hardware_Manual_guide/node00BC.html) , and
finally to the  [end-of-data words](../Hardware_Manual_guide/node00BD.html) . After reading in the sprite control
information and storing it in other registers, they proceed to read in the
 [color descriptor words](../Hardware_Manual_guide/node00BC.html) . The  [color descriptor words](../Hardware_Manual_guide/node00BC.html)  are stored in
sprite data registers, which are used by the sprite DMA channel to display
the data on screen. For more information about how the sprite DMA channels
handle the display, see the  [Hardware Details](../Hardware_Manual_guide/node00C8.html)  section below.

