# gadtools.library/GT_GetIMsg



   NAME
	GT_GetIMsg -- get an [IntuiMessage](../Includes_and_Autodocs_3._guide/node05E0.html#line762), with GadTools processing. (V36)

   SYNOPSIS
	imsg = GT_GetIMsg(intuiport)
	D0                A0

	struct [IntuiMessage](../Includes_and_Autodocs_3._guide/node05E0.html#line762) *GT_GetIMsg(struct [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) *);

   FUNCTION
	Use GT_GetIMsg() in place of the usual [exec.library/GetMsg()](../Includes_and_Autodocs_3._guide/node0214.html) when
	reading IntuiMessages from your window's UserPort.  If needed,
	the GadTools dispatcher will be invoked, and suitable processing
	will be done for gadget actions.  This function returns a pointer
	to a modified [IntuiMessage](../Includes_and_Autodocs_3._guide/node05E0.html#line762) (which is a copy of the original,
	possibly with some supplementary information from GadTools).
	If there are no messages (or if the only messages are meaningful
	only to GadTools, NULL will be returned.

   INPUTS
	intuiport - the Window->UserPort of a window that is using the
	            [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213) Toolkit.

   RESULT
	imsg - pointer to modified [IntuiMessage](../Includes_and_Autodocs_3._guide/node05E0.html#line762), or NULL if there are
	       no applicable messages.

   NOTES
	Be sure to use [GT_ReplyIMsg()](../Includes_and_Autodocs_3._guide/node0283.html) and not [exec.library/ReplyMsg()](../Includes_and_Autodocs_3._guide/node0235.html) on
	messages obtained with GT_GetIMsg().
	If you intend to do more with the resulting message than read
	its fields, act on it, and reply it, you may find [GT_FilterIMsg()](../Includes_and_Autodocs_3._guide/node027E.html)
	more appropriate.

	Starting with V39, this function actually returns a pointer to an
	[ExtIntuiMessage](../Includes_and_Autodocs_3._guide/node05E0.html#line821) structure, but the prototype was not changed for
	source code compatibility with older software.

   SEE ALSO
	[GT_ReplyIMsg()](../Includes_and_Autodocs_3._guide/node0283.html), [GT_FilterIMsg()](../Includes_and_Autodocs_3._guide/node027E.html)

