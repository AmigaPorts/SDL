# rexxsyslib.library/ClearRexxMsg



    NAME
	ClearRexxMsg - Releases and clears the argument array in a [RexxMsg](../Includes_and_Autodocs_3._guide/node0633.html#line97)

    SYNOPSIS
	ClearRexxMsg(msgptr, count)
	             A0      D0

	VOID ClearRexxMsg(struct [RexxMsg](../Includes_and_Autodocs_3._guide/node0633.html#line97) *,ULONG);

    FUNCTION
	This function will [DeleteArgstring()](../Includes_and_Autodocs_3._guide/node054B.html) one or more argstrings from
	the [RexxMsg](../Includes_and_Autodocs_3._guide/node0633.html#line97) and clear the slot.  The count is used to select the
	number of slots to clear.

    INPUTS
	msgptr - A pointer to a [RexxMsg](../Includes_and_Autodocs_3._guide/node0633.html#line97)
	count - The number of slots to be cleared.  The number can be from
	        1 to 16.  (There are 16 slots)

    RESULTS
	All of the slots in the given count will be cleared and the argstring
	will have been released.

    SEE ALSO
	[FillRexxMsg()](../Includes_and_Autodocs_3._guide/node054D.html), [DeleteRexxMsg()](../Includes_and_Autodocs_3._guide/node054C.html), [DeleteArgstring()](../Includes_and_Autodocs_3._guide/node054B.html), [CreateArgstring()](../Includes_and_Autodocs_3._guide/node0549.html)


    BUGS
