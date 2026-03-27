# intuition.library/RethinkDisplay



    NAME
	RethinkDisplay -- Grand manipulation of the entire Intuition display.

    SYNOPSIS
	failure = RethinkDisplay()
	D0 (V39)

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) RethinkDisplay( VOID );
	/* Returns [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) in V39 and greater */

    FUNCTION
	This function performs the Intuition global display reconstruction.
	This includes rethinking about all of the  ViewPorts and their
	relationship to one another and reconstructing the entire display
	based on the results of this rethinking.

	Specifically, and omitting many internal details, the operation
	consists of this:

	    Determine which ViewPorts are invisible and set their VP_HIDE
	    [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) Mode flag. VP_HIDE flags are also set for screens that
	    may not be simultaneously displayed with the frontmost (V36).

	    If a change to a viewport height, or changing interlace or
	    monitor scan rates require, [MakeVPort()](../Includes_and_Autodocs_3._guide/node02FF.html) is called for specific
	    screen viewports.  After this phase, the intermediate Copper lists
	    for each screen's viewport are correctly set up.

	    [MrgCop()](../Includes_and_Autodocs_3._guide/node0303.html) and [LoadView()](../Includes_and_Autodocs_3._guide/node02FD.html) are then called to get these Copper lists
	    in action, thus establishing the new state of the Intuition
	    display.

	You may perform a [MakeScreen()](../Includes_and_Autodocs_3._guide/node03C4.html) on your [Custom](../Includes_and_Autodocs_3._guide/node05F6.html#line24) [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) before calling
	this routine.  The results will be incorporated in the new display, but
	changing the INTERLACE [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) mode for one screens must be reflected
	in the Intuition [View](../Includes_and_Autodocs_3._guide/node05ED.html#line63), which is left to Intuition.

	WARNING:  This routine can take several milliseconds to run, so
	do not use it lightly.

	New for V36: This routine is substantially changed to support
	new screen modes.  In particular, if screen rearrangement has
	caused a change in interlace mode or scan rate, this routine
	will remake the copper lists for each screen's viewport.

    INPUTS
	None

    RESULT
	Starting with V39, returns zero for success, non-zero for failure.
	Probable cause of failure is failure of [graphics.library/MakeVPort()](../Includes_and_Autodocs_3._guide/node02FF.html)
	or of [graphics.library/MrgCop()](../Includes_and_Autodocs_3._guide/node0303.html).
	Prior to V39, the return code is invalid.  Do not interpret it when
	running on pre-V39 systems!

    BUGS
	In V35 and earlier, an interlaced screen coming to the front
	may not trigger a complete remake as required when the global
	interlace state is changed.  In some cases, this can be compensated
	for by setting the viewport DHeight field to 0 for hidden screens.

    SEE ALSO
	[RemakeDisplay()](../Includes_and_Autodocs_3._guide/node03E0.html), [graphics.library/MakeVPort()](../Includes_and_Autodocs_3._guide/node02FF.html), [graphics.library/MrgCop()](../Includes_and_Autodocs_3._guide/node0303.html),
	[graphics.library/LoadView()](../Includes_and_Autodocs_3._guide/node02FD.html), [MakeScreen()](../Includes_and_Autodocs_3._guide/node03C4.html)

