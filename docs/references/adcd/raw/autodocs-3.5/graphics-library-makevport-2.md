# graphics.library/MakeVPort



   NAME
	MakeVPort -- generate display copper list for a viewport.

   SYNOPSIS
	error =  MakeVPort( view, viewport )
	 d0                   a0     a1

	ULONG MakeVPort( struct [View](../Includes_and_Autodocs_3._guide/node05ED.html#line63) *, struct [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) * );

   FUNCTION
	Uses information in the [View](../Includes_and_Autodocs_3._guide/node05ED.html#line63), [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46), ViewPort->RasInfo to
	construct and intermediate copper list for this [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46).

   INPUTS
	view - pointer to a [View](../Includes_and_Autodocs_3._guide/node05ED.html#line63) structure
	viewport - pointer to a [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) structure
		 The viewport must have valid pointer to a RasInfo.

   RESULTS
	constructs intermediate copper list and puts pointers in
	viewport.DspIns
	If the [ColorMap](../Includes_and_Autodocs_3._guide/node05ED.html#line142) ptr in [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) is NULL then it uses colors
	from the default color table.
	If DUALPF in Modes then there must be a second RasInfo pointed
	to by the first RasInfo

	From V39, MakeVPort can return a ULONG error value (previous versions
	returned void), to indicate that either not enough memory could be
	allocated for MakeVPort's use, or that the [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) mode
	and bitplane alignments are incorrect for the bitplane's depth.

	You should check for these error values - they are defined in
	[<graphics/view.h>](../Includes_and_Autodocs_3._guide/node05ED.html).


   BUGS
	In V37 and earlier, narrow Viewports (whose righthand edge is
	less than 3/4 of the way across the display) do not work properly.

   SEE ALSO
	[InitVPort()](../Includes_and_Autodocs_3._guide/node02FA.html) [MrgCop()](../Includes_and_Autodocs_3._guide/node0303.html) [graphics/view.h](../Includes_and_Autodocs_3._guide/node05ED.html) [intuition.library/MakeScreen()](../Includes_and_Autodocs_3._guide/node03C4.html)
	[intuition.library/RemakeDisplay()](../Includes_and_Autodocs_3._guide/node03E0.html) [intuition.library/RethinkDisplay()](../Includes_and_Autodocs_3._guide/node03E7.html)

