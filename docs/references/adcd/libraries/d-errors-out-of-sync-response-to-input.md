---
title: D / Errors / Out-of-Sync Response to Input
manual: libraries
chapter: libraries
section: d-errors-out-of-sync-response-to-input
functions: [Wait, WaitPort]
libraries: [exec.library]
---

# D / Errors / Out-of-Sync Response to Input

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Caused by failing to handle all received signals or all possible messages
after a [Wait()](libraries/22-the-signal-system-waiting-for-a-signal.md) or [WaitPort()](libraries/24-messages-waiting-for-a-message.md) call.  More than one event or message may
have caused your program to awakened.  Check the signals returned by
Wait() and act on every one that is set.  At ports which may have more
than one message (for instance, a window's IDCMP port), you must handle
the messages in a while(msg=GetMsg(...)) loop.

---

## See Also

- [Wait — exec.library](../autodocs/exec.library.md#wait)
- [WaitPort — exec.library](../autodocs/exec.library.md#waitport)
