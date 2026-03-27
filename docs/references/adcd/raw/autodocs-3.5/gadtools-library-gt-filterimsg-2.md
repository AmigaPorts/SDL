# gadtools.library/GT_FilterIMsg



   NAME
	GT_FilterIMsg -- filter an [IntuiMessage](../Includes_and_Autodocs_3._guide/node05E0.html#line762) through GadTools. (V36)

   SYNOPSIS
	modimsg = GT_FilterIMsg(imsg)
	D0                      A1

	struct [IntuiMessage](../Includes_and_Autodocs_3._guide/node05E0.html#line762) *GT_FilterIMsg(struct [IntuiMessage](../Includes_and_Autodocs_3._guide/node05E0.html#line762) *);

   FUNCTION
	NOTE WELL:  Extremely few programs will actually need this function.
	You almost certainly should be using [GT_GetIMsg()](../Includes_and_Autodocs_3._guide/node0280.html) and [GT_ReplyIMsg()](../Includes_and_Autodocs_3._guide/node0283.html)
	only, and not GT_FilterIMsg() and [GT_PostFilterIMsg()](../Includes_and_Autodocs_3._guide/node0281.html).

	GT_FilterIMsg() takes the supplied [IntuiMessage](../Includes_and_Autodocs_3._guide/node05E0.html#line762) and asks the
	[Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213) Toolkit to consider and possibly act on it.  Returns
	NULL if the message was only of significance to a GadTools gadget
	(i.e. not to you), else returns a pointer to a modified IDCMP
	message, which may contain additional information.

	You should examine the Class, Code, and IAddress fields of
	the returned message to learn what happened.  Do not make
	interpretations based on the original imsg.

	You should use [GT_PostFilterIMsg()](../Includes_and_Autodocs_3._guide/node0281.html) to revert to the original
	[IntuiMessage](../Includes_and_Autodocs_3._guide/node05E0.html#line762) once you are done with the modified one.

   INPUTS
	imsg - an [IntuiMessage](../Includes_and_Autodocs_3._guide/node05E0.html#line762) you obtained from a Window's UserPort.

   RESULT
	modimsg - a modified [IntuiMessage](../Includes_and_Autodocs_3._guide/node05E0.html#line762), possibly with extra information
	          from GadTools, or NULL. When NULL, the message passed in to
		  the function should be sent back to Intuition via [ReplyMsg()](../Includes_and_Autodocs_3._guide/node0235.html)

   NOTES
	Starting with V39, this function actually expects and returns
	pointers to [ExtIntuiMessage](../Includes_and_Autodocs_3._guide/node05E0.html#line821) structures, but the prototype was not
	changed for source code compatibility with older software.

   WARNING
	If this function returns NULL, you must call [ReplyMsg()](../Includes_and_Autodocs_3._guide/node0235.html) on the
	[IntuiMessage](../Includes_and_Autodocs_3._guide/node05E0.html#line762) you passed in to GT_FilterIMsg(). That is, if the
	message was processed by the toolkit you must reply this message
	to Intuition since gadtools will not do this automatically.

   SEE ALSO
	[GT_GetIMsg()](../Includes_and_Autodocs_3._guide/node0280.html), [GT_PostFilterIMsg()](../Includes_and_Autodocs_3._guide/node0281.html)

