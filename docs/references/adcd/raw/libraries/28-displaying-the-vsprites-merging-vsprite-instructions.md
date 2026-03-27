# 28 / / Displaying the VSprites / Merging VSprite Instructions


Once [DrawGList()](../Libraries_Manual_guide/node038C.html) has prepared the necessary instructions and memory areas
to display the data, the VSprites are installed into the display with
[MrgCop()](../Includes_and_Autodocs_2._guide/node045F.html).  (DrawGList() does not actually draw the VSprites, it only
prepares the Copper instructions.)


```c
    struct View *view;

    MrgCop(view);
```
The view is a pointer to the [View](../Libraries_Manual_guide/node00F1.html#line4) structure whose Copper instructions are
to be merged.

