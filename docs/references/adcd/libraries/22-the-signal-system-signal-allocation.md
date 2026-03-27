---
title: 22 / The Signal System / Signal Allocation
manual: libraries
chapter: libraries
section: 22-the-signal-system-signal-allocation
functions: [AllocSignal, CreateMsgPort, DoIO, FreeSignal, OpenWindow, Wait, WaitIO, WaitPort]
libraries: [exec.library, intuition.library]
---

# 22 / The Signal System / Signal Allocation

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

As mentioned above, a task assigns its own meaning to a particular signal.
Because certain system libraries may occasionally require the use of a
signal, there is a convention for signal allocation.  It is unwise ever to
make assumptions about which signals are actually in use.

Before a signal can be used, it must be allocated with the [AllocSignal()](autodocs-2.0/exec-library-allocsignal.md)
function.  When a signal is no longer needed, it should be freed for reuse
with [FreeSignal()](autodocs-2.0/exec-library-freesignal.md).


```c
    BYTE AllocSignal( LONG signalNum );
    VOID FreeSignal( LONG signalNum );
```
[AllocSignal()](autodocs-2.0/exec-library-allocsignal.md) marks a signal as being in use and prevents the accidental
use of the same signal for more than one event.  You may ask for either a
specific signal number, or more commonly, you would pass -1 to request the
next available signal.  The state of the newly allocated signal is cleared
(ready for use).  Generally it is best to let the system assign you the
next free signal.  Of the 32 available signals, the lower 16 are reserved
for system use.  This leaves the upper 16 signals free for application
programs to allocate.  Other subsystems that you may call depend on
AllocSignal().

The following C example asks for the next free signal to be allocated for
its use:


```c
    if (-1 == (signal = AllocSignal(-1)))
        printf("no signal bits available\n");
    else
        {
        printf("allocated signal number %ld\n", signal);
        /* Other code could go here */
        FreeSignal(signal)
        }
```
The value returned by [AllocSignal()](autodocs-2.0/exec-library-allocsignal.md) is a signal bit number. This value
cannot be used directly in calls to signal-related functions without first
being converted to a mask:


```c
    mask = 1L << signal;
```
It is important to realize that signal bit allocation is relevant only to
the running task.  You cannot allocate a signal from another task.  Note
that functions which create a signal [MsgPort](libraries/24-exec-messages-and-ports-message-ports.md) will allocate a signal from
the task that calls the function.  Such functions include [OpenWindow()](libraries/4-basic-window-structures-and-functions-opening-a-window.md),
[CreatePort()](libraries/24-message-ports-creating-a-message-port.md), and [CreateMsgPort()](libraries/24-message-ports-creating-a-message-port.md).  For this reason, only the creating
task may [Wait()](libraries/22-the-signal-system-waiting-for-a-signal.md) (directly or indirectly) on the MsgPort's signal.
Functions which call Wait() include [DoIO()](libraries/19-exec-device-i-o-using-a-device.md), [WaitIO()](libraries/19-using-a-device-synchronous-vs-asynchronous-requests.md) and [WaitPort()](libraries/24-messages-waiting-for-a-message.md).

---

## See Also

- [AllocSignal — exec.library](../autodocs/exec.library.md#allocsignal)
- [CreateMsgPort — exec.library](../autodocs/exec.library.md#createmsgport)
- [DoIO — exec.library](../autodocs/exec.library.md#doio)
- [FreeSignal — exec.library](../autodocs/exec.library.md#freesignal)
- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
- [Wait — exec.library](../autodocs/exec.library.md#wait)
- [WaitIO — exec.library](../autodocs/exec.library.md#waitio)
- [WaitPort — exec.library](../autodocs/exec.library.md#waitport)
