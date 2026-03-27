# graphics.library/LoadRGB32



   NAME
	LoadRGB32 -- Set a series of color registers for this Viewport. (V39)

   SYNOPSIS
	LoadRGB32(  vp,  table )
	            a0   a1

	void LoadRGB32( struct [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) *, ULONG *);

   INPUTS
	vp = viewport
	table = a pointer to a series of records which describe which colors to
	        modify.
   RESULT
	The selected color registers are changed to match your specs.
   BUGS

   NOTES

	Passing a NULL "table" is ignored.
	The format of the table passed to this function is a series of records,
	each with the following format:

	        1 Word with the number of colors to load
	        1 Word with the first color to be loaded.
	        3 longwords representing a left justified 32 bit rgb triplet.
	        The list is terminated by a count value of 0.

	   examples:
	        ULONG table[]={1l<<16+0,0xffffffff,0,0,0} loads color register
	                0 with 100% red.
	        ULONG table[]={256l<<16+0,r1,g1,b1,r2,g2,b2,.....0} can be used
	                to load an entire 256 color palette.

	Lower order bits of the palette specification will be discarded,
	depending on the color palette resolution of the target graphics
	device. Use 0xffffffff for the full value, 0x7fffffff for 50%,
	etc. You can find out the palette range for your screen by
	querying the graphics data base.

	LoadRGB32 is faster than [SetRGB32](../Includes_and_Autodocs_3._guide/node0328.html), even for one color.

   SEE ALSO
	[LoadRGB4()](../Includes_and_Autodocs_3._guide/node02FC.html) [GetColorMap()](../Includes_and_Autodocs_3._guide/node02E3.html) [GetRGB32()](../Includes_and_Autodocs_3._guide/node02E9.html) [SetRGB32CM()](../Includes_and_Autodocs_3._guide/node0329.html) [graphics/view.h](../Includes_and_Autodocs_3._guide/node05ED.html)

