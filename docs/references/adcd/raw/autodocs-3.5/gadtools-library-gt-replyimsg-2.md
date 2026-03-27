# gadtools.library/GT_ReplyIMsg



   NAME
	GT_ReplyIMsg -- reply a message obtained with [GT_GetIMsg()](../Includes_and_Autodocs_3._guide/node0280.html). (V36)

   SYNOPSIS
	GT_ReplyIMsg(imsg)
	             A1

	VOID GT_ReplyIMsg(struct [IntuiMessage](../Includes_and_Autodocs_3._guide/node05E0.html#line762) *);

   FUNCTION
	Reply a modified [IntuiMessage](../Includes_and_Autodocs_3._guide/node05E0.html#line762) obtained with [GT_GetIMsg()](../Includes_and_Autodocs_3._guide/node0280.html).
	If you use [GT_GetIMsg()](../Includes_and_Autodocs_3._guide/node0280.html), use this function where you would normally
	have used [exec.library/ReplyMsg()](../Includes_and_Autodocs_3._guide/node0235.html).
	You may safely call this routine with a NULL pointer (nothing
	will be done).

   INPUTS
	imsg - a modified [IntuiMessage](../Includes_and_Autodocs_3._guide/node05E0.html#line762) obtained with [GT_GetIMsg()](../Includes_and_Autodocs_3._guide/node0280.html), or NULL
	       in which case this function does nothing

   NOTES
	When using GadTools, you MUST explicitly GT_ReplyIMsg()
	all messages you receive.  You cannot depend on [CloseWindow()](../Includes_and_Autodocs_3._guide/node03A0.html)
	to handle messages you have not replied.

	Starting with V39, this function actually expects a pointer to an
	[ExtIntuiMessage](../Includes_and_Autodocs_3._guide/node05E0.html#line821) structure, but the prototype was not changed for
	source code compatibility with older software.

   SEE ALSO
	[GT_GetIMsg()](../Includes_and_Autodocs_3._guide/node0280.html)

