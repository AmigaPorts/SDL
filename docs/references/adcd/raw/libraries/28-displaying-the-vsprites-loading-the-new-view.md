# 28 / / Displaying the VSprites / Loading the New View


Now that the display instructions include the definition of the VSprites,
the system can display this newly configured [View](../Libraries_Manual_guide/node00F1.html#line4) with the [LoadView()](../Includes_and_Autodocs_2._guide/node0459.html)
function:


```c
    struct View *view;

    LoadView(view);
```
Again, view is a pointer to the [View](../Libraries_Manual_guide/node00F1.html#line4) that contains the the new Copper
instruction list (if you are using GELs in an Intuition Screen, do not
call [LoadView()](../Includes_and_Autodocs_2._guide/node0459.html).)

The Copper instruction lists are double-buffered, so this instruction does
not actually take effect until the next display field occurs. This avoids
the possibility of some function trying to update the Copper instruction
list while the Copper is trying to use it to create the display.

