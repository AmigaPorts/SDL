---
title: gadtools.library/GT_PostFilterIMsg
manual: autodocs-3.5
chapter: autodocs-3.5
section: gadtools-library-gt-postfilterimsg-2
functions: [GT_FilterIMsg, GT_GetIMsg, GT_PostFilterIMsg, GT_ReplyIMsg, GetMsg, ReplyMsg]
libraries: [exec.library, gadtools.library]
---

# gadtools.library/GT_PostFilterIMsg

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GT_PostFilterIMsg -- return the unfiltered message after
	                     [GT_FilterIMsg()](autodocs-3.5/gadtools-library-gt-filterimsg-2.md) was called, and clean up. (V36)

   SYNOPSIS
	imsg = GT_PostFilterIMsg(modimsg)
	D0                       A1

	struct [IntuiMessage](autodocs-3.5/include-intuition-intuition-h.md) *GT_PostFilterIMsg(struct [IntuiMessage](autodocs-3.5/include-intuition-intuition-h.md) *);

   FUNCTION
	NOTE WELL:  Extremely few programs will actually need this function.
	You almost certainly should be using [GT_GetIMsg()](autodocs-3.5/gadtools-library-gt-getimsg-2.md) and [GT_ReplyIMsg()](autodocs-3.5/gadtools-library-gt-replyimsg-2.md)
	only, and not [GT_FilterIMsg()](autodocs-3.5/gadtools-library-gt-filterimsg-2.md) and GT_PostFilterIMsg().

	Performs any clean-up necessitated by a previous call to
	[GT_FilterIMsg()](autodocs-3.5/gadtools-library-gt-filterimsg-2.md).  The original [IntuiMessage](autodocs-3.5/include-intuition-intuition-h.md) is now yours to handle.
	Do not interpret the fields of the original [IntuiMessage](autodocs-3.5/include-intuition-intuition-h.md), but
	rather use only the one you got from [GT_FilterIMsg()](autodocs-3.5/gadtools-library-gt-filterimsg-2.md).  You
	may only do message related things at this point, such as queueing
	it up or replying it.  Since you got the message with
	[exec.library/GetMsg()](autodocs-3.5/exec-library-getmsg-2.md), your responsibilities do include replying
	it with [exec.library/ReplyMsg()](autodocs-3.5/exec-library-replymsg-2.md). This function may be safely
	called with a NULL parameter.

   INPUTS
	modimsg - a modified [IntuiMessage](autodocs-3.5/include-intuition-intuition-h.md) obtained with [GT_FilterIMsg()](autodocs-3.5/gadtools-library-gt-filterimsg-2.md),
	          or NULL in which case this function does nothing and
	          returns NULL

   RESULT
	imsg - a pointer to the original [IntuiMessage](autodocs-3.5/include-intuition-intuition-h.md), if [GT_FilterIMsg()](autodocs-3.5/gadtools-library-gt-filterimsg-2.md)
	       returned non-NULL.

   NOTES
	Be sure to use [exec.library/ReplyMsg()](autodocs-3.5/exec-library-replymsg-2.md) on the original [IntuiMessage](autodocs-3.5/include-intuition-intuition-h.md)
	you obtained with [GetMsg()](autodocs-3.5/exec-library-getmsg-2.md), (which is the what you passed to
	[GT_FilterIMsg()](autodocs-3.5/gadtools-library-gt-filterimsg-2.md)), and not on the parameter of this function.

	Starting with V39, this function actually expects and returns
	pointers to [ExtIntuiMessage](autodocs-3.5/include-intuition-intuition-h.md) structures, but the prototype was not
	changed for source code compatibility with older software.

   SEE ALSO
	[GT_FilterIMsg()](autodocs-3.5/gadtools-library-gt-filterimsg-2.md)

---

## See Also

- [GT_FilterIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_filterimsg)
- [GT_GetIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_getimsg)
- [GT_PostFilterIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_postfilterimsg)
- [GT_ReplyIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_replyimsg)
- [GetMsg — exec.library](../autodocs/exec.library.md#getmsg)
- [ReplyMsg — exec.library](../autodocs/exec.library.md#replymsg)
