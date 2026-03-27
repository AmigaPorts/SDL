---
title: 22 / The Signal System / Waiting for a Signal
manual: libraries
chapter: libraries
section: 22-the-signal-system-waiting-for-a-signal
functions: [Disable, Forbid, SetSignal, Wait]
libraries: [exec.library]
---

# 22 / The Signal System / Waiting for a Signal

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Signals are most often used to wake up a task upon the occurrence of some
external event.  Applications call the Exec [Wait()](autodocs-2.0/exec-library-wait.md) function, directly or
indirectly, in order to enter a wait state until some external event
triggers a signal which awakens the task.

Though signals are usually not used to interrupt an executing task, they
can be used this way.  Task exceptions, described in the "[Exec Tasks](libraries/21-exec-tasks-task-exceptions.md)"
chapter, allow signals to act as a task-local interrupt.

The [Wait()](autodocs-2.0/exec-library-wait.md) function specifies the set of signals that will wake up the
task and then puts the task to sleep (into the waiting state).


```c
    ULONG Wait( ULONG signalSet );
```
Any one signal or any combination of signals from this set are sufficient
to awaken the task.  [Wait()](autodocs-2.0/exec-library-wait.md) returns a mask indicating which signals
satisfied the Wait() call.  Note that when signals are used in conjunction
with a message port, a set signal bit does not necessarily mean that there
is a message at the message port.  See the "[Exec Messages and Ports](libraries/24-messages-waiting-for-a-message.md)"
chapter for details about proper handling of messages.

Because tasks (and interrupts) normally execute asynchronously, it is
often possible to receive a particular signal before a task actually
[Wait()s](autodocs-2.0/exec-library-wait.md) for it.  In such cases the Wait() will be immediately satisfied,
and the task will not be put to sleep.

The [Wait()](autodocs-2.0/exec-library-wait.md) function implicitly clears those signal bits that satisfied the
wait condition.  This effectively resets those signals for reuse.
However, keep in mind that a task might get more signals while it is still
processing the previous signal.  If the same signal is received multiple
times and the signal bit is not cleared between them, some signals will go
unnoticed.

Be aware that using [Wait()](autodocs-2.0/exec-library-wait.md) will break a [Forbid()](libraries/21-task-exclusion-forbidding-task-switching.md) or [Disable()](libraries/21-task-exclusion-disabling-tasks.md) state.
Wait() cannot be used in supervisor mode or within interrupts.

A task may [Wait()](autodocs-2.0/exec-library-wait.md) for a combination of signal bits and will wake up when
any of the signals occur.  Wait() returns a signal mask specifying which
signal or signals were received.  Usually the program must check the
returned mask for each signal it was waiting on and take the appropriate
action for each that occurred.  The order in which these bits are checked
is often important.

Here is a hypothetical example of a process that is using the console and
timer devices, and is waiting for a message from either device and a
possible break character issued by the user:


```c
    consoleSignal = 1L << ConsolePort->mp_SigBit;
    timerSignal   = 1L << TimerPort->mp_SigBit;
    userSignal    = SIGBREAKF_CTRL_C;         /* Defined in <dos/dos.h> */

    signals = Wait(consoleSignal | timerSignal | userSignal);

    if (signals & consoleSignal)
        printf("new character\n");

    if (signals & timeOutSignal)
        printf("timeout\n");

    if (signals & userSignal)
        printf("User Ctrl-C Abort\n");
```
This code will put the task to sleep waiting for a new character, or the
expiration of a time period, or a Ctrl-C break character issued by the
user.  Notice that this code checks for an incoming character signal
before checking for a timeout.  Although a program can check for the
occurrence of a particular event by checking whether its signal has
occurred, this may lead to busy wait polling.  Such polling is wasteful of
the processor and is usually harmful to the proper function of the Amiga
system.  However, if a program needs to do constant processing and also
check signals (a compiler for example) [SetSignal](autodocs-2.0/exec-library-setsignal.md)(0,0) can be used to get a
copy of your task's current signals.


```c
    ULONG SetSignal( ULONG newSignals, ULONG signalSet );
```
[SetSignal()](autodocs-2.0/exec-library-setsignal.md) can also be used to set or clear the state of the signals.
Implementing this can be dangerous and should generally not be done. The
following fragment illustrates a possible use of SetSignal().


```c
    signals = SetSignal(0,0);           /* Get current state of signals */

    if (signals & SIGBREAKF_CTRL_C)     /* Check for Ctrl-C.           */
        {
        printf("Break\n");              /* Ctrl-C signal has been set. */
        SetSignal(0, SIGBREAKF_CTRL_C)  /* Clear Ctrl-C signal.        */
        }
```

---

## See Also

- [Disable — exec.library](../autodocs/exec.library.md#disable)
- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [SetSignal — exec.library](../autodocs/exec.library.md#setsignal)
- [Wait — exec.library](../autodocs/exec.library.md#wait)
