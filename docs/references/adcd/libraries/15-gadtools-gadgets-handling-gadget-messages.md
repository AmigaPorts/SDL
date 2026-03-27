---
title: 15 / GadTools Gadgets / Handling Gadget Messages
manual: libraries
chapter: libraries
section: 15-gadtools-gadgets-handling-gadget-messages
functions: [GT_GetIMsg, GT_ReplyIMsg, GetMsg, ReplyMsg]
libraries: [exec.library, gadtools.library]
---

# 15 / GadTools Gadgets / Handling Gadget Messages

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

GadTools gadgets follow the same input model as other Intuition
components.  When the user operates a GadTools gadget, Intuition notifies
the application about the input event by sending an [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md).  The
application can get these messages at the [Window](libraries/4-intuition-windows-the-window-structure.md).UserPort.  However
GadTools gadgets use different message handling functions to get and reply
these messages.  Instead of the Exec functions [GetMsg()](libraries/24-messages-getting-a-message.md) and [ReplyMsg()](libraries/24-messages-replying.md),
applications should get and reply these messages through a pair of special
GadTools functions, [GT_GetIMsg()](autodocs-2.0/gadtools-library-gt-getimsg.md) and [GT_ReplyIMsg()](autodocs-2.0/gadtools-library-gt-replyimsg.md).


```c
    struct IntuiMessage *GT_GetIMsg(struct MsgPort *iport)
    void  GT_ReplyIMsg(struct IntuiMessage *imsg)
```
For [GT_GetIMsg()](autodocs-2.0/gadtools-library-gt-getimsg.md), the iport argument should be set to the window's
UserPort.  For [GT_ReplyIMsg()](autodocs-2.0/gadtools-library-gt-replyimsg.md), the imsg argument should be set to a
pointer to the [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md) returned by GT_GetIMsg().

These functions ensure that the application only sees the gadget events
that concern it and in a desirable form.  For example, with a GadTools
slider gadget, a message only gets through to the application when the
slider's level actually changes and that level can be found in the
[IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md)'s [Code](libraries/9-using-the-idcmp-intuimessages.md) field:


```c
    imsg = GT_GetIMsg(win->UserPort);
    object = imsg->IAddress;
    class = imsg->Class;
    code = imsg->Code;
    GT_ReplyIMsg(imsg);
    switch (class)
        {
        case IDCMP_MOUSEMOVE:
            if (object == slidergad)
                {
                printf("Slider at level %ld\n", code);
                }
            ...
            break;
        ...
        }
```
In general, the [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md)s received from GadTools contain more
information in the [Code](libraries/9-using-the-idcmp-intuimessages.md) field than is found in regular Intuition gadget
messages.  Also, when dealing with GadTools a lot of messages (mostly
[IDCMP_MOUSEMOVE](libraries/9-event-message-classes-and-flags-mouse-flags.md)s) do not have to be processed by the application.  These
are two reasons why dealing with GadTools gadgets is much easier than
dealing with regular Intuition gadgets.  Unfortunately this processing
cannot happen magically, so applications must use [GT_GetIMsg()](autodocs-2.0/gadtools-library-gt-getimsg.md) and
[GT_ReplyIMsg()](autodocs-2.0/gadtools-library-gt-replyimsg.md) where they would normally have used [GetMsg()](libraries/24-messages-getting-a-message.md) and [ReplyMsg()](libraries/24-messages-replying.md).

[GT_GetIMsg()](autodocs-2.0/gadtools-library-gt-getimsg.md) actually calls [GetMsg()](libraries/24-messages-getting-a-message.md) to remove a message from the
specified window's UserPort.  If the message pertains to a GadTools gadget
then some dispatching code in GadTools will be called to process the
message.  What the program will receive from GT_GetIMsg() is actually a
copy of the real [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md), possibly with some supplementary
information from GadTools, such as the information typically found in the
[Code](libraries/9-using-the-idcmp-intuimessages.md) field.

The [GT_ReplyIMsg()](autodocs-2.0/gadtools-library-gt-replyimsg.md) call will take care of cleaning up and replying to the
real [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md).


```c
    Warning:
    --------
    When an [IDCMP_MOUSEMOVE](libraries/9-event-message-classes-and-flags-mouse-flags.md) message is received from a GadTools gadget,
    GadTools arranges to have the gadget's pointer in the [IAddress](libraries/9-using-the-idcmp-intuimessages.md)
    field of the [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md).  While this is extremely convenient, it
    is also untrue of messages from regular Intuition gadgets (described
    in the "[Intuition Gadgets](libraries/5-intuition-gadgets-gadget-pointer-movements.md)" chapter).  Do not make the mistake of
    assuming it to be true.
```
This description of the inner workings of [GT_GetIMsg()](autodocs-2.0/gadtools-library-gt-getimsg.md) and [GT_ReplyIMsg()](autodocs-2.0/gadtools-library-gt-replyimsg.md)
is provided for understanding only; it is crucial that the program make no
assumptions or interpretations about the real [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md).  Any such
inferences are not likely to hold true in the future.  See the section on
[documented side-effects](libraries/15-gadtools-gadgets-documented-side-effects.md) for more information.

---

## See Also

- [GT_GetIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_getimsg)
- [GT_ReplyIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_replyimsg)
- [GetMsg — exec.library](../autodocs/exec.library.md#getmsg)
- [ReplyMsg — exec.library](../autodocs/exec.library.md#replymsg)
