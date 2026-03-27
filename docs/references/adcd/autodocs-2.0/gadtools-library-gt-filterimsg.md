---
title: gadtools.library/GT_FilterIMsg
manual: autodocs-2.0
chapter: autodocs-2.0
section: gadtools-library-gt-filterimsg
functions: [GT_FilterIMsg, GT_GetIMsg, GT_PostFilterIMsg, GT_ReplyIMsg]
libraries: [gadtools.library]
---

# gadtools.library/GT_FilterIMsg

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    GT_FilterIMsg -- Filter an [IntuiMessage](autodocs-2.0/includes-intuition-intuition-h.md) through GadTools. (V36)
```
SYNOPSIS

```c
    modimsg = GT_FilterIMsg(imsg)
    D0                      A1

    struct [IntuiMessage](autodocs-2.0/includes-intuition-intuition-h.md) *GT_FilterIMsg(struct [IntuiMessage](autodocs-2.0/includes-intuition-intuition-h.md) *);
```
FUNCTION

```c
    NOTE WELL:  Extremely few programs will actually need this function.
    You almost certainly should be using [GT_GetIMsg()](autodocs-2.0/gadtools-library-gt-getimsg.md) and [GT_ReplyIMsg()](autodocs-2.0/gadtools-library-gt-replyimsg.md)
    only, and not GT_FilterIMsg() and [GT_PostFilterIMsg()](autodocs-2.0/gadtools-library-gt-postfilterimsg.md).

    GT_FilterIMsg() takes the supplied [IntuiMessage](autodocs-2.0/includes-intuition-intuition-h.md) and asks the
    [Gadget](autodocs-2.0/includes-intuition-intuition-h.md) Toolkit to consider and possibly act on it.  Returns
    NULL if the message was only of significance to a GadTools gadget
    (i.e. not to you), else returns a pointer to a modified IDCMP
    message, which may contain additional information.
    You should examine the Class, Code, and IAddress fields of
    the returned message to learn what happened.  Do not make
    interpretations based on the original imsg.
    You should use [GT_PostFilterIMsg()](autodocs-2.0/gadtools-library-gt-postfilterimsg.md) to revert to the original
    [IntuiMessage](autodocs-2.0/includes-intuition-intuition-h.md) once you are done with the modified one.
```
INPUTS

```c
    imsg - An [IntuiMessage](autodocs-2.0/includes-intuition-intuition-h.md) you obtained from a Window's UserPort.
```
RESULT

```c
    modimsg - A modified [IntuiMessage](autodocs-2.0/includes-intuition-intuition-h.md), possibly with extra information
        from GadTools, or NULL.
```
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [GT_GetIMsg()](autodocs-2.0/gadtools-library-gt-getimsg.md), [GT_PostFilterIMsg()](autodocs-2.0/gadtools-library-gt-postfilterimsg.md)
```

---

## See Also

- [GT_FilterIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_filterimsg)
- [GT_GetIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_getimsg)
- [GT_PostFilterIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_postfilterimsg)
- [GT_ReplyIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_replyimsg)
