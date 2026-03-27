---
title: gadtools.library/GT_GetIMsg
manual: autodocs-2.0
chapter: autodocs-2.0
section: gadtools-library-gt-getimsg
functions: [GT_FilterIMsg, GT_GetIMsg, GT_ReplyIMsg, GetMsg, ReplyMsg]
libraries: [exec.library, gadtools.library]
---

# gadtools.library/GT_GetIMsg

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    GT_GetIMsg -- Get an [IntuiMessage](autodocs-2.0/includes-intuition-intuition-h.md), with GadTools processing. (V36)
```
SYNOPSIS

```c
    imsg = GT_GetIMsg(intuiport)
    D0                A0

    struct [IntuiMessage](autodocs-2.0/includes-intuition-intuition-h.md) *GT_GetIMsg(struct [MsgPort](autodocs-2.0/includes-exec-ports-h.md) *);
```
FUNCTION

```c
    Use GT_GetIMsg() in place of the usual [exec.library/GetMsg()](autodocs-2.0/exec-library-getmsg.md) when
    reading IntuiMessages from your window's UserPort.  If needed,
    the GadTools dispatcher will be invoked, and suitable processing
    will be done for gadget actions.  This function returns a pointer
    to a modified [IntuiMessage](autodocs-2.0/includes-intuition-intuition-h.md) (which is a copy of the original,
    possibly with some supplementary information from GadTools).
    If there are no messages (or if the only messages are meaningful
    only to GadTools, NULL will be returned.
```
INPUTS

```c
    intuiport - The Window->UserPort of a window that is using the
        [Gadget](autodocs-2.0/includes-intuition-intuition-h.md) Toolkit.
```
RESULT

```c
    imsg - Pointer to modified [IntuiMessage](autodocs-2.0/includes-intuition-intuition-h.md), or NULL if there are
        no applicable messages.
```
EXAMPLE

NOTES

```c
    Be sure to use [GT_ReplyIMsg()](autodocs-2.0/gadtools-library-gt-replyimsg.md) and not [exec.library/ReplyMsg()](autodocs-2.0/exec-library-replymsg.md) on
    messages obtained with GT_GetIMsg().
    If you intend to do more with the resulting message than read
    its fields, act on it, and reply it, you may find [GT_FilterIMsg()](autodocs-2.0/gadtools-library-gt-filterimsg.md)
    more appropriate.
```
BUGS

SEE ALSO

```c
    [GT_ReplyIMsg()](autodocs-2.0/gadtools-library-gt-replyimsg.md), [GT_FilterIMsg()](autodocs-2.0/gadtools-library-gt-filterimsg.md)
```

---

## See Also

- [GT_FilterIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_filterimsg)
- [GT_GetIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_getimsg)
- [GT_ReplyIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_replyimsg)
- [GetMsg — exec.library](../autodocs/exec.library.md#getmsg)
- [ReplyMsg — exec.library](../autodocs/exec.library.md#replymsg)
