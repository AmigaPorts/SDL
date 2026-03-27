# graphics.library/GetRGB32



   NAME
	GetRGB32 -- Set a series of color registers for this Viewport. (V39)

   SYNOPSIS
	GetRGB32(  cm,  firstcolor, ncolors, table )
	           a0   d0   		d1    a1


```c
       void GetRGB32( struct [ColorMap](../Includes_and_Autodocs_3._guide/node05ED.html#line142) *, ULONG, ULONG, ULONG *);
```
   INPUTS
	cm = colormap
	firstcolor = the first color register to get
	ncolors = the number of color registers to set.
	table=a pointer to a series of 32-bit RGB triplets.

   RESULT
	The ULONG data pointed to by 'table' will be filled with the 32 bit
	fractional RGB values from the colormap.
   BUGS

   NOTES
	'Table' should point to at least ncolors*3 longwords.

   SEE ALSO
	[LoadRGB4()](../Includes_and_Autodocs_3._guide/node02FC.html) [GetColorMap()](../Includes_and_Autodocs_3._guide/node02E3.html) [LoadRGB32()](../Includes_and_Autodocs_3._guide/node02FB.html) [SetRGB32CM()](../Includes_and_Autodocs_3._guide/node0329.html) [graphics/view.h](../Includes_and_Autodocs_3._guide/node05ED.html)

