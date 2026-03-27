---
title: 22 Exec Signals / The Signal System
manual: libraries
chapter: libraries
section: 22-exec-signals-the-signal-system
functions: []
libraries: []
---

# 22 Exec Signals / The Signal System

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The signal system is designed to support independent simultaneous events,
so several signals can occur at the same time.  Each task has 32
independent signals, 16 of which are pre-allocated for use by the
operating system.  The signals in use by a particular task are represented
as bits in a 32-bit field in its [Task](libraries/21-exec-tasks-task-structure.md) structure (<exec/[tasks.h](autodocs-2.0/includes-exec-tasks-h.md)>).  Two
other 32-bit fields in the Task structure indicate which signals the task
is waiting for, and which signals have been received.

Signals are task relative.  A task can only allocate its own signals, and
may only wait on its own signals.  In addition, a task may assign its own
significance to a particular signal.  Signals are not broadcast to all
tasks; they are directed only to individual tasks. A signal has meaning to
the task that defined it and to those tasks that have been informed of its
meaning.

For example, signal bit 12 may indicate a timeout event to one task, but
to another task it may indicate a message arrival event. You can never
wait on a signal that you did not directly or indirectly allocate
yourself, and any other task that wishes to signal you must use a signal
that you allocated.

 [Signal Allocation](libraries/22-the-signal-system-signal-allocation.md)    [Waiting for a Signal](libraries/22-the-signal-system-waiting-for-a-signal.md)    [Generating a Signal](libraries/22-the-signal-system-generating-a-signal.md) 

