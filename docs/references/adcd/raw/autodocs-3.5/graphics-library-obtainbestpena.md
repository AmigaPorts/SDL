# graphics.library/ObtainBestPenA



   NAME
	ObtainBestPenA --- Search for the closest color match, or allocate a
	                   new one. (V39)
	ObtainBestPen  --- varargs stub for ObtainBestPenA

   SYNOPSIS
	color | -1 =ObtainBestPenA(  cm,  R,   G,    B,    taglist)
	                             a0   d1   d2    d3       a1

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) ObtainBestPenA( struct [ColorMap](../Includes_and_Autodocs_3._guide/node05ED.html#line142) *, ULONG, ULONG,
			ULONG, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *);

	color = ObtainBestPen(cm,r,g,b,tags....);

   INPUTS
	cm = colormap
	R = red level   (32 bit left justified fraction)
	G = green level (32 bit left justified fraction)
	B = blue level  (32 bit left justified fraction)
	taglist = a pointer to a standard tag list specifying the color
	          matching settings desired:

	        OBP_Precision - specifies the desired precision for the
	                match. Should be PRECISION_GUI, PRECISION_ICON, or
	                PRECISION_IMAGE or PRECISION_EXACT.
	                Defaults to PRECISION_IMAGE.

	        OBP_FailIfBad - specifies that you want ObtainBestPen to return
	                a failure value if there is not a color within the
	                given tolerance, instead of returning the closest color.
	                With OBP_FailIfBad==FALSE, ObtainBestPen will only fail
	                if the [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) contains no sharable colors.
	                Defaults to FALSE.


   FUNCTION
	This function can be used by applications to figure out
	what pen to use to represent a given color.

	The system will attempt to find the color in your viewport closest
	to the specified color. If there is no color within your tolerance,
	then a new one will be allocated, if available. If none is available,
	then the closest one found will be returned.

   RESULT
	The correct pen value, or -1 if no sharable palette entries are available.


   BUGS

   NOTES
	If this call succceeds, then you must call [ReleasePen()](../Includes_and_Autodocs_3._guide/node0314.html) when you are
	done with the color.

	The error metric used for ObtainBestPen() is based on the magnitude
	squared between the two RGB values, scaled by the percentage of free
	entries.

   SEE ALSO
	[GetColorMap()](../Includes_and_Autodocs_3._guide/node02E3.html) [ObtainPen()](../Includes_and_Autodocs_3._guide/node0307.html) [ReleasePen()](../Includes_and_Autodocs_3._guide/node0314.html)

