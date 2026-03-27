---
title: 15 / / Other Functions / GT_FilterIMsg() and GT_PostFilterIMsg()
manual: libraries
chapter: libraries
section: 15-other-functions-gt-filterimsg-and-gt-postfilterimsg
functions: [GT_FilterIMsg, GT_GetIMsg, GT_PostFilterIMsg, GT_ReplyIMsg, GetMsg, ReplyMsg]
libraries: [exec.library, gadtools.library]
---

# 15 / / Other Functions / GT_FilterIMsg() and GT_PostFilterIMsg()

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

For most GadTools programs, [GT_GetIMsg()](libraries/15-gadtools-gadgets-handling-gadget-messages.md) and [GT_ReplyIMsg()](libraries/15-gadtools-gadgets-handling-gadget-messages.md) work perfectly
well.  In rare cases an application may find they pose a bit of a problem.
A typical case is when all messages are supposed to go through a
centralized [ReplyMsg()](libraries/24-messages-replying.md) that cannot be converted to a GT_ReplyIMsg().
Since calls to GT_GetIMsg() and GT_ReplyIMsg() must be paired, there would
be a problem.

For such cases, the [GT_FilterIMsg()](autodocs-2.0/gadtools-library-gt-filterimsg.md) and [GT_PostFilterIMsg()](autodocs-2.0/gadtools-library-gt-postfilterimsg.md) functions are
available.  These functions allow [GetMsg()](libraries/24-messages-getting-a-message.md) and [ReplyMsg()](libraries/24-messages-replying.md) to be used in a
way that is compatible with GadTools.


```c
    Warning:
    --------
    These functions are for specialized use only and will not be used by
    the majority of applications.  See [GT_GetIMsg()](libraries/15-gadtools-gadgets-handling-gadget-messages.md) and
    [GT_ReplyIMsg()](libraries/15-gadtools-gadgets-handling-gadget-messages.md) for standard message handling.


    struct IntuiMessage *GT_FilterIMsg( struct IntuiMessage *imsg );
    struct IntuiMessage *GT_PostFilterIMsg( struct IntuiMessage *imsg );
```
The [GT_FilterIMsg()](autodocs-2.0/gadtools-library-gt-filterimsg.md) function should be called right after [GetMsg()](libraries/24-messages-getting-a-message.md).  It
takes a pointer to the original [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md) and, if the message applies
to a GadTools gadget, returns either a modified IntuiMessage or a NULL.  A
NULL return signifies that the message was consumed by a GadTools gadget
(and not needed by the application).

The [GT_PostFilterIMsg()](autodocs-2.0/gadtools-library-gt-postfilterimsg.md) function should be called before replying to any
message modified by [GT_FilterIMsg()](autodocs-2.0/gadtools-library-gt-filterimsg.md).  It takes a pointer to the modified
version of an [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md) obtained with GT_FilterIMsg() and returns a
pointer to the original IntuiMessage.

The typical calling sequence for a program that uses these functions, is
to call [GetMsg()](libraries/24-messages-getting-a-message.md) to get the [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md).  Then, if the message applies to
a window which contains GadTools gadgets, call [GT_FilterIMsg()](autodocs-2.0/gadtools-library-gt-filterimsg.md).  Any
message returned by GT_FilterIMsg() should be used like a message returned
from [GT_GetIMsg()](libraries/15-gadtools-gadgets-handling-gadget-messages.md).

When done with the message, the application must call [GT_PostFilterIMsg()](autodocs-2.0/gadtools-library-gt-postfilterimsg.md)
to perform any clean up necessitated by the previous call to
[GT_FilterIMsg()](autodocs-2.0/gadtools-library-gt-filterimsg.md).  In all cases, the application must then reply the
original [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md) using [ReplyMsg()](libraries/24-messages-replying.md).  This is true even for consumed
messages as these are not replied by GadTools.  For example, the
application could use code such as this:


```c
    /* port is a message port receiving different messages */
    /* gtwindow is the window that contains GadTools gadgets */

    imsg = GetMsg(port);

    /* Is this the window with GadTools gadgets? */
    if (imsg->IDCMPWindow == gtwindow)
        {
        /* Filter the message and see if action is needed */
        if (gtimsg = GT_FilterIMsg(imsg))
            {
            switch (gtimsg->Class)
                {
                /* Act depending on the message */
                ...
                }
            /* Clean up the filtered message.  The return value is not */
            /* needed since we already have a pointer to the original  */
            /* message.                                                */
            GT_PostFilterIMsg(gtimsg);
            }
        }
    /* other stuff can go here */
    ReplyMsg(imsg);
```
You should not make any assumptions about the contents of the unfiltered
[IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md) (imsg in the above example).  Only two things are guaranteed:
the unfiltered IntuiMessage must be replied to and the unfiltered
IntuiMessage (if it produces anything when passed through [GT_FilterIMsg()](autodocs-2.0/gadtools-library-gt-filterimsg.md))
will produce a meaningful GadTools IntuiMessage like those described in
the section on the different [kinds of gadgets](libraries/15-gadtools-gadgets-the-kinds-of-gadtools-gadgets.md).  The relationship between
the unfiltered and filtered messages are expected to change in the future.
See the section on [documented side-effects](libraries/15-gadtools-gadgets-documented-side-effects.md) for more information.

---

## See Also

- [GT_FilterIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_filterimsg)
- [GT_GetIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_getimsg)
- [GT_PostFilterIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_postfilterimsg)
- [GT_ReplyIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_replyimsg)
- [GetMsg — exec.library](../autodocs/exec.library.md#getmsg)
- [ReplyMsg — exec.library](../autodocs/exec.library.md#replymsg)
