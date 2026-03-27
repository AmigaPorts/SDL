# gadtools.library/GT_RefreshWindow



   NAME
	GT_RefreshWindow -- refresh all GadTools gadgets in a window. (V36)

   SYNOPSIS
	GT_RefreshWindow(win, req)
	                 A0   A1

	VOID GT_RefreshWindow(struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *, struct [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143) *);

   FUNCTION
	Perform the initial refresh of all the GadTools gadgets you have
	created.  After you have opened your window, you must call this
	function.  Or, if you have opened your window without gadgets,
	you add the gadgets with [intuition.library/AddGList()](../Includes_and_Autodocs_3._guide/node0393.html),
	refresh them using [intuition.library/RefreshGList()](../Includes_and_Autodocs_3._guide/node03DD.html), then call
	this function.
	You should not need this function at other times.

   INPUTS
	win - pointer to the [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) containing GadTools gadgets.
	req - reserved for future use, should always be NULL

   SEE ALSO
	[GT_BeginRefresh()](../Includes_and_Autodocs_3._guide/node027C.html)

