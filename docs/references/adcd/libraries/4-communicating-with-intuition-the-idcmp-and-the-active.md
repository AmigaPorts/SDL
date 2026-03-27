---
title: 4 / Communicating with Intuition / The IDCMP And The Active Window
manual: libraries
chapter: libraries
section: 4-communicating-with-intuition-the-idcmp-and-the-active
functions: [ActivateWindow]
libraries: [intuition.library]
---

# 4 / Communicating with Intuition / The IDCMP And The Active Window

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

On the Amiga, all input is directed to a single window called the active
window.  In general, changing the active window should be left up to the
user.  (The user activates a window by pressing the select button while
the pointer is within the window boundaries.)  If the active window is
changed, the user may be confused if the change was not performed at their
direction.  Hence, new windows should be activated only when they open as
a direct and synchronous response to the user's action.  Existing windows
should almost never be activated by the application.

An application can learn when one of its windows is activated or
deactivated by setting the IDCMP flags [IDCMP_ACTIVEWINDOW](libraries/9-event-message-classes-and-flags-window-flags.md) and
[IDCMP_INACTIVEWINDOW](libraries/9-event-message-classes-and-flags-window-flags.md). When these flags are specified, the program will
receive a message each time the user activates the window or causes the
window to become inactive by activating some other window.

The application may specify that a window is to become active when it
opens.  This is done with the [WA_Activate](libraries/4-window-attributes-boolean-window-attribute-tags.md) tag or by setting WFLG_ACTIVATE
in [NewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md).Flags when the window is opened.

The application may also activate an existing window.  This is done by
calling the [ActivateWindow()](autodocs-2.0/intuition-library-activatewindow.md) function, which will activate the window as
soon as possible.  Try to use this function only in response to user
action since it may cause a shift in the input focus:


```c
    LONG ActivateWindow( struct Window *window );
```
This function call may have its action deferred.  Do not assume that the
selected window has become active when this call returns.  Intuition will
inform the application when this window has become active by sending an
[IDCMP_ACTIVEWINDOW](libraries/9-event-message-classes-and-flags-window-flags.md) message.  Getting this message is the only supported
way of tracking the activation status of your windows.

---

## See Also

- [ActivateWindow — intuition.library](../autodocs/intuition.library.md#activatewindow)
