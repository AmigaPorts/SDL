# graphics.library/CalcIVG



   NAME
	CalcIVG -- Calculate the number of blank lines above a [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) (V39)

   SYNOPSIS
	count = CalcIVG(View, ViewPort)
	 d0.w           a0    a1

	[UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43) CalcIVG(struct [View](../Includes_and_Autodocs_3._guide/node05ED.html#line63) *, struct [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) *);

   FUNCTION
	To calculate the maximum number of blank lines above a viewport needed to
	load all the copper instructions, after accounting for the viewport
	bandwidth and size.

   INPUTS
	[View](../Includes_and_Autodocs_3._guide/node05ED.html#line63)       - pointer to the [View](../Includes_and_Autodocs_3._guide/node05ED.html#line63)
	[ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46)   - pointer to the [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) you are interested in.

   RESULT
	count      - the number of [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) resolution scan lines needed to
	             execute all the copper instructions for [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46),
	             or 0 if any error.

   NOTES
	The number of copper instructions comes from the vp->vp_DspIns list.
	Although there may be other copper instructions in the final list (from
	UCopIns, SprIns and ClrIns) they are currently ignored for this
	function. This also means that if the [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) has never been made
	(for example, the [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) of an intuition screen was opened behind)
	then vp->vp_DspIns is NULL.

	Although CalcIVG() returns the true number of lines needed by the
	copper, intuition still maintains an inter-screen gap of 3 non-laced
	lines (6 interlaced). Therefore, for intuition screens use:
	MAX(CalcIVG(v, vp), (islaced ? 6 : 3))


   SEE ALSO
	[GfxNew()](../Includes_and_Autodocs_3._guide/node02F1.html)  [VideoControl()](../Includes_and_Autodocs_3._guide/node0338.html)  [graphics/view.h](../Includes_and_Autodocs_3._guide/node05ED.html)

