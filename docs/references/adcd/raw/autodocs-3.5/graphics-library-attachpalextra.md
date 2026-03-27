# graphics.library/AttachPalExtra



   NAME

```c
       AttachPalExtra -- [Allocate](../Includes_and_Autodocs_3._guide/node01E5.html) and attach a palette sharing structure to a
```
	                  colormap. (V39)


   SYNOPSIS
```c
       status=AttachPalExtra( cm, vp)
```
	                       a0  a1

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) AttachPalExtra( Struct [ColorMap](../Includes_and_Autodocs_3._guide/node05ED.html#line142) *, struct [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) *);

   FUNCTION
	Allocates and attaches a PalExtra structure to a [ColorMap](../Includes_and_Autodocs_3._guide/node05ED.html#line142).
	This is necessary for color palette sharing to work. The
	PalExtra structure will be freed by [FreeColorMap()](../Includes_and_Autodocs_3._guide/node02D7.html).
	The set of available colors will be determined by the mode
	and depth of the viewport.

   INPUTS
	cm  =  A pointer to a color map created by [GetColorMap()](../Includes_and_Autodocs_3._guide/node02E3.html).

	vp   = A pointer to the viewport structure associated with
	       the [ColorMap](../Includes_and_Autodocs_3._guide/node05ED.html#line142).

   RESULTS
	status - 0 if sucessful, else an error number. The only currently
	         defined error number is out of memory (1).

   BUGS

   NOTES
	This function is for use with custom ViewPorts and custom ColorMaps,
	as Intuition attaches a PalExtra to all of its Screens.
	If there is already a PalExtra associated with the [ColorMap](../Includes_and_Autodocs_3._guide/node05ED.html#line142), then
	this function will do nothing.

   SEE ALSO
	[GetColorMap()](../Includes_and_Autodocs_3._guide/node02E3.html) [FreeColorMap()](../Includes_and_Autodocs_3._guide/node02D7.html) [ObtainPen()](../Includes_and_Autodocs_3._guide/node0307.html) [ObtainBestPenA()](../Includes_and_Autodocs_3._guide/node0306.html)

