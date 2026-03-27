# intuition.library/NextPubScreen



    NAME
	NextPubScreen -- Identify next public screen in the cycle. (V36)

    SYNOPSIS
	Buff = NextPubScreen( [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132), NameBuff )
	D0                    A0      A1

	[UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) *NextPubScreen( struct [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) *, [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) * );

    FUNCTION
	Returns name of next public screen in system rotation, to
	allow visitor windows to provide function to "jump" among
	public-screens in a cycle.

    INPUTS
	[Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) = pointer to the screen your window is currently open in,
	  or NULL, if you don't have a pointer to a public screen.
	NameBuff = pointer to a buffer of MAXPUBSCREENNAME+1 characters,
	  for Intuition to fill in with the name of the next public
	  screen in rotation.

    RESULT
	Returns NULL if there are no public screens, otherwise a
	pointer to your NameBuff.

    NOTES
	There is no guarantee that the public screen whose name
	was returned by this function will exist or be in "public" state
	by the time you call [LockPubScreen()](../Includes_and_Autodocs_3._guide/node03C1.html), etc.  You must handle
	cases where [LockPubScreen()](../Includes_and_Autodocs_3._guide/node03C1.html), etc. will fail.

	Note that this function may return the name of a public screen
	which is open but in "private mode" (see [PubScreenStatus()](../Includes_and_Autodocs_3._guide/node03DA.html) and
	PSNF_PRIVATE).

    BUGS
	Due to a bug, your buffer needs to be (MAXPUBSCREENNAME + 1)
	characters big, which is one more than originally documented.

	The starting screen and cycle order of the public screens isn't
	defined, so do not draw conclusions about the order you
	see in the current version of Intuition.  We reserve the
	right to add meaning to the ordering at a future time.

    SEE ALSO
	[OpenScreen()](../Includes_and_Autodocs_3._guide/node03D3.html), Intuition V36 update documentation

