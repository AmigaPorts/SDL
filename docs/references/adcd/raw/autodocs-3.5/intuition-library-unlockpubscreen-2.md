# intuition.library/UnlockPubScreen



    NAME
	UnlockPubScreen -- Release lock on a public screen. (V36)

    SYNOPSIS
	UnlockPubScreen( Name, [Screen] )
			 A0    A1

	VOID UnlockPubScreen( [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) *, struct [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) * );

    FUNCTION
	Releases lock gotten by [LockPubScreen()](../Includes_and_Autodocs_3._guide/node03C1.html).
	It is best to identify the locked public screen by
	the pointer returned from [LockPubScreen()](../Includes_and_Autodocs_3._guide/node03C1.html).  To do this,
	supply a NULL 'Name' pointer and the screen pointer.

	In rare circumstances where it would be more convenient to pass
	a non-NULL pointer to the public screen name string, the
	'Screen' parameter is ignored.

    INPUTS
	Name = pointer to name of public screen.  If Name is NULL,
	    then argument 'Screen' is used as a direct pointer to
	    a public screen.
	[Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) = pointer to a public screen.  Used only if Name
	    is NULL.  This pointer MUST have been returned
	    by [LockPubScreen()](../Includes_and_Autodocs_3._guide/node03C1.html).
	    It is safe to call UnlockPubScreen() with NULL Name
	    and [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) (the function will have no effect).

    RESULT

    BUGS

    SEE ALSO
	[LockPubScreen()](../Includes_and_Autodocs_3._guide/node03C1.html)

