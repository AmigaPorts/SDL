---
title: 6 / / Intercepting Menu Operations / IDCMP_MENUVERIFY and Deadlock
manual: libraries
chapter: libraries
section: 6-intercepting-menu-operations-idcmp-menuverify-and-deadlock
functions: [AutoRequest, ModifyIDCMP, OpenDevice, OpenDiskFont, OpenLibrary]
libraries: [diskfont.library, exec.library, intuition.library]
---

# 6 / / Intercepting Menu Operations / IDCMP_MENUVERIFY and Deadlock

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The program may call [ModifyIDCMP()](libraries/9-intuition-input-and-output-methods-function-reference.md) to turn [IDCMP_MENUVERIFY](libraries/9-event-message-classes-and-flags-menu-flags.md) and the other
VERIFY IDCMP options off.  It is important that this be done each and
every time that the application is directly or indirectly waiting for
Intuition, since Intuition may be waiting for the application, but not
watching the window message port for IDCMP_MENUVERIFY events.  The program
cannot wait for a gadget or mouse event without checking also for any
IDCMP_MENUVERIFY event messages that may require program response.

The most common problem area is System Requesters ([AutoRequest()](libraries/7-intuition-requesters-and-alerts-function-reference.md) and
[EasyRequest()](libraries/7-intuition-requesters-and-alerts-easy-requesters.md)).  Before AutoRequest() and EasyRequest() return control to
the application, Intuition must be free to run and accept a response from
the user.  If the user presses the menu button, Intuition will wait for
the program to reply to the [IDCMP_MENUVERIFY](libraries/9-event-message-classes-and-flags-menu-flags.md) event and a deadlock results.

Therefore, it is extremely important to use [ModifyIDCMP()](libraries/9-intuition-input-and-output-methods-function-reference.md) to turn off all
verify messages before calling [AutoRequest()](libraries/7-intuition-requesters-and-alerts-function-reference.md), [EasyRequest()](libraries/7-intuition-requesters-and-alerts-easy-requesters.md) or, directly
or indirectly, AmigaDOS, since many error conditions in the DOS require
user input in the form of an EasyRequest().  Indirect DOS calls include
[OpenLibrary()](libraries/17-introduction-to-exec-libraries-and-devices.md), [OpenDevice()](libraries/19-accessing-a-device-opening-a-device.md), and [OpenDiskFont()](libraries/29-the-text-function-choosing-the-font.md).

Beginning with V36, all windows that have the [IDCMP_MENUVERIFY](libraries/9-event-message-classes-and-flags-menu-flags.md) bit set
must respond to Intuition within a set time period, or the menu operation
will time out and the menu action will be canceled.  This prevents the
deadlocks that were possible under previous versions of the operating
system.

---

## See Also

- [AutoRequest — intuition.library](../autodocs/intuition.library.md#autorequest)
- [ModifyIDCMP — intuition.library](../autodocs/intuition.library.md#modifyidcmp)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
- [OpenDiskFont — diskfont.library](../autodocs/diskfont.library.md#opendiskfont)
- [OpenLibrary — exec.library](../autodocs/exec.library.md#openlibrary)
