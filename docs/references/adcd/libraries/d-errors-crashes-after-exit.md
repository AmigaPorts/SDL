---
title: D / Errors / Crashes--After Exit
manual: libraries
chapter: libraries
section: d-errors-crashes-after-exit
functions: [AbortIO, Lock, UnLock, WaitIO, WaitTOF]
libraries: [dos.library, exec.library, graphics.library, timer.device]
---

# D / Errors / Crashes--After Exit

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

If this only happens when you start your program [from Workbench](libraries/14-workbench-environment-wbstartup-message.md), then you
are probably [UnLock()](autodocs-2.0/dos-library-unlock.md)ing one of the [WBStartup](libraries/14-workbench-environment-wbstartup-message.md) message [wa_Locks](libraries/14-workbench-environment-wbstartup-message.md), or
UnLock()ing the [Lock()](autodocs-2.0/dos-library-lock.md) returned from an initial [CurrentDir()](autodocs-2.0/dos-library-currentdir.md) call.  If you
CurrentDir(), save the lock returned initially, and CurrentDir() back to
it before you exit. Only UnLock() locks that you created.

If you are crashing from both Workbench and CLI, and you are only crashing
after exit, then you are probably either freeing/closing something twice,
or freeing/closing something your did not actually allocate/open, or you
may be leaving an outstanding device I/O request or other wakeup request.
You must abort and WaitIO() any outstanding I/O requests before you free
things and exit (see the Autodocs for your device, and for Exec [AbortIO()](autodocs-2.0/exec-library-abortio.md)
and [WaitIO()](autodocs-2.0/exec-library-waitio.md)).  Similar problems can be caused by deleting a subtask that
might be in a WaitTOF().  Only delete subtasks when you are sure they are
in a safe state such as [Wait](libraries/22-the-signal-system-waiting-for-a-signal.md)(0L).

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [Lock — dos.library](../autodocs/dos.library.md#lock)
- [UnLock — dos.library](../autodocs/dos.library.md#unlock)
- [WaitIO — exec.library](../autodocs/exec.library.md#waitio)
- [WaitTOF — graphics.library](../autodocs/graphics.library.md#waittof)
