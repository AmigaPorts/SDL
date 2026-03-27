---
title: D / Errors / Memory Loss--Workbench Only
manual: libraries
chapter: libraries
section: d-errors-memory-loss-workbench-only
functions: [ReplyMsg]
libraries: [exec.library]
---

# D / Errors / Memory Loss--Workbench Only

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Commonly, this is caused by a failure of your code to unload after you
exit.  Make sure that your code is being linked with a standard correct
startup module, and do not use the [Exit](autodocs-2.0/dos-library-exit.md)(n) function to exit your program.
This function will bypass your startup code's cleanup, including its
[ReplyMsg()](libraries/24-messages-getting-a-message.md) of the [WBStartup](libraries/14-workbench-environment-wbstartup-message.md) message (which would signal Workbench to
unload your program from memory).  You should exit via either exit(n)
where n is a valid DOS error code such as RETURN_OK (<dos/[dos.h](autodocs-2.0/includes-dos-dos-h.md)>), or via
final "}" or return.  Assembler programmers using startup code can JMP to
_exit with a long return value on stack, or use the RTS instruction.

---

## See Also

- [ReplyMsg — exec.library](../autodocs/exec.library.md#replymsg)
