# 27 / / Using the Graphics Drawing Routines / Reading Individual Pixels


You can determine the color of a specific pixel with a statement like this:


```c
    SHORT x, y;
    LONG result;
    result = ReadPixel(&rastPort, x, y);
```
[ReadPixel()](../Includes_and_Autodocs_2._guide/node046A.html) returns the value of the pixel color selector at the specified
x,y location. If the coordinates you specify are outside the range of your
[RastPort](../Libraries_Manual_guide/node034A.html), this function returns a value of -1.

