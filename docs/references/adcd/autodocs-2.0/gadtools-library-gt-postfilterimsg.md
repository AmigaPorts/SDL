---
title: gadtools.library/GT_PostFilterIMsg
manual: autodocs-2.0
chapter: autodocs-2.0
section: gadtools-library-gt-postfilterimsg
functions: [GT_FilterIMsg, GT_GetIMsg, GT_PostFilterIMsg, GT_ReplyIMsg, GetMsg, ReplyMsg]
libraries: [exec.library, gadtools.library]
---

# gadtools.library/GT_PostFilterIMsg

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    GT_PostFilterIMsg -- Return the unfiltered message after
        [GT_FilterIMsg()](autodocs-2.0/gadtools-library-gt-filterimsg.md) was called, and clean up. (V36)
```
SYNOPSIS

```c
    imsg = GT_PostFilterIMsg(modimsg)
    D0                       A1

    struct [IntuiMessage](autodocs-2.0/includes-intuition-intuition-h.md) *GT_PostFilterIMsg(struct [IntuiMessage](autodocs-2.0/includes-intuition-intuition-h.md) *);
```
FUNCTION

```c
    NOTE WELL:  Extremely few programs will actually need this function.
    You almost certainly should be using [GT_GetIMsg()](autodocs-2.0/gadtools-library-gt-getimsg.md) and [GT_ReplyIMsg()](autodocs-2.0/gadtools-library-gt-replyimsg.md)
    only, and not [GT_FilterIMsg()](autodocs-2.0/gadtools-library-gt-filterimsg.md) and GT_PostFilterIMsg().

    Performs any clean-up necessitated by a previous call to
    [GT_FilterIMsg()](autodocs-2.0/gadtools-library-gt-filterimsg.md).  The original [IntuiMessage](autodocs-2.0/includes-intuition-intuition-h.md) is now yours to handle.
    Do not interpret the fields of the original [IntuiMessage](autodocs-2.0/includes-intuition-intuition-h.md), but
    rather use only the one you got from [GT_FilterIMsg()](autodocs-2.0/gadtools-library-gt-filterimsg.md).  You
    may only do message related things at this point, such as queueing
    it up or replying it.  Since you got the message with
    [exec.library/GetMsg()](autodocs-2.0/exec-library-getmsg.md), your responsibilities do include replying
    it with [exec.library/ReplyMsg()](autodocs-2.0/exec-library-replymsg.md). This function may be safely
    called with a NULL parameter.
```
INPUTS

```c
    modimsg - A modified [IntuiMessage](autodocs-2.0/includes-intuition-intuition-h.md) obtained with [GT_FilterIMsg()](autodocs-2.0/gadtools-library-gt-filterimsg.md).
```
RESULT

```c
    imsg - A pointer to the original [IntuiMessage](autodocs-2.0/includes-intuition-intuition-h.md), if [GT_FilterIMsg()](autodocs-2.0/gadtools-library-gt-filterimsg.md)
        returned non-NULL.
```
EXAMPLE

NOTES

```c
    Be sure to use [exec.library/ReplyMsg()](autodocs-2.0/exec-library-replymsg.md) on the original [IntuiMessage](autodocs-2.0/includes-intuition-intuition-h.md)
    you obtained with [GetMsg()](autodocs-2.0/exec-library-getmsg.md), (which is the what you passed to
    [GT_FilterIMsg()](autodocs-2.0/gadtools-library-gt-filterimsg.md)), and not on the parameter of this function.
```
BUGS

SEE ALSO

```c
    [GT_FilterIMsg()](autodocs-2.0/gadtools-library-gt-filterimsg.md)
```

---

## See Also

- [GT_FilterIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_filterimsg)
- [GT_GetIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_getimsg)
- [GT_PostFilterIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_postfilterimsg)
- [GT_ReplyIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_replyimsg)
- [GetMsg — exec.library](../autodocs/exec.library.md#getmsg)
- [ReplyMsg — exec.library](../autodocs/exec.library.md#replymsg)
