---
title: 6 / / Intercepting Normal Menu Operations / Menu Verify
manual: libraries
chapter: libraries
section: 6-intercepting-normal-menu-operations-menu-verify
functions: []
libraries: []
---

# 6 / / Intercepting Normal Menu Operations / Menu Verify

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Menu verify is one of the Intuition verification capabilities that allow
an application to ensure that it is prepared for some action taken by
Intuition before that action takes place.  Through menu verify, Intuition
allows all windows in a screen to verify that they are prepared for menu
operations before the operations begin.  In general, use menu verify if
the program is doing something special to the display of a custom screen,
and needs to be sure the operation has completed before menus are rendered.

Any window can access the menu verify feature by setting the
[IDCMP_MENUVERIFY](libraries/9-event-message-classes-and-flags-menu-flags.md) flag with the [WA_IDCMP](libraries/4-window-attributes-window-attribute-tags.md) tag when opening the window.  When
menus are activated in a screen which contains at least one window with
IDCMP_MENUVERFIY set, menu operations will not proceed until all windows
with the menu verify flag set reply to the notification or until the last
message times out.  The specific menu verify protocol is described below.

In any case, it is vital that the application know when menu operations
terminate, for only then does it have control of the screen again.  For
the active window, this is typically detected by watching for an
[IDCMP_MENUPICK](libraries/9-event-message-classes-and-flags-menu-flags.md) message.  If the program cancels the menu operations
(MENUCANCEL), then it will instead receive an [IDCMP_MOUSEBUTTONS](libraries/9-event-message-classes-and-flags-mouse-flags.md) message
with code equal to MENUUP.  Inactive windows will always receive
IDCMP_MOUSEBUTTONS message with code equal to MENUUP.

The active window is given special menu verify treatment.  It receives the
menu verify message before any other window and has the option of
canceling menu operations altogether.  This could be used, for instance,
to examine where the user has positioned the mouse when the right button
was pressed.  For example, the application may choose to allow normal menu
operations to proceed only when the pointer is in the menu bar area.  When
the pointer is below the menu bar, then the application can choose to
interpret the menu verify message as a right button event for some
non-menu purpose.

The program can tell if it is the active window for the verify event by
examining the [Code](libraries/9-using-the-idcmp-intuimessages.md) field of the [IDCMP_MENUVERIFY](libraries/9-event-message-classes-and-flags-menu-flags.md) message.  If the Code
field is equal to MENUWAITING, this window is not active and Intuition is
simply waiting for verification that menu operations may continue.
However, if the Code field is equal to MENUHOT, this window is active and
it determines if menu operations should proceed.

If it wishes menu operations to proceed, the active window should reply to
the [IDCMP_MENUVERIFY](libraries/9-event-message-classes-and-flags-menu-flags.md) message without changing any values.  To cancel the
menu operation, change the code field of the message to MENUCANCEL before
replying to the message.

When the active window cancels the menu operation it will be sent an
[IDCMP_MOUSEBUTTONS](libraries/9-event-message-classes-and-flags-mouse-flags.md) message with code equal to MENUUP.  In general, the
window will not then receive an [IDCMP_MENUPICK](libraries/9-event-message-classes-and-flags-menu-flags.md) event as it cancelled the
operation.  However, the system should be prepared to handle an
IDCMP_MENUPICK message with code equal to [MENUNULL](libraries/6-setting-up-menus-menu-numbers.md) as one may be sent if
the user releases the mouse button before the window replies to the
message.

The system takes no action on screen until the active window either
replies to the menu verify event or the event times out.  If the active
window replies to the event in time and does not cancel the menu
operation, Intuition will then move the screen title bar layer to the
front, display the menu strip and notify all inactive menu verify windows
of the operation.  Layers will not be locked and the actual menus will not
be swapped in until all these inactive windows reply to the message or
time out.  The inactive windows may not cancel the menu operation.

If the user releases the menu button before the active window replies to
the menu verify message, the menu operation will be cancelled and the
active window will be sent an [IDCMP_MOUSEBUTTONS](libraries/9-event-message-classes-and-flags-mouse-flags.md) message with code equal
to MENUUP.  When the active window finally replies to the message, it will
receive an [IDCMP_MENUPICK](libraries/9-event-message-classes-and-flags-menu-flags.md) message with code equal to [MENUNULL](libraries/6-setting-up-menus-menu-numbers.md).

If the event times out before the active window replies to the message, it
will immediately be sent an [IDCMP_MENUPICK](libraries/9-event-message-classes-and-flags-menu-flags.md) message with code equal to
[MENUNULL](libraries/6-setting-up-menus-menu-numbers.md).  Then, when the user releases the menu button, the program will
receive an [IDCMP_MOUSEBUTTONS](libraries/9-event-message-classes-and-flags-mouse-flags.md) message with code equal to MENUUP.

If an inactive window receives an [IDCMP_MENUVERIFY](libraries/9-event-message-classes-and-flags-menu-flags.md) message, it will always
receive an [IDCMP_MOUSEBUTTONS](libraries/9-event-message-classes-and-flags-mouse-flags.md) message with code equal to MENUUP when the
menu operations are completed.


```c
    About Double-Menu Requesters.
    -----------------------------
    The processing described above becomes more complicated when
    double-menu requester processing is introduced.  If an application
    chooses to use a double-menu requester in a window with
    [IDCMP_MENUVERIFY](libraries/9-event-message-classes-and-flags-menu-flags.md) set, it should be aware that odd message
    combinations are possible.  For instance, it is possible to receive
    only an IDCMP_MENUVERIFY event with no following [IDCMP_MOUSEBUTTONS](libraries/9-event-message-classes-and-flags-mouse-flags.md)
    event or [IDCMP_MENUPICK](libraries/9-event-message-classes-and-flags-menu-flags.md) event.  Applications should avoid using
    double menu requesters if possible.
```
