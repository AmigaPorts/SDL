# 4 Sprite Hardware / Displaying a Sprite


After building the  [data structure](../Hardware_Manual_guide/node00B9.html) , you need to tell the system to
display it. This section describes the display of sprites in
 [automatic mode](../Hardware_Manual_guide/node00C8.html#line86)  . In this mode, once the sprite DMA channel begins to
retrieve and display the data, the display continues until the VSTOP
position is reached.  [Manual mode](../Hardware_Manual_guide/node00C7.html)  is described later on in this chapter.

The following steps are used in displaying the sprite:

   1. Decide which of the eight sprite DMA channels to use (making certain

```c
      that the chosen channel is available).
```
   2. Set the sprite pointers to tell the system where to find the sprite

      data.
   3. Turn on sprite direct memory access if it is not already on.

   4. For each subsequent display field, during the  [vertical blanking](../Hardware_Manual_guide/node0169.html) 

      interval, rewrite the sprite pointers.
   About sprite DMA.
   -----------------
   If sprite DMA is turned off while a sprite is being displayed (that
   is, after VSTART but before VSTOP), the system will continue to
   display the line of sprite data that was most recently fetched. This
   causes a vertical bar to appear on the screen. It is recommended that
   sprite DMA be turned off only during  [vertical blanking](../Hardware_Manual_guide/node0169.html)  or during some
   portion of the display where you are sure that no sprite is being
   displayed.


```c
     [Selecting a DMA Channel and Setting the Pointers](../Hardware_Manual_guide/node00BF.html) 
     [Resetting the Address Pointers](../Hardware_Manual_guide/node00C0.html) 
     [Sprite Display Example](../Hardware_Manual_guide/node02D2.html) 
```
