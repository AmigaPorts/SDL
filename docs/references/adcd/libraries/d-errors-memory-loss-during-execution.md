---
title: D / Errors / Memory Loss--During Execution
manual: libraries
chapter: libraries
section: d-errors-memory-loss-during-execution
functions: [ReplyMsg]
libraries: [exec.library]
---

# D / Errors / Memory Loss--During Execution

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A continuing memory loss during execution can be caused by failure to keep
up with voluminous IDCMP messages such as [MOUSEMOVE](libraries/9-event-message-classes-and-flags-mouse-flags.md) messages. Intuition
cannot re-use IDCMP message blocks until you [ReplyMsg()](libraries/24-messages-replying.md) them.  If your
window's allotted message blocks are all in use, new sets will be
allocated and not freed till the window is closed.  Continuing memory
losses can also be caused by a program loop containing an allocation-type
call without a corresponding free.

---

## See Also

- [ReplyMsg — exec.library](../autodocs/exec.library.md#replymsg)
