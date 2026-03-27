# intuition.library/MakeScreen



    NAME
	MakeScreen -- Do an Intuition-integrated [MakeVPort()](../Includes_and_Autodocs_3._guide/node02FF.html) of a screen.

    SYNOPSIS
	failure = MakeScreen( [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) )
	D0 (V39)              A0

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) MakeScreen( struct [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) * );
	/* Returns [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) in V39 and greater */

    FUNCTION
	This procedure allows you to do a [MakeVPort()](../Includes_and_Autodocs_3._guide/node02FF.html) for the viewport of your
	custom screen in an Intuition-integrated way.  This way you can
	do your own screen manipulations without worrying about interference
	with Intuition's usage of the same viewport.

	The operation of this function is as follows:
	    - Block until the Intuition [View](../Includes_and_Autodocs_3._guide/node05ED.html#line63) structure is not in being changed.
	    - Set the view modes correctly to reflect if there is a (visible)
	      interlaced screen.
	    - call [MakeVPort()](../Includes_and_Autodocs_3._guide/node02FF.html), passing the Intuition [View](../Includes_and_Autodocs_3._guide/node05ED.html#line63) and your screen's
	      [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46).
	    - Unlocks the Intuition [View](../Includes_and_Autodocs_3._guide/node05ED.html#line63).

	After calling this routine, you should call [RethinkDisplay()](../Includes_and_Autodocs_3._guide/node03E7.html) to
	incorporate the new viewport of your custom screen into the
	Intuition display.

	NOTE: Intuition may determine that because of a change in global
	interlace needs that all viewports need to be remade, so
	it may effectively call [RemakeDisplay()](../Includes_and_Autodocs_3._guide/node03E0.html).

    INPUTS
	[Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) = address of the custom screen structure

    RESULT
	Starting with V39, returns zero for success, non-zero for failure.
	Probable cause of failure is failure of [graphics.library/MakeVPort()](../Includes_and_Autodocs_3._guide/node02FF.html).
	Prior to V39, the return code is invalid.  Do not interpret it when
	running on pre-V39 systems!

    BUGS

    SEE ALSO
	[RethinkDisplay()](../Includes_and_Autodocs_3._guide/node03E7.html), [RemakeDisplay()](../Includes_and_Autodocs_3._guide/node03E0.html), [graphics.library/MakeVPort()](../Includes_and_Autodocs_3._guide/node02FF.html)

