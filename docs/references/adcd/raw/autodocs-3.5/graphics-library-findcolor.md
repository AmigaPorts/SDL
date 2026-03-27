# graphics.library/FindColor



   NAME
	FindColor -- Find the closest matching color in a colormap. (V39)

   SYNOPSIS
	color = FindColor(  cm,  R,   G,    B , maxpen)
	                   a3   d1   d2    d3   d4

	ULONG FindColor( struct [ColorMap](../Includes_and_Autodocs_3._guide/node05ED.html#line142) *, ULONG, ULONG, ULONG,LONG);

   INPUTS
	cm = colormap
	R = red level   (32 bit left justified fraction)
	G = green level (32 bit left justified fraction)
	B = blue level  (32 bit left justified fraction)
	MaxPen = the maximum entry in the color table to search. A value of
	        -1 will limt the search to only those pens which could be
	        rendered in (for instance, it will not examine the sprite
	        colors on a 4 color screen).


   RESULT
	The system will attempt to find the color in the passed colormap
	which most closely matches the RGB values passed. No new pens will
	be allocated, and you should not [ReleasePen()](../Includes_and_Autodocs_3._guide/node0314.html) the returned pen.
	This function is not sensitive to palette sharing issues. Its
	intended use is for:

	        (a) programs which pop up on public screens when those
	            screens are not using palette sharing. You might
	            use this function as a fallback when [ObtainBestPenA()](../Includes_and_Autodocs_3._guide/node0306.html)
	            says that there are no sharable pens.

	        (b) Internal color matching by an application which is
	            either running on a non-public screen, or which
	            wants to match colors to an internal color table
	            which may not be associated with any displayed screen.

   BUGS

   NOTES
	In order to use the MaxPen=-1 feature, you must have initialized
	palette sharing via [AttachPalExtra()](../Includes_and_Autodocs_3._guide/node02AE.html) (all intuition screens do this).
	Otherwise, MaxPen=-1 will search all colors in the colormap.


   SEE ALSO
	[ObtainBestPenA()](../Includes_and_Autodocs_3._guide/node0306.html) [GetColorMap()](../Includes_and_Autodocs_3._guide/node02E3.html) [ObtainPen()](../Includes_and_Autodocs_3._guide/node0307.html) [ReleasePen()](../Includes_and_Autodocs_3._guide/node0314.html)

