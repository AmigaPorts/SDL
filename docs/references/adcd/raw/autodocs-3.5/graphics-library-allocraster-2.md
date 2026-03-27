# graphics.library/AllocRaster



   NAME
	AllocRaster -- [Allocate](../Includes_and_Autodocs_3._guide/node01E5.html) space for a bitplane.

   SYNOPSIS
	planeptr = AllocRaster( width, height )
	   d0                    d0     d1

	[PLANEPTR](../Includes_and_Autodocs_3._guide/node05DC.html#line43) AllocRaster(ULONG,ULONG);

   FUNCTION
	This function calls the memory allocation routines
	to allocate memory space for a bitplane "width" bits
	wide and "height" bits high.

   INPUTS
	width	- number of columns in bitplane
	height	- number of rows in bitplane

   RESULT
	planeptr - pointer to first word in bitplane, or NULL if
		   it was not possible to allocate the desired
		   amount of memory.

   NOTES
	In order to assure proper alignment of display memory, the
	[AllocBitMap()](../Includes_and_Autodocs_3._guide/node02A0.html) function should be used instead of AllocRaster
	when you wish to allocate display memory (rasters which are
	attached to a [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) or Screen).

   BUGS

   SEE ALSO
	[FreeRaster()](../Includes_and_Autodocs_3._guide/node02DC.html) [graphics/gfx.h](../Includes_and_Autodocs_3._guide/node05DC.html)

