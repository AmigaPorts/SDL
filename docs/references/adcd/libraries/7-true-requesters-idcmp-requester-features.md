---
title: 7 / True Requesters / IDCMP Requester Features
manual: libraries
chapter: libraries
section: 7-true-requesters-idcmp-requester-features
functions: [AutoRequest, ModifyIDCMP, Request]
libraries: [intuition.library]
---

# 7 / True Requesters / IDCMP Requester Features

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Intuition can notify your application about user activity in the requester
by sending a message to the parent window's IDCMP port ([Window.UserPort](libraries/9-intuition-input-and-output-methods-using-the-idcmp.md)).
When using the IDCMP for input, the following IDCMP flags control how
requester input events will be handled.

[IDCMP_REQSET](libraries/9-event-message-classes-and-flags-requester-flags.md)

    With this flag set, the program will receive a message whenever a
    requester opens in its window.  The application will receive one
    IDCMP_REQSET event for each requester opened in the window.
[IDCMP_REQCLEAR](libraries/9-event-message-classes-and-flags-requester-flags.md)

    With this flag set, the program will receive a message whenever a
    requester is cleared from its window.  The application will receive
    one IDCMP_REQCLEAR event for each requester closed in the window.  By
    counting the number of IDCMP_REQSET and IDCMP_REQCLEAR events, the
    application may determine how many requesters are currently open in a
    window.
[IDCMP_REQVERIFY](libraries/9-event-message-classes-and-flags-requester-flags.md)

```c
    With this flag set, the application can ensure that it is ready to
    allow a requester to appear in the window before the requester is
    displayed.

    When the program receives an IDCMP_REQVERIFY message, it must reply
    to that message before the requester is added to the window.  If
    multiple requesters are opened in the window at the same time, only
    the first one will cause an IDCMP_REQVERIFY event.  It is assumed
    that once a requester is in a window others may be added without the
    program's consent.  After the requester count drops to zero and there
    are no open requesters in the window, the next requester to open will
    cause another IDCMP_REQVERIFY event.

    IDCMP_REQVERIFY is ignored by the [Request()](libraries/7-true-requesters-creating-application-requesters.md) function.  Since
    Request() is controlled by the application, it is assumed that the
    program is prepared to handle the request when calling this function.
    Since the system does not render [true](libraries/7-intuition-requesters-and-alerts-true-requesters.md) requesters into an
    application's window ([EasyRequest()](libraries/7-intuition-requesters-and-alerts-easy-requesters.md) and [AutoRequest()](libraries/7-intuition-requesters-and-alerts-function-reference.md) come up in
    their own window, not in the application's window), IDCMP_REQVERIFY
    will only control the timing of [double menu](libraries/7-true-requesters-double-menu-requesters.md) requesters.
```
These flags are set when the parent window is first opened by using either
the [WA_IDCMP](libraries/4-window-attributes-window-attribute-tags.md) tag or NewWindow.IDCMPFlags.  They can also be set after the
parent window is open by using the [ModifyIDCMP()](libraries/9-intuition-input-and-output-methods-function-reference.md) call.  See the chapter
entitled "[Intuition Input and Output Methods](libraries/9-event-message-classes-and-flags-requester-flags.md)," for further information
about these IDCMP flags.  See the "[Intuition Windows](libraries/4-communicating-with-intuition-the-idcmp.md)" chapter for details
on setting IDCMP flags when a window is opened.

---

## See Also

- [AutoRequest — intuition.library](../autodocs/intuition.library.md#autorequest)
- [ModifyIDCMP — intuition.library](../autodocs/intuition.library.md#modifyidcmp)
- [Request — intuition.library](../autodocs/intuition.library.md#request)
