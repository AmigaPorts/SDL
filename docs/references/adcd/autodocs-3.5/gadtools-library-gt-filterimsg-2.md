---
title: gadtools.library/GT_FilterIMsg
manual: autodocs-3.5
chapter: autodocs-3.5
section: gadtools-library-gt-filterimsg-2
functions: [GT_FilterIMsg, GT_GetIMsg, GT_PostFilterIMsg, GT_ReplyIMsg, ReplyMsg]
libraries: [exec.library, gadtools.library]
---

# gadtools.library/GT_FilterIMsg

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GT_FilterIMsg -- filter an [IntuiMessage](autodocs-3.5/include-intuition-intuition-h.md) through GadTools. (V36)

   SYNOPSIS
	modimsg = GT_FilterIMsg(imsg)
	D0                      A1

	struct [IntuiMessage](autodocs-3.5/include-intuition-intuition-h.md) *GT_FilterIMsg(struct [IntuiMessage](autodocs-3.5/include-intuition-intuition-h.md) *);

   FUNCTION
	NOTE WELL:  Extremely few programs will actually need this function.
	You almost certainly should be using [GT_GetIMsg()](autodocs-3.5/gadtools-library-gt-getimsg-2.md) and [GT_ReplyIMsg()](autodocs-3.5/gadtools-library-gt-replyimsg-2.md)
	only, and not GT_FilterIMsg() and [GT_PostFilterIMsg()](autodocs-3.5/gadtools-library-gt-postfilterimsg-2.md).

	GT_FilterIMsg() takes the supplied [IntuiMessage](autodocs-3.5/include-intuition-intuition-h.md) and asks the
	[Gadget](autodocs-3.5/include-intuition-intuition-h.md) Toolkit to consider and possibly act on it.  Returns
	NULL if the message was only of significance to a GadTools gadget
	(i.e. not to you), else returns a pointer to a modified IDCMP
	message, which may contain additional information.

	You should examine the Class, Code, and IAddress fields of
	the returned message to learn what happened.  Do not make
	interpretations based on the original imsg.

	You should use [GT_PostFilterIMsg()](autodocs-3.5/gadtools-library-gt-postfilterimsg-2.md) to revert to the original
	[IntuiMessage](autodocs-3.5/include-intuition-intuition-h.md) once you are done with the modified one.

   INPUTS
	imsg - an [IntuiMessage](autodocs-3.5/include-intuition-intuition-h.md) you obtained from a Window's UserPort.

   RESULT
	modimsg - a modified [IntuiMessage](autodocs-3.5/include-intuition-intuition-h.md), possibly with extra information
	          from GadTools, or NULL. When NULL, the message passed in to
		  the function should be sent back to Intuition via [ReplyMsg()](autodocs-3.5/exec-library-replymsg-2.md)

   NOTES
	Starting with V39, this function actually expects and returns
	pointers to [ExtIntuiMessage](autodocs-3.5/include-intuition-intuition-h.md) structures, but the prototype was not
	changed for source code compatibility with older software.

   WARNING
	If this function returns NULL, you must call [ReplyMsg()](autodocs-3.5/exec-library-replymsg-2.md) on the
	[IntuiMessage](autodocs-3.5/include-intuition-intuition-h.md) you passed in to GT_FilterIMsg(). That is, if the
	message was processed by the toolkit you must reply this message
	to Intuition since gadtools will not do this automatically.

   SEE ALSO
	[GT_GetIMsg()](autodocs-3.5/gadtools-library-gt-getimsg-2.md), [GT_PostFilterIMsg()](autodocs-3.5/gadtools-library-gt-postfilterimsg-2.md)

---

## See Also

- [GT_FilterIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_filterimsg)
- [GT_GetIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_getimsg)
- [GT_PostFilterIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_postfilterimsg)
- [GT_ReplyIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_replyimsg)
- [ReplyMsg — exec.library](../autodocs/exec.library.md#replymsg)
