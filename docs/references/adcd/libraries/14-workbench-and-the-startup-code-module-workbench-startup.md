---
title: 14 / Workbench and the Startup Code Module / Workbench Startup
manual: libraries
chapter: libraries
section: 14-workbench-and-the-startup-code-module-workbench-startup
functions: [Forbid, GetMsg, ReplyMsg]
libraries: [exec.library]
---

# 14 / Workbench and the Startup Code Module / Workbench Startup

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When the user activates a project or tool icon, the program is run as a
separate process asynchronous to Workbench.  This allows the user to take
full advantage of the multitasking features of the Amiga.  A process is
simply a task with additional information needed to use DOS library.

When Workbench loads and starts a program, its sends the program a
[WBStartup](libraries/14-workbench-environment-wbstartup-message.md) message containing the arguments as described earlier.  The
WBStartup also contains a pointer to the new [Process](libraries/17-introduction-to-exec-multitasking.md) structure which
describes the execution environment of the program.  The WBStartup message
is posted to the message port of the program's Process structure.

The [Process](libraries/17-introduction-to-exec-multitasking.md) message port is for the exclusive use of DOS, so this message
must be removed from the port before using any DOS library functions.
Normally this is handled by the startup code module that comes with your
compiler so you don't have to worry about this unless you are writing your
own startup code.

Standard startup code modules also set up [SysBase](libraries/1-dynamic-memory-architecture-exec-the-system-executive.md), the pointer to the Exec
master library, and open the DOS library setting up [DOSBase](libraries/17-libraries-and-devices-calling-a-library-function.md).   That is why
Exec and AmigaDOS functions can be called by C applications without first
opening a library; the startup code that applications are linked with
handles this.  Some special startups may also set up NIL: input and output
streams, or may open a stdio window so that the Workbench applications can
use stdio functions such as [printf()](autodocs-2.0/amiga-lib-printf.md).

The startup code can tell if it is running in the Workbench environment
because the [pr_CLI](autodocs-2.0/includes-dos-dosextens-h.md) field of the [Process](libraries/17-introduction-to-exec-multitasking.md) structure will contain NULL.  In
that case the startup code removes the [WBStartup](libraries/14-workbench-environment-wbstartup-message.md) message from the Process
message port with [GetMsg()](libraries/24-messages-getting-a-message.md) before using any functions in the DOS library.


```c
    Do Not Use the Process Message Port for Anything Else.
    ------------------------------------------------------
    The message port in a [Process](libraries/17-introduction-to-exec-multitasking.md) structure is for the exclusive use
    of the DOS library.
```
Standard startup code will pass the [WBStartup](libraries/14-workbench-environment-wbstartup-message.md) message pointer in argv and
0 (zero) in argc if the program is started from Workbench.  These values
are pushed onto the stack, and the startup code calls the application code
that it is linked with as a function.  When the application code exits
back to the startup code, the startup code closes and frees all opens and
allocations it made.  It will then [Forbid()](libraries/21-exec-tasks-function-reference.md), and [ReplyMsg()](libraries/24-messages-replying.md) the WBStartup
message, notifying Workbench that the application [Process](libraries/17-introduction-to-exec-multitasking.md) may be
terminated and its code unloaded from memory.


```c
    Avoid the DOS Exit() function.
    ------------------------------
    The DOS [Exit()](autodocs-2.0/dos-library-exit.md) function does not return an application to the
    startup code that called it.  If you wish to exit your application,
    use the exit function provided by your startup code (usually
    lower-case exit(), or _exit for assembler), passing it a valid
    DOS return code as listed in the include file <libraries/[dos.h](autodocs-2.0/includes-libraries-dos-h.md)>.
```

---

## See Also

- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [GetMsg — exec.library](../autodocs/exec.library.md#getmsg)
- [ReplyMsg — exec.library](../autodocs/exec.library.md#replymsg)
