---
title: D / Errors / Crashes--Window Related
manual: libraries
chapter: libraries
section: d-errors-crashes-window-related
functions: [ClearMenuStrip, CloseWindow, GetMsg, ModifyIDCMP, OpenWindow]
libraries: [exec.library, intuition.library]
---

# D / Errors / Crashes--Window Related

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Be careful not to [CloseWindow()](libraries/4-basic-window-structures-and-functions-closing-windows.md) a window during a while(msg=GetMsg(...))
loop on that window's port (next [GetMsg()](libraries/24-messages-getting-a-message.md) would be on freed pointer).
Also, use [ModifyIDCMP](libraries/9-intuition-input-and-output-methods-function-reference.md)(NULL) with care, especially if using one port with
multiple windows.  Be sure to [ClearMenuStrip()](libraries/6-setting-up-menus-submitting-and-removing-menu-strips.md) any menus before closing a
window, and do not free items such as dynamically allocated gadgets and
menus while they are attached to a window.  Do not reference an
[IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md)'s [IAddress](libraries/9-using-the-idcmp-intuimessages.md) field as a structure pointer of any kind before
determining it is a structure pointer (this depends on the [Class](libraries/9-using-the-idcmp-intuimessages.md) of the
IntuiMessage).  If a crash or problem only occurs when opening a window
after extended use of your program, check to make sure that your program
is properly freeing up signals allocated indirectly by [CreatePort()](libraries/24-message-ports-creating-a-message-port.md),
[OpenWindow()](libraries/4-basic-window-structures-and-functions-opening-a-window.md) or ModifyIDCMP().

---

## See Also

- [ClearMenuStrip — intuition.library](../autodocs/intuition.library.md#clearmenustrip)
- [CloseWindow — intuition.library](../autodocs/intuition.library.md#closewindow)
- [GetMsg — exec.library](../autodocs/exec.library.md#getmsg)
- [ModifyIDCMP — intuition.library](../autodocs/intuition.library.md#modifyidcmp)
- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
