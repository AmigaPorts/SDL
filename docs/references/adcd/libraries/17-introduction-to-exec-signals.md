---
title: 17 Introduction to Exec / Signals
manual: libraries
chapter: libraries
section: 17-introduction-to-exec-signals
functions: [Wait]
libraries: [exec.library]
---

# 17 Introduction to Exec / Signals

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Amiga uses a mechanism called signals to tell a task that some event
occurred.  Each task has its own set of 32 signals, 16 of which are set
aside for system use.  When one task signals a second task, it asks the OS
to set a specific bit in the 32-bit long word set aside for the second
task's signals.

Signals are what makes it possible for a task to go to sleep.  When a task
goes to sleep, it asks the OS to wake it up when a specific signal bit
gets set.  That bit is tied to some event.  When that event occurs, that
signal bit gets set.  This triggers the OS into waking up the sleeping
task.

To go to sleep, a task calls a system function called [Wait()](libraries/22-the-signal-system-waiting-for-a-signal.md). This
function takes one argument, a bitmask that tells Exec which of the task's
signal bits to "listen to".  The task will only wake up if it receives one
of the signals whose corresponding bit is set in that bitmask.  For
example, if a task wanted to wait for signals 17 and 19, it would call
Wait() like this:


```c
    mysignals = Wait(1L<<17 | 1L<<19);
```
[Wait()](libraries/22-the-signal-system-waiting-for-a-signal.md) puts the task to sleep and will not return until some other task
sets at least one of these two signals.  When the task wakes up, mysignals
will contain the bitmask of the signal or signals that woke up the task.
It is possible for several signals to occur simultaneously, so any
combination of the signals that the task Wait()ed on can occur.  It is up
to the waking task to use the return value from Wait() to figure out which
signal or signals occurred.

 [Looking for Break Keys](libraries/17-signals-looking-for-break-keys.md)    [Processing Signals Without Wait()ing](libraries/17-signals-processing-signals-without-wait-ing.md) 

---

## See Also

- [Wait — exec.library](../autodocs/exec.library.md#wait)
