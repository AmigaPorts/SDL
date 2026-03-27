# graphics.library/SetRGB4




```c
    NAME
       SetRGB4 -- Set one color register for this viewport.

    SYNOPSIS
       SetRGB4(  vp, n,   r,    g,    b)
                 a0  d0  d1:4  d2:4  d3:4
```
	void SetRGB4( struct [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) *, [SHORT](../Includes_and_Autodocs_3._guide/node0654.html#line63), [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50), [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50), [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) );

    FUNCTION
	Change the color look up table so that this viewport displays
	the color (r,g,b) for pen number n.

    INPUTS
	vp - pointer to  viewport structure
```c
       n - the color number (range from 0 to 31)
       r - red level (0-15)
       g - green level (0-15)
       b - blue level (0-15)

    RESULT
```
	If there is a [ColorMap](../Includes_and_Autodocs_3._guide/node05ED.html#line142) for this viewport, then the value will
	be stored in the [ColorMap](../Includes_and_Autodocs_3._guide/node05ED.html#line142).
       The selected color register is changed to match your specs.
	If the color value is unused then nothing will happen.


    BUGS
	NOTE: Under V36 and up, it is not safe to call this function
	from an interrupt, due to semaphore protection of graphics
	copper lists.


```c
    SEE ALSO
       [LoadRGB4()](../Includes_and_Autodocs_3._guide/node02FC.html) [GetRGB4()](../Includes_and_Autodocs_3._guide/node02EA.html) [graphics/view.h](../Includes_and_Autodocs_3._guide/node05ED.html)
```
