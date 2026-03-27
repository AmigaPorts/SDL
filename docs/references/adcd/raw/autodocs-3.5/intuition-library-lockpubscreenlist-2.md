# intuition.library/LockPubScreenList



    NAME
	LockPubScreenList -- Prevent changes to the system list. (V36)

    SYNOPSIS
	[List](../Includes_and_Autodocs_3._guide/node0628.html#line19) = LockPubScreenList()
	D0

	struct [List](../Includes_and_Autodocs_3._guide/node0628.html#line19) *LockPubScreenList( VOID );

    FUNCTION
	Arbitrates access to public screen list	while you quickly
	make a copy of it for display to the user.

	Note that this is intended only for the Public [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) Manager
	program.

    NOTES
	The nodes on the list are [PubScreenNode](../Includes_and_Autodocs_3._guide/node0602.html#line548) structures.
	Act quickly while holding this lock.  The restrictions
	on [LockIBase()](../Includes_and_Autodocs_3._guide/node03C0.html) apply here as well.

    INPUTS
	None.

    RESULT
	A pointer to the public screen list.

    BUGS

    SEE ALSO
	[UnlockPubScreenList()](../Includes_and_Autodocs_3._guide/node03FF.html), [OpenScreen()](../Includes_and_Autodocs_3._guide/node03D3.html), Intuition V36 update documentation

