---
title: D / Errors / Crashes--Workbench Only
manual: libraries
chapter: libraries
section: d-errors-crashes-workbench-only
functions: [GetMsg]
libraries: [exec.library]
---

# D / Errors / Crashes--Workbench Only

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

If you are crashing near the first DOS call, either your stack is too
small or your startup code did not [GetMsg()](libraries/24-messages-getting-a-message.md) the [WBStartup](libraries/14-workbench-environment-wbstartup-message.md) message from the
process message port.  If your program crashes during execution or during
your exit procedure only when started from Workbench, and your startup
opens no stdio window or NIL: file handles for WB programs, then make sure
you are not writing anything to stdout ([printf()](autodocs-2.0/amiga-lib-printf.md), etc.) when started from
WB (argc==0).  See also "[Crashes--After Exit](libraries/d-errors-crashes-after-exit.md)".

---

## See Also

- [GetMsg — exec.library](../autodocs/exec.library.md#getmsg)
