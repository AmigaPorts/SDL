# 28 / Using Virtual Sprites / Displaying the VSprites


The next few sections explain how to display the VSprites. The following
system functions are used:


```c
    [DrawGList()](../Libraries_Manual_guide/node038D.html)  [Draws](../Libraries_Manual_guide/node038E.html#line2) the VSprites into the current [RastPort](../Libraries_Manual_guide/node034A.html).
       [MrgCop()](../Libraries_Manual_guide/node038E.html)  Installs the VSprites into the display.
     [LoadView()](../Libraries_Manual_guide/node038F.html)  Asks the system to display the new [View](../Libraries_Manual_guide/node00F1.html#line4).
      [WaitTOF()](../Libraries_Manual_guide/node0390.html)  Synchronizes the functions with the display.
```
 [Drawing the Graphics Elements](../Libraries_Manual_guide/node038D.html)    [Loading the New View](../Libraries_Manual_guide/node038F.html) 
 [Merging VSprite Instructions](../Libraries_Manual_guide/node038E.html)     [Synchronizing with the Display](../Libraries_Manual_guide/node0390.html) 

