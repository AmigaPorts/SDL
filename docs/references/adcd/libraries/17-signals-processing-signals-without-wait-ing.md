---
title: 17 / Signals / Processing Signals Without Wait()ing
manual: libraries
chapter: libraries
section: 17-signals-processing-signals-without-wait-ing
functions: [Delay, SetSignal, Wait, WaitForChar, WaitTOF]
libraries: [dos.library, exec.library, graphics.library]
---

# 17 / Signals / Processing Signals Without Wait()ing

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

In some cases an application may need to process signals but cannot go to
sleep to wait for them.  For example, a compiler might want to check to
see if the user hit Control-C, but it can't to go to sleep to check for
the break because that will stop the compiler.  In this case, the task can
periodically check its own signal bits for the Ctrl-C break signal using
the Exec library function, [SetSignal()](autodocs-2.0/exec-library-setsignal.md):


```c
    oldsignals = ULONG SetSignal(ULONG newsignals, ULONG signalmask);
```
Although [SetSignal()](autodocs-2.0/exec-library-setsignal.md) can change a task's signal bits, it can also monitor
them.  The following fragment illustrates using SetSignal() to poll a
task's signal bits for a Ctrl-C break:


```c
    /* Get current state of signals */
    signals = SetSignal(0L, 0L);

    /* check for Ctrl-C */
    if (signals & SIGBREAKF_CTRL_C)
    {
        /* The Ctrl-C signal has been set, take care of processing it... */

        /* ...then clear the Ctrl-C signal */
        SetSignal(0L, SIGBREAKF_CTRL_C);
    }
```
If your task is waiting for signals, but is also waiting for other events
that have no signal bit (such as input characters from standard input),
you may need to use [SetSignal()](autodocs-2.0/exec-library-setsignal.md).  In such cases, you must be careful not
to poll in a tight loop (also known as busy-waiting).  Busy-waiting hogs
CPU time and degrades the performance of other tasks.  One easy way around
this is for a task to sleep briefly within its polling loop by using the
timer.device, or the graphics function [WaitTOF()](libraries/28-displaying-the-vsprites-synchronizing-with-the-display.md), or (if the task is a
[Process](libraries/17-introduction-to-exec-multitasking.md)) the DOS library [Delay()](autodocs-2.0/dos-library-delay.md)) or [WaitForChar()](autodocs-2.0/dos-library-waitforchar.md) functions.

For more information on signals, see the "[Exec Signals](libraries/22-exec-signals.md)" chapter of this
manual.

---

## See Also

- [Delay — dos.library](../autodocs/dos.library.md#delay)
- [SetSignal — exec.library](../autodocs/exec.library.md#setsignal)
- [Wait — exec.library](../autodocs/exec.library.md#wait)
- [WaitForChar — dos.library](../autodocs/dos.library.md#waitforchar)
- [WaitTOF — graphics.library](../autodocs/graphics.library.md#waittof)
