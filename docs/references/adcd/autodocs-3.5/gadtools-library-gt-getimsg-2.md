---
title: gadtools.library/GT_GetIMsg
manual: autodocs-3.5
chapter: autodocs-3.5
section: gadtools-library-gt-getimsg-2
functions: [GT_FilterIMsg, GT_GetIMsg, GT_ReplyIMsg, GetMsg, ReplyMsg]
libraries: [exec.library, gadtools.library]
---

# gadtools.library/GT_GetIMsg

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GT_GetIMsg -- get an [IntuiMessage](autodocs-3.5/include-intuition-intuition-h.md), with GadTools processing. (V36)

   SYNOPSIS
	imsg = GT_GetIMsg(intuiport)
	D0                A0

	struct [IntuiMessage](autodocs-3.5/include-intuition-intuition-h.md) *GT_GetIMsg(struct [MsgPort](autodocs-3.5/include-exec-ports-h.md) *);

   FUNCTION
	Use GT_GetIMsg() in place of the usual [exec.library/GetMsg()](autodocs-3.5/exec-library-getmsg-2.md) when
	reading IntuiMessages from your window's UserPort.  If needed,
	the GadTools dispatcher will be invoked, and suitable processing
	will be done for gadget actions.  This function returns a pointer
	to a modified [IntuiMessage](autodocs-3.5/include-intuition-intuition-h.md) (which is a copy of the original,
	possibly with some supplementary information from GadTools).
	If there are no messages (or if the only messages are meaningful
	only to GadTools, NULL will be returned.

   INPUTS
	intuiport - the Window->UserPort of a window that is using the
	            [Gadget](autodocs-3.5/include-intuition-intuition-h.md) Toolkit.

   RESULT
	imsg - pointer to modified [IntuiMessage](autodocs-3.5/include-intuition-intuition-h.md), or NULL if there are
	       no applicable messages.

   NOTES
	Be sure to use [GT_ReplyIMsg()](autodocs-3.5/gadtools-library-gt-replyimsg-2.md) and not [exec.library/ReplyMsg()](autodocs-3.5/exec-library-replymsg-2.md) on
	messages obtained with GT_GetIMsg().
	If you intend to do more with the resulting message than read
	its fields, act on it, and reply it, you may find [GT_FilterIMsg()](autodocs-3.5/gadtools-library-gt-filterimsg-2.md)
	more appropriate.

	Starting with V39, this function actually returns a pointer to an
	[ExtIntuiMessage](autodocs-3.5/include-intuition-intuition-h.md) structure, but the prototype was not changed for
	source code compatibility with older software.

   SEE ALSO
	[GT_ReplyIMsg()](autodocs-3.5/gadtools-library-gt-replyimsg-2.md), [GT_FilterIMsg()](autodocs-3.5/gadtools-library-gt-filterimsg-2.md)

---

## See Also

- [GT_FilterIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_filterimsg)
- [GT_GetIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_getimsg)
- [GT_ReplyIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_replyimsg)
- [GetMsg — exec.library](../autodocs/exec.library.md#getmsg)
- [ReplyMsg — exec.library](../autodocs/exec.library.md#replymsg)
