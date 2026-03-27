# 28 / Using Virtual Sprites / Getting the VSprite List In Order


When the system has displayed the last line of a VSprite, it is able to
reassign the hardware sprite to another VSprite located at a lower
position on the screen.  The system allocates hardware sprites in the
order in which it encounters the VSprites in the list.  Therefore, the
list of VSprites must be sorted before the system can assign the use of
the hardware Sprites correctly.

The function [SortGList()](../Includes_and_Autodocs_2._guide/node047F.html) must be used to get the GELs in the correct order
before the system is asked to display them.  This sorting step is
essential!  It should be done before calling [DrawGList()](../Libraries_Manual_guide/node038C.html), whenever a GEL
has changed position.  This function is called as follows:


```c
    struct RastPort myRastPort = {0};

    SortGList(&myRastPort);
```
The only argument is a pointer to the [RastPort](../Libraries_Manual_guide/node034A.html) structure containing the
[GelsInfo](../Libraries_Manual_guide/node0377.html#line6).

