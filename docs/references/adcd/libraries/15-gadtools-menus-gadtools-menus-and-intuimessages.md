---
title: 15 / GadTools Menus / GadTools Menus and IntuiMessages
manual: libraries
chapter: libraries
section: 15-gadtools-menus-gadtools-menus-and-intuimessages
functions: [CreateContext, GT_FilterIMsg, GT_GetIMsg, GT_PostFilterIMsg, GT_ReplyIMsg, GetMsg, ReplyMsg]
libraries: [exec.library, gadtools.library]
---

# 15 / GadTools Menus / GadTools Menus and IntuiMessages

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

If the window uses GadTools menus and GadTools gadgets, then use the
[GT_GetIMsg()](libraries/15-gadtools-gadgets-handling-gadget-messages.md) and [GT_ReplyIMsg()](libraries/15-gadtools-gadgets-handling-gadget-messages.md) functions described below (or
[GT_FilterIMsg()](libraries/15-other-functions-gt-filterimsg-and-gt-postfilterimsg.md) and [GT_PostFilterIMsg()](libraries/15-other-functions-gt-filterimsg-and-gt-postfilterimsg.md), if applicable).  However, if the
window has GadTools menus, but no GadTools gadgets, it is acceptable to
use [GetMsg()](libraries/24-messages-getting-a-message.md) and [ReplyMsg()](libraries/24-messages-replying.md) in the usual manner.

Additionally, no context need be created with [CreateContext()](libraries/15-setting-up-gadtools-menus-and-gadgets-createcontext.md) if no
GadTools gadgets are used.  For more about these functions, see the
section on "[Other GadTools Functions](libraries/15-gadtools-gadgets-other-gadtools-functions.md)" later in this chapter.

---

## See Also

- [CreateContext — gadtools.library](../autodocs/gadtools.library.md#createcontext)
- [GT_FilterIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_filterimsg)
- [GT_GetIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_getimsg)
- [GT_PostFilterIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_postfilterimsg)
- [GT_ReplyIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_replyimsg)
- [GetMsg — exec.library](../autodocs/exec.library.md#getmsg)
- [ReplyMsg — exec.library](../autodocs/exec.library.md#replymsg)
