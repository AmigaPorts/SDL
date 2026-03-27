---
title: 4 / Other Window Functions / Changing Pointer Position Reports
manual: libraries
chapter: libraries
section: 4-other-window-functions-changing-pointer-position-reports
functions: [ReportMouse]
libraries: [intuition.library]
---

# 4 / Other Window Functions / Changing Pointer Position Reports

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Pointer position messages to a window may be turned on and off by simply
setting or clearing the [WFLG_REPORTMOUSE](libraries/4-window-attributes-boolean-window-attribute-tags.md) flag bit in [Window->Flags](libraries/4-intuition-windows-the-window-structure.md), in an
atomic way, as explained for the [WA_RMBTrap](libraries/4-window-attributes-boolean-window-attribute-tags.md) tag in the "Window Attributes"
section above.  Using this direct method of setting the flag avoids the
historic confusion on the ordering of the arguments of the [ReportMouse()](libraries/10-the-pointer-pointer-position.md)
function call.

Mouse reporting may be turned on even if mouse movements were not
activated when the window was opened.  The proper IDCMP flags must be set
for the window to receive the messages.  See the chapter
"[Intuition Mouse and Keyboard](libraries/10-the-mouse-mouse-messages.md)" for more details on enabling mouse
reporting in an application.

---

## See Also

- [ReportMouse — intuition.library](../autodocs/intuition.library.md#reportmouse)
