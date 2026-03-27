# intuition.library/EndRefresh



    NAME
	EndRefresh -- End the optimized refresh state of the window.

    SYNOPSIS
	EndRefresh( [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908), Complete )
		    A0      D0

	VOID EndRefresh( struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *, [BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) );

    FUNCTION
	This function gets you out of the special refresh state of your
	window.  It is called following a call to [BeginRefresh()](../Includes_and_Autodocs_3._guide/node0397.html), which
	routine puts you into the special refresh state.  While your window
	is in the refresh state, the only rendering that will be wrought in
	your window will be to those areas which were recently revealed and
	need to be refreshed.

	After you've done all the refreshing you want to do for this window,
	you should call this routine to restore the window to its
	non-refreshing state.  Then all rendering will go to the entire
	window, as usual.

	The 'Complete' argument is a boolean TRUE or FALSE value used to
	describe whether or not the refreshing you've done was all the
	refreshing that needs to be done at this time.  Most often, this
	argument will be TRUE.  But if, for instance, you have multiple
	tasks or multiple procedure calls which must run to completely
	refresh the window, then each can call its own Begin/EndRefresh()
	pair with a Complete argument of FALSE, and only the last calls
	with a Complete argument of TRUE.

	WARNING:  Passing this function the value of FALSE has its
	pitfalls.  Please see the several caveats in the autodoc for
	[BeginRefresh()](../Includes_and_Autodocs_3._guide/node0397.html).

	For your information, this routine calls the Layers library function
	[EndUpdate()](../Includes_and_Autodocs_3._guide/node0421.html), unlocks your layers (calls [UnlockLayerRom()](../Includes_and_Autodocs_3._guide/node0336.html)), clears
	the LAYERREFRESH bit in your [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) Flags, and clears the
	WFLG_WINDOWREFRESH bit in your window Flags.

    INPUTS
	[Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) = pointer to the window currently in optimized-refresh mode
	Complete = Boolean TRUE or FALSE describing whether or not this
           window is completely refreshed

    RESULT
	None

    BUGS

    SEE ALSO
	[BeginRefresh()](../Includes_and_Autodocs_3._guide/node0397.html), [layers.library/EndUpdate()](../Includes_and_Autodocs_3._guide/node0421.html),
	[graphics.library/UnlockLayerRom()](../Includes_and_Autodocs_3._guide/node0336.html)

