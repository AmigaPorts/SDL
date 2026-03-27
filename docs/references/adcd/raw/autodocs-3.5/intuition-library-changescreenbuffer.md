# intuition.library/ChangeScreenBuffer



    NAME
	ChangeScreenBuffer -- Swap the screen's [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45). (V39)

    SYNOPSIS
	success = ChangeScreenBuffer( [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132), [ScreenBuffer](../Includes_and_Autodocs_3._guide/node0602.html#line644) )
	D0                            A0      A1

	ULONG ChangeScreenBuffer( struct [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) *, struct [ScreenBuffer](../Includes_and_Autodocs_3._guide/node0602.html#line644) * );

    FUNCTION
	Performs double (or multiple) buffering on an Intuition screen
	in an Intuition-cooperative manner.  The [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45) associated
	with the supplied [ScreenBuffer](../Includes_and_Autodocs_3._guide/node0602.html#line644) will be installed in the
	specified screen, if possible.  The previously-installed [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45)
	is available for re-use upon receiving a signal from
	graphics.library.  See the graphics.library autodocs for
	[graphics.library/AllocDBufInfo()](../Includes_and_Autodocs_3._guide/node02A1.html) and [graphics.library/ChangeVPBitMap()](../Includes_and_Autodocs_3._guide/node02BD.html)
	for details.

    INPUTS
	Screen: pointer to the screen whose bitmap is to be swapped.
	ScreenBuffer: pointer to a [ScreenBuffer](../Includes_and_Autodocs_3._guide/node0602.html#line644) structure obtained from
	    [AllocScreenBuffer()](../Includes_and_Autodocs_3._guide/node0395.html).

    RESULT
	Returns non-zero if the operation succeeded.  Returns zero
	if the operation cannot be performed.  This function will
	fail if Intuition's state cannot permit it, for example the
	user is playing with menus or gadgets.

    NOTES
	It is not required to restore the original [ScreenBuffer](../Includes_and_Autodocs_3._guide/node0602.html#line644)
	before closing the screen. Simply [FreeScreenBuffer()](../Includes_and_Autodocs_3._guide/node03B1.html) each
	buffer (including the original and the currently-installed one)
	then close the screen.	Of course, you cannot call
	ChangeScreenBuffer() after freeing the currently-installed one.

    BUGS

    SEE ALSO
	[AllocScreenBuffer()](../Includes_and_Autodocs_3._guide/node0395.html), [FreeScreenBuffer()](../Includes_and_Autodocs_3._guide/node03B1.html),
	[graphics.library/ChangeVPBitMap()](../Includes_and_Autodocs_3._guide/node02BD.html)

