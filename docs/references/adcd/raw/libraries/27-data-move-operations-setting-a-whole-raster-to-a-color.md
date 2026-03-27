# 27 / / Data Move Operations / Setting a Whole Raster to a Color


You can preset a whole raster to a single color by using the function
[SetRast()](../Includes_and_Autodocs_2._guide/node047B.html). A call to this function takes the following form:


```c
    SetRast(&rastPort, pen);
```
As always, the &rastPort is a pointer to the [RastPort](../Libraries_Manual_guide/node034A.html) you wish to use.
Set the pen argument to the color register you want to fill the RastPort
with.

