---
title: exec.library/RemTask
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-remtask-2
functions: [Forbid, Permit, RemTask]
libraries: [exec.library]
---

# exec.library/RemTask

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	RemTask -- remove a task from the system

   SYNOPSIS
	RemTask(task)
		A1

	void RemTask(struct [Task](autodocs-3.5/include-exec-tasks-h.md) *);

   FUNCTION
	This function removes a task from the system.  Deallocation of
	resources should have been performed prior to calling this
	function.  Removing some other task is very dangerous.	Generally
	is is best to arrange for tasks to call RemTask(0L) on themselves.

	RemTask will automagically free any memory lists attached to the
	task's TC_MEMENTRY list.

   INPUTS
	task - pointer to the task node representing the task to be
	       removed.  A zero value indicates self removal, and will
	       cause the next ready task to begin execution.

   BUGS
	Before V36 if RemTask() was called on a task other than the current
	task, and that task was created with [amiga.lib/CreateTask](autodocs-3.5/amiga-lib-createtask-2.md), there was
	a slight chance of a crash.  The problem can be hidden by bracketing
	RemTask() with [Forbid()/Permit()](autodocs-3.5/exec-library-permit-2.md).

   SEE ALSO
	[AddTask()](autodocs-3.5/exec-library-addtask-2.md), [AllocEntry()](autodocs-3.5/exec-library-allocentry-2.md), [amiga.lib/DeleteTask()](autodocs-3.5/amiga-lib-deletetask-2.md)

---

## See Also

- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [Permit — exec.library](../autodocs/exec.library.md#permit)
- [RemTask — exec.library](../autodocs/exec.library.md#remtask)
