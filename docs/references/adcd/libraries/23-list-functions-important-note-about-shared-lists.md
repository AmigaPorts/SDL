---
title: 23 / List Functions / Important Note About Shared Lists
manual: libraries
chapter: libraries
section: 23-list-functions-important-note-about-shared-lists
functions: [Disable, Forbid, ObtainSemaphore, Wait]
libraries: [exec.library]
---

# 23 / List Functions / Important Note About Shared Lists

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

It is possible to run into contention problems with other tasks when
manipulating a list that is shared by more than one task.  None of the
standard Exec list functions arbitrates for access to the list.  For
example, if some other task happens to be modifying a list while your task
scans it, an inconsistent view of the list may be formed.  This can result
in a corrupted system.

Generally it is not permissible to read or write a shared list without
first locking out access from other tasks.  All users of a list must use
the same arbitration method.  Several arbitration techniques are used on
the Amiga.  Some lists are protected by a semaphore.  The [ObtainSemaphore()](libraries/25-the-signal-semaphore-obtaining-a-signalsemaphore.md)
call grants ownership of the list (see the "[Exec Semaphores](libraries/25-exec-semaphores.md)" chapter for
more information).  Some lists require special arbitration. For example,
you must use the Intuition [LockIBase](libraries/11-intuition-special-functions-locking-intuitionbase.md)(0) call before accessing any
Intuition lists.  Other lists may be accessed only during [Forbid()](libraries/21-task-exclusion-forbidding-task-switching.md) or
[Disable()](libraries/21-task-exclusion-disabling-tasks.md) (see the "[Exec Tasks](libraries/21-exec-tasks-task-exclusion.md)" chapter for more information).

The preferred method for arbitrating use of a shared list is through
semaphores because a semaphores only holds off other tasks that are trying
to access the shared list.  Rather than suspending all multitasking.
Failure to lock a shared list before use will result in unreliable
operation.

Note that I/O functions including [printf()](autodocs-2.0/amiga-lib-printf.md) generally call [Wait()](libraries/22-the-signal-system-waiting-for-a-signal.md) to wait
for I/O completion, and this allows other tasks to run.  Therefore, it is
not safe to print or Wait() while traversing a list unless the list is
fully controlled by your application, or if the list is otherwise
guaranteed not to change during multitasking.

---

## See Also

- [Disable — exec.library](../autodocs/exec.library.md#disable)
- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [ObtainSemaphore — exec.library](../autodocs/exec.library.md#obtainsemaphore)
- [Wait — exec.library](../autodocs/exec.library.md#wait)
