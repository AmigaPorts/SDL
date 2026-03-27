# gadtools.library/GT_EndRefresh



   NAME
	GT_EndRefresh -- end refreshing friendly to GadTools. (V36)

   SYNOPSIS
	GT_EndRefresh(win, complete)
	              A0   D0

	VOID GT_EndRefresh(struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *, [BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) complete);

   FUNCTION
	Invokes the [intuition.library/EndRefresh()](../Includes_and_Autodocs_3._guide/node03AC.html) function in a manner
	friendly to the [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213) Toolkit.  This function call permits
	GadTools gadgets to refresh themselves at the correct time.
	Call this function to [EndRefresh()](../Includes_and_Autodocs_3._guide/node03AC.html) when you have used
	[GT_BeginRefresh()](../Includes_and_Autodocs_3._guide/node027C.html).

   INPUTS
	win - pointer to [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) structure for which a IDCMP_REFRESHWINDOW
	      IDCMP event was received.
	complete - TRUE when done with refreshing.

   SEE ALSO
	[intuition.library/EndRefresh()](../Includes_and_Autodocs_3._guide/node03AC.html)

