# graphics.library/SetRGB32CM



   NAME

```c
       SetRGB32CM -- Set one color register for this [ColorMap](../Includes_and_Autodocs_3._guide/node05ED.html#line142). (V39)
```
   SYNOPSIS

```c
       SetRGB32CM(  cm,  n,   r,    g,    b)
                    a0  d0   d1    d2    d3

       void SetRGB4CM( struct [ColorMap](../Includes_and_Autodocs_3._guide/node05ED.html#line142) *, ULONG, ULONG, ULONG , ULONG);
```
   INPUTS
	cm = colormap
```c
       n = the number of the color register to set. Must not exceed the numbe
```
r of colors
	    allocated for the colormap.

```c
       r = red level (32 bit unsigned left justified fraction)
       g = green level
       b = blue level
```
   RESULT
	Store the (r,g,b) triplet at index n of the [ColorMap](../Includes_and_Autodocs_3._guide/node05ED.html#line142) structure.
```c
       This function can be used to set up a [ColorMap](../Includes_and_Autodocs_3._guide/node05ED.html#line142) before before
```
	linking it into a viewport.

   BUGS

   SEE ALSO

```c
       [GetColorMap()](../Includes_and_Autodocs_3._guide/node02E3.html) [GetRGB32()](../Includes_and_Autodocs_3._guide/node02E9.html) [SetRGB32()](../Includes_and_Autodocs_3._guide/node0328.html) [SetRGB4CM()](../Includes_and_Autodocs_3._guide/node032B.html) [graphics/view.h](../Includes_and_Autodocs_3._guide/node05ED.html)
```
