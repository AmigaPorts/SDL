# graphics.library/SetRGB4CM



   NAME

```c
       SetRGB4CM -- Set one color register for this [ColorMap](../Includes_and_Autodocs_3._guide/node05ED.html#line142).
```
   SYNOPSIS

```c
       SetRGB4CM(  cm,  n,   r,    g,    b)
                   a0  d0  d1:4  d2:4  d3:4

       void SetRGB4CM( struct [ColorMap](../Includes_and_Autodocs_3._guide/node05ED.html#line142) *, [SHORT](../Includes_and_Autodocs_3._guide/node0654.html#line63), [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50), [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50), [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) );
```
   INPUTS
	cm = colormap
```c
       n = the number of the color register to set. Ranges from 0 to 31
```
	    on current Amiga displays.

```c
       r = red level (0-15)
       g = green level (0-15)
       b = blue level (0-15)
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
       [GetColorMap()](../Includes_and_Autodocs_3._guide/node02E3.html) [GetRGB4()](../Includes_and_Autodocs_3._guide/node02EA.html) [SetRGB4()](../Includes_and_Autodocs_3._guide/node032A.html) [graphics/view.h](../Includes_and_Autodocs_3._guide/node05ED.html)
```
