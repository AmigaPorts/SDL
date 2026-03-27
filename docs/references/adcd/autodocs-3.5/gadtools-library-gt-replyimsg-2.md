---
title: gadtools.library/GT_ReplyIMsg
manual: autodocs-3.5
chapter: autodocs-3.5
section: gadtools-library-gt-replyimsg-2
functions: [CloseWindow, GT_GetIMsg, GT_ReplyIMsg, ReplyMsg]
libraries: [exec.library, gadtools.library, intuition.library]
---

# gadtools.library/GT_ReplyIMsg

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GT_ReplyIMsg -- reply a message obtained with [GT_GetIMsg()](autodocs-3.5/gadtools-library-gt-getimsg-2.md). (V36)

   SYNOPSIS
	GT_ReplyIMsg(imsg)
	             A1

	VOID GT_ReplyIMsg(struct [IntuiMessage](autodocs-3.5/include-intuition-intuition-h.md) *);

   FUNCTION
	Reply a modified [IntuiMessage](autodocs-3.5/include-intuition-intuition-h.md) obtained with [GT_GetIMsg()](autodocs-3.5/gadtools-library-gt-getimsg-2.md).
	If you use [GT_GetIMsg()](autodocs-3.5/gadtools-library-gt-getimsg-2.md), use this function where you would normally
	have used [exec.library/ReplyMsg()](autodocs-3.5/exec-library-replymsg-2.md).
	You may safely call this routine with a NULL pointer (nothing
	will be done).

   INPUTS
	imsg - a modified [IntuiMessage](autodocs-3.5/include-intuition-intuition-h.md) obtained with [GT_GetIMsg()](autodocs-3.5/gadtools-library-gt-getimsg-2.md), or NULL
	       in which case this function does nothing

   NOTES
	When using GadTools, you MUST explicitly GT_ReplyIMsg()
	all messages you receive.  You cannot depend on [CloseWindow()](autodocs-3.5/intuition-library-closewindow-2.md)
	to handle messages you have not replied.

	Starting with V39, this function actually expects a pointer to an
	[ExtIntuiMessage](autodocs-3.5/include-intuition-intuition-h.md) structure, but the prototype was not changed for
	source code compatibility with older software.

   SEE ALSO
	[GT_GetIMsg()](autodocs-3.5/gadtools-library-gt-getimsg-2.md)

---

## See Also

- [CloseWindow — intuition.library](../autodocs/intuition.library.md#closewindow)
- [GT_GetIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_getimsg)
- [GT_ReplyIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_replyimsg)
- [ReplyMsg — exec.library](../autodocs/exec.library.md#replymsg)
