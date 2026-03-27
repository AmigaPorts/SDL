# 28 / / Displaying the VSprites / Drawing the Graphics Elements


The system function called [DrawGList()](../Includes_and_Autodocs_2._guide/node0438.html) looks through the list of GELS and
prepares the necessary Copper instructions and memory areas to display the
data.  This function is called as follows:


```c
    struct RastPort myRastPort = {0};
    struct ViewPort myViewPort = {0};

    DrawGList(&myRastPort, &myViewPort);
```
The myRastPort argument specifies the [RastPort](../Libraries_Manual_guide/node034A.html) containing the [GelsInfo](../Libraries_Manual_guide/node0377.html#line6)
list with the VSprites that you want to display.  The &myViewPort argument
is a pointer to the [ViewPort](../Libraries_Manual_guide/node00F1.html#line4) for which the VSprites will be created.

