---
title: D / Errors / DOS-related Problems
manual: libraries
chapter: libraries
section: d-errors-dos-related-problems
functions: [GetMsg]
libraries: [exec.library]
---

# D / Errors / DOS-related Problems

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

In general, any dos.library function which fills in a structure for you
(for example, [Examine()](autodocs-2.0/dos-library-examine.md)), requires that the structure be longword aligned.
In most cases, the only way to insure longword alignment in C is to
dynamically allocate the structure.  Unless documented otherwise,
dos.library functions may only be called from a process, not from a task.
Also note that a process's [pr_MsgPort](autodocs-2.0/includes-dos-dosextens-h.md) is intended for the exclusive use of
dos.library.  (The port may be used to receive a [WBStartup](libraries/14-workbench-environment-wbstartup-message.md) message as long
as the message is [GetMsg()](libraries/24-messages-getting-a-message.md)'d from the port before DOS is used.

---

## See Also

- [GetMsg — exec.library](../autodocs/exec.library.md#getmsg)
