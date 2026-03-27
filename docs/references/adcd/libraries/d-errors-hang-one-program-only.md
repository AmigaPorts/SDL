---
title: D / Errors / Hang--One Program Only
manual: libraries
chapter: libraries
section: d-errors-hang-one-program-only
functions: [AutoRequest, Wait, WaitIO, WaitPort]
libraries: [exec.library, intuition.library]
---

# D / Errors / Hang--One Program Only

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Program hangs are generally caused by [Wait()](libraries/22-the-signal-system-waiting-for-a-signal.md)ing on the wrong signal bits,
on the wrong port, on the wrong message, or on some other event that will
never occur.  This can occur if the event you are waiting on is not
coming, or if one task tries to Wait(), [WaitPort()](libraries/24-messages-waiting-for-a-message.md), or [WaitIO()](libraries/19-using-a-device-synchronous-vs-asynchronous-requests.md) on a
signal, port, or window that was created by a different task.  Both
WaitIO() and WaitPort() can call Wait(), and you cannot Wait() on another
task's signals.  Hangs can also be caused by verify deadlocks. Be sure to
turn off all Intuition verify messages (such as [MENUVERIFY](libraries/9-event-message-classes-and-flags-menu-flags.md)) before calling
[AutoRequest()](libraries/7-intuition-requesters-and-alerts-function-reference.md) or doing disk access.

---

## See Also

- [AutoRequest — intuition.library](../autodocs/intuition.library.md#autorequest)
- [Wait — exec.library](../autodocs/exec.library.md#wait)
- [WaitIO — exec.library](../autodocs/exec.library.md#waitio)
- [WaitPort — exec.library](../autodocs/exec.library.md#waitport)
