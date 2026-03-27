# gadtools.library/GT_PostFilterIMsg



   NAME
	GT_PostFilterIMsg -- return the unfiltered message after
	                     [GT_FilterIMsg()](../Includes_and_Autodocs_3._guide/node027E.html) was called, and clean up. (V36)

   SYNOPSIS
	imsg = GT_PostFilterIMsg(modimsg)
	D0                       A1

	struct [IntuiMessage](../Includes_and_Autodocs_3._guide/node05E0.html#line762) *GT_PostFilterIMsg(struct [IntuiMessage](../Includes_and_Autodocs_3._guide/node05E0.html#line762) *);

   FUNCTION
	NOTE WELL:  Extremely few programs will actually need this function.
	You almost certainly should be using [GT_GetIMsg()](../Includes_and_Autodocs_3._guide/node0280.html) and [GT_ReplyIMsg()](../Includes_and_Autodocs_3._guide/node0283.html)
	only, and not [GT_FilterIMsg()](../Includes_and_Autodocs_3._guide/node027E.html) and GT_PostFilterIMsg().

	Performs any clean-up necessitated by a previous call to
	[GT_FilterIMsg()](../Includes_and_Autodocs_3._guide/node027E.html).  The original [IntuiMessage](../Includes_and_Autodocs_3._guide/node05E0.html#line762) is now yours to handle.
	Do not interpret the fields of the original [IntuiMessage](../Includes_and_Autodocs_3._guide/node05E0.html#line762), but
	rather use only the one you got from [GT_FilterIMsg()](../Includes_and_Autodocs_3._guide/node027E.html).  You
	may only do message related things at this point, such as queueing
	it up or replying it.  Since you got the message with
	[exec.library/GetMsg()](../Includes_and_Autodocs_3._guide/node0214.html), your responsibilities do include replying
	it with [exec.library/ReplyMsg()](../Includes_and_Autodocs_3._guide/node0235.html). This function may be safely
	called with a NULL parameter.

   INPUTS
	modimsg - a modified [IntuiMessage](../Includes_and_Autodocs_3._guide/node05E0.html#line762) obtained with [GT_FilterIMsg()](../Includes_and_Autodocs_3._guide/node027E.html),
	          or NULL in which case this function does nothing and
	          returns NULL

   RESULT
	imsg - a pointer to the original [IntuiMessage](../Includes_and_Autodocs_3._guide/node05E0.html#line762), if [GT_FilterIMsg()](../Includes_and_Autodocs_3._guide/node027E.html)
	       returned non-NULL.

   NOTES
	Be sure to use [exec.library/ReplyMsg()](../Includes_and_Autodocs_3._guide/node0235.html) on the original [IntuiMessage](../Includes_and_Autodocs_3._guide/node05E0.html#line762)
	you obtained with [GetMsg()](../Includes_and_Autodocs_3._guide/node0214.html), (which is the what you passed to
	[GT_FilterIMsg()](../Includes_and_Autodocs_3._guide/node027E.html)), and not on the parameter of this function.

	Starting with V39, this function actually expects and returns
	pointers to [ExtIntuiMessage](../Includes_and_Autodocs_3._guide/node05E0.html#line821) structures, but the prototype was not
	changed for source code compatibility with older software.

   SEE ALSO
	[GT_FilterIMsg()](../Includes_and_Autodocs_3._guide/node027E.html)

