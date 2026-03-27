# 27 / / Using the Graphics Drawing Routines / Drawing Individual Pixels


You can set a specific pixel to a desired color by using a statement like
this:


```c
    SHORT x, y;
    LONG result;
    result = WritePixel(&rastPort, x, y);
```
[WritePixel()](../Includes_and_Autodocs_2._guide/node048D.html) uses the primary drawing pen and changes the pixel at that
x,y position to the desired color if the x,y coordinate falls within the
boundaries of the [RastPort](../Libraries_Manual_guide/node034A.html). A value of 0 is returned if the write was
successful; a value of -1 is returned if x,y was outside the range of the
RastPort.

