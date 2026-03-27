---
title: 26 / Servicing Interrupts / Environment
manual: libraries
chapter: libraries
section: 26-servicing-interrupts-environment
functions: [AddHead, AddTail, Alert, Cause, Disable, Enable, FindName, FindPort, FindTask, Forbid, GetMsg, Permit, PutMsg, RemHead, RemTail, ReplyMsg, SendIO, Signal]
libraries: [exec.library]
---

# 26 / Servicing Interrupts / Environment

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Interrupts execute in an environment different from that of tasks. All
interrupts execute in [supervisor mode](libraries/21-processor-and-cache-control-supervisor-mode.md) and utilize the single system stack.
This stack is large enough to handle extreme cases of nested interrupts
(of higher priorities).  Interrupt processing has no effect on task stack
usage.

All interrupt processing code, both handlers and servers, is invoked as
assembly code subroutines.  Normal assembly code register conventions
dictate that the D0, D1, A0 and A1 registers be free for scratch use.  In
the case of an interrupt handler, some of these registers also contain
data that may be useful to the handler code.  See the section on [handlers](libraries/26-servicing-interrupts-interrupt-handlers.md)
below.

Because interrupt processing executes outside the context of most system
activities, certain data structures will not be self-consistent and must
be considered off limits for all practical purposes.  This happens because
certain system operations are not atomic in nature and might be
interrupted only after executing part of an important instruction
sequence.  For example, memory allocation and deallocation routines do not
disable interrupts.  This results in the possibility of interrupting a
memory-related routine.  In such a case, a memory linked list may be
inconsistent during and interrupt. Therefore, interrupt routines must not
use any memory allocation or deallocation functions.

In addition, interrupts may not call any system function which might
allocate memory, wait, manipulate unprotected lists, or modify
[ExecBase](autodocs-2.0/includes-exec-execbase-h.md)->ThisTask data (for example [Forbid()](libraries/21-task-exclusion-forbidding-task-switching.md), [Permit()](libraries/21-task-exclusion-forbidding-task-switching.md), and [mathieee](libraries/35-math-libraries.md)
libraries).  In practice, this means that very few system calls may be
used within interrupt code. The following functions may generally be used
safely within interrupts:


```c
    [Alert()](autodocs-2.0/exec-library-alert.md), [Disable()](libraries/21-task-exclusion-disabling-tasks.md), [Enable()](libraries/21-task-exclusion-disabling-tasks.md), [Signal()](libraries/22-the-signal-system-generating-a-signal.md), [Cause()](libraries/26-exec-interrupts-software-interrupts.md),
    [GetMsg()](libraries/24-messages-getting-a-message.md), [PutMsg()](libraries/24-messages-putting-a-message.md), [ReplyMsg()](libraries/24-messages-replying.md), [FindPort()](libraries/24-message-ports-how-to-rendezvous-at-a-message-port.md), [FindTask()](libraries/21-exec-tasks-task-structure.md)
```
and if you are manipulating your own [List](libraries/23-list-structure-list-header-structure-definition.md) structures while in an interrupt:


```c
    [AddHead()](libraries/23-list-functions-special-case-insertion.md), [AddTail()](libraries/23-list-functions-special-case-insertion.md), [RemHead()](libraries/23-list-functions-special-case-removal.md), [RemTail()](libraries/23-list-functions-special-case-removal.md), [FindName()](libraries/23-list-functions-searching-by-name.md)
```
In addition, certain devices (notably the timer device) specifically allow
limited use of [SendIO()](libraries/19-exec-device-i-o-using-a-device.md) and [BeginIO()](libraries/19-exec-device-i-o-using-a-device.md) within interrupts.

---

## See Also

- [AddHead — exec.library](../autodocs/exec.library.md#addhead)
- [AddTail — exec.library](../autodocs/exec.library.md#addtail)
- [Alert — exec.library](../autodocs/exec.library.md#alert)
- [Cause — exec.library](../autodocs/exec.library.md#cause)
- [Disable — exec.library](../autodocs/exec.library.md#disable)
- [Enable — exec.library](../autodocs/exec.library.md#enable)
- [FindName — exec.library](../autodocs/exec.library.md#findname)
- [FindPort — exec.library](../autodocs/exec.library.md#findport)
- [FindTask — exec.library](../autodocs/exec.library.md#findtask)
- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [GetMsg — exec.library](../autodocs/exec.library.md#getmsg)
- [Permit — exec.library](../autodocs/exec.library.md#permit)
- [PutMsg — exec.library](../autodocs/exec.library.md#putmsg)
- [RemHead — exec.library](../autodocs/exec.library.md#remhead)
- [RemTail — exec.library](../autodocs/exec.library.md#remtail)
- [ReplyMsg — exec.library](../autodocs/exec.library.md#replymsg)
- [SendIO — exec.library](../autodocs/exec.library.md#sendio)
- [Signal — exec.library](../autodocs/exec.library.md#signal)
