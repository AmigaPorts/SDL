# graphics.library/InitView



   NAME   
   InitView - Initialize [View](../Includes_and_Autodocs_3._guide/node05ED.html#line63) structure.

   SYNOPSIS
	InitView( view )
		   a1

	void InitView( struct [View](../Includes_and_Autodocs_3._guide/node05ED.html#line63) * );

   FUNCTION
	Initialize [View](../Includes_and_Autodocs_3._guide/node05ED.html#line63) structure to default values.

   INPUTS
	view - pointer to a [View](../Includes_and_Autodocs_3._guide/node05ED.html#line63) structure

   RESULT
	[View](../Includes_and_Autodocs_3._guide/node05ED.html#line63) structure set to all 0's. (1.0,1.1.1.2)
	Then values are put in DxOffset,DyOffset to properly position
	default display about .5 inches from top and left on monitor.
	InitView pays no attention to previous contents of view.

   BUGS

   SEE ALSO
 	[MakeVPort](../Includes_and_Autodocs_3._guide/node02FF.html) [graphics/view.h](../Includes_and_Autodocs_3._guide/node05ED.html)

