---
title: gadtools.library/GT_ReplyIMsg
manual: autodocs-2.0
chapter: autodocs-2.0
section: gadtools-library-gt-replyimsg
functions: [CloseWindow, GT_GetIMsg, GT_ReplyIMsg, ReplyMsg]
libraries: [exec.library, gadtools.library, intuition.library]
---

# gadtools.library/GT_ReplyIMsg

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    GT_ReplyIMsg -- Reply a message obtained with [GT_GetIMsg()](autodocs-2.0/gadtools-library-gt-getimsg.md). (V36)
```
SYNOPSIS

```c
    GT_ReplyIMsg(imsg)
                 A1

    VOID GT_ReplyIMsg(struct [IntuiMessage](autodocs-2.0/includes-intuition-intuition-h.md) *);
```
FUNCTION

```c
    Reply a modified [IntuiMessage](autodocs-2.0/includes-intuition-intuition-h.md) obtained with [GT_GetIMsg()](autodocs-2.0/gadtools-library-gt-getimsg.md).
    If you use [GT_GetIMsg()](autodocs-2.0/gadtools-library-gt-getimsg.md), use this function where you would normally
    have used [exec.library/ReplyMsg()](autodocs-2.0/exec-library-replymsg.md).
    You may safely call this routine with a NULL pointer (nothing
    will be done).
```
INPUTS

```c
    imsg - A modified [IntuiMessage](autodocs-2.0/includes-intuition-intuition-h.md) obtained with [GT_GetIMsg()](autodocs-2.0/gadtools-library-gt-getimsg.md).
```
RESULT

    None.
EXAMPLE

NOTES

```c
    When using GadTools, you MUST explicitly GT_ReplyIMsg()
    all messages you receive.  You cannot depend on [CloseWindow()](autodocs-2.0/intuition-library-closewindow.md)
    to handle messages you have not replied.
```
BUGS

SEE ALSO

```c
    [GT_GetIMsg()](autodocs-2.0/gadtools-library-gt-getimsg.md)
```

---

## See Also

- [CloseWindow — intuition.library](../autodocs/intuition.library.md#closewindow)
- [GT_GetIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_getimsg)
- [GT_ReplyIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_replyimsg)
- [ReplyMsg — exec.library](../autodocs/exec.library.md#replymsg)
