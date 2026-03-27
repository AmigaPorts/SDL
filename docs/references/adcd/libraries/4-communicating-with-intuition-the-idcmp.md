---
title: 4 / Communicating with Intuition / The IDCMP
manual: libraries
chapter: libraries
section: 4-communicating-with-intuition-the-idcmp
functions: [OpenWindow, OpenWindowTagList]
libraries: [intuition.library]
---

# 4 / Communicating with Intuition / The IDCMP

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The IDCMP gives an application convenient access to many types of user
input events through the Exec message and port system.  Intuition input
event messages include mouse and keyboard activity as well as high level
events from menus and gadgets.

With the IDCMP, you specify the input events you want to know about when
you open the window.  The input events are specified with one or more of
the [IDCMP flags](libraries/9-intuition-input-and-output-methods-idcmp-flags.md) in <intuition/[intuition.h](autodocs-2.0/includes-intuition-intuition-h.md)>.  Use the flags with the
[WA_IDCMP](libraries/4-window-attributes-window-attribute-tags.md) tag for the [OpenWindowTagList()](libraries/4-basic-window-structures-and-functions-opening-a-window.md) (or [OpenWindowTags()](libraries/4-basic-window-structures-and-functions-opening-a-window.md)) function.
Or, set the flags in [NewWindow.IDCMPFlags](libraries/4-window-attributes-window-attribute-tags.md) for the [OpenWindow()](libraries/4-basic-window-structures-and-functions-opening-a-window.md) function.  If
any IDCMP flags are set when the window is opened, Intuition automatically
creates a message port for you to receive messages about user activity.
If NULL is specified for IDCMP flags, no port is created.  For more
information on receiving messages from Intuition, see the IDCMP sections
in the chapter "[Intuition Input and Output Methods](libraries/9-intuition-input-and-output-methods.md)."

---

## See Also

- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
- [OpenWindowTagList — intuition.library](../autodocs/intuition.library.md#openwindowtaglist)
