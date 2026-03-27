# graphics.library/SetRGB32



   NAME
	SetRGB32 -- Set one color register for this Viewport. (V39)

   SYNOPSIS
	SetRGB32(  vp,  n,   r,    g,    b)
	           a0  d0   d1    d2    d3

	void SetRGB32( struct [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) *, ULONG, ULONG, ULONG, ULONG );

   INPUTS
	vp = viewport
	n = the number of the color register to set.
	r = red level   (32 bit left justified fraction)
	g = green level (32 bit left justified fraction)
	b = blue level  (32 bit left justified fraction)

   RESULT
	If there is a [ColorMap](../Includes_and_Autodocs_3._guide/node05ED.html#line142) for this viewport, then the value will
	be stored in the [ColorMap](../Includes_and_Autodocs_3._guide/node05ED.html#line142).
	The selected color register is changed to match your specs.
	If the color value is unused then nothing will happen.

   BUGS

   NOTES
	Lower order bits of the palette specification will be discarded,
	depending on the color palette resolution of the target graphics
	device. Use 0xffffffff for the full value, 0x7fffffff for 50%,
	etc. You can find out the palette range for your screen by
	querying the graphics data base.

   SEE ALSO
	[GetColorMap()](../Includes_and_Autodocs_3._guide/node02E3.html) [GetRGB32()](../Includes_and_Autodocs_3._guide/node02E9.html) [SetRGB32CM()](../Includes_and_Autodocs_3._guide/node0329.html) [LoadRGB32()](../Includes_and_Autodocs_3._guide/node02FB.html) [graphics/view.h](../Includes_and_Autodocs_3._guide/node05ED.html)

