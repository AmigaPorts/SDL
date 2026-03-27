# graphics.library/LoadRGB4



   NAME
	LoadRGB4 -- Load RGB color values from table.

   SYNOPSIS
	LoadRGB4( vp, colors , count )

                 a0  	a1     d0:16
	void LoadRGB4( struct [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) *, [UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43) *, WORD);

   FUNCTION
   	load the count words of the colormap from table starting at
	entry 0.

   INPUTS
	vp - pointer to [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46), whose colors you wish to change
	colors - pointer to table of RGB values set up as an array
	         of USHORTS
		 	background--  0x0RGB
			color1	  --  0x0RGB
			color2    --  0x0RGB
			 etc.         [UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43) per value.
		The colors are interpreted as 15 = maximum intensity.
		                              0 = minimum intensity.
	count	= number of UWORDs in the table to load into the
	  colormap starting at color 0(background) and proceeding
	  to the next higher color number

   RESULTS
	The [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) should have a pointer to a valid [ColorMap](../Includes_and_Autodocs_3._guide/node05ED.html#line142) to store
	the colors in.
	Updates the hardware copperlist to reflect the new colors.
	Updates the intermediate copperlist with the new colors.

   BUGS

	NOTE: Under V36 and up, it is not safe to call this function
	from an interrupt, due to semaphore protection of graphics
	copper lists.

   SEE ALSO
	[SetRGB4()](../Includes_and_Autodocs_3._guide/node032A.html) [GetRGB4()](../Includes_and_Autodocs_3._guide/node02EA.html) [GetColorMap()](../Includes_and_Autodocs_3._guide/node02E3.html) [graphics/view.h](../Includes_and_Autodocs_3._guide/node05ED.html)

