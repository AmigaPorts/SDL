---
title: 1 / / Multitasking / What the System Does For You
manual: libraries
chapter: libraries
section: 1-multitasking-what-the-system-does-for-you
functions: [AllocMem]
libraries: [exec.library]
---

# 1 / / Multitasking / What the System Does For You

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Amiga uses preemptive [multitasking](libraries/17-introduction-to-exec-multitasking.md) which means that the operating
system keeps track of all the tasks in memory and decides which one should
run.  The system checks hundreds of times per second to see which task
should be run based on whether or not it is waiting, and other factors.
Since the system handles all the work of task switching, multitasking is
transparent to the application.  From the application's point of view, it
appears to have the machine all to itself.

The Amiga OS also manages the sharing of resources between tasks.  This is
important because in order for a variety of tasks to run independently in
the Amiga's [multitasking](libraries/17-introduction-to-exec-multitasking.md) environment, tasks must be prevented from
interfering with one another.  Imagine if five tasks were allowed to use
the parallel port at the same time.  The result would be I/O chaos.  To
prevent this, the operating system provides an arbitration method (usually
a function call) for every system resource.  For instance you must call a
function, [AllocMem()](libraries/20-exec-memory-allocation-memory-functions.md), to get exclusive access to a block of memory.

---

## See Also

- [AllocMem — exec.library](../autodocs/exec.library.md#allocmem)
