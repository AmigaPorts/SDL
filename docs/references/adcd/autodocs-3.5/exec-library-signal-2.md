---
title: exec.library/Signal
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-signal-2
functions: [SetSignal, Wait]
libraries: [exec.library]
---

# exec.library/Signal

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	Signal -- signal a task

   SYNOPSIS
	Signal(task, signals)
	       A1    D0

	void Signal(struct [Task](autodocs-3.5/include-exec-tasks-h.md) *,ULONG);

   FUNCTION
	This function signals a task with the given signals.  If the task
	is currently waiting for one or more of these signals, it will be
	made ready and a reschedule will occur. If the task is not waiting
	for any of these signals, the signals will be posted to the task
	for possible later use. A signal may be sent to a task regardless
	of whether it is running, ready, or waiting.

	This function is considered "low level".  Its main purpose is to
	support multiple higher level functions like [PutMsg](autodocs-3.5/exec-library-putmsg-2.md).

	This function is safe to call from interrupts.

   INPUT
	task - the task to be signalled
	signals - the signals to be sent

   SEE ALSO
	[Wait()](autodocs-3.5/exec-library-wait-2.md), [SetSignal()](autodocs-3.5/exec-library-setsignal-2.md)

---

## See Also

- [SetSignal — exec.library](../autodocs/exec.library.md#setsignal)
- [Wait — exec.library](../autodocs/exec.library.md#wait)
