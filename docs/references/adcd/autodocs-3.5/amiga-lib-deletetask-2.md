---
title: amiga.lib/DeleteTask
manual: autodocs-3.5
chapter: autodocs-3.5
section: amiga-lib-deletetask-2
functions: [RemTask]
libraries: [exec.library]
---

# amiga.lib/DeleteTask

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	DeleteTask -- delete a task created with [CreateTask()](autodocs-3.5/amiga-lib-createtask-2.md)

   SYNOPSIS
	DeleteTask(task)

	VOID DeleteTask(struct [Task](autodocs-3.5/include-exec-tasks-h.md) *);

   FUNCTION
	This function simply calls [exec.library/RemTask()](autodocs-3.5/exec-library-remtask-2.md), deleting a task
	from the Exec task lists and automatically freeing any stack and
	structure memory allocated for it by [CreateTask()](autodocs-3.5/amiga-lib-createtask-2.md).

	Before deleting a task, you must first make sure that the task is
	not currently executing any system code which might try to signal
	the task after it is gone.

	This can be accomplished by stopping all sources that might reference
	the doomed task, then causing the subtask to execute a Wait(0L).
	Another option is to have the task call [DeleteTask()/RemTask()](autodocs-3.5/exec-library-remtask-2.md) on
	itself.

   INPUTS
	task - task to remove from the system

   NOTE
	This function simply calls [exec.library/RemTask()](autodocs-3.5/exec-library-remtask-2.md), so you can call
	[RemTask()](autodocs-3.5/exec-library-remtask-2.md) directly instead of calling this function.

   SEE ALSO
	[CreateTask()](autodocs-3.5/amiga-lib-createtask-2.md), [exec.library/RemTask()](autodocs-3.5/exec-library-remtask-2.md)

---

## See Also

- [RemTask — exec.library](../autodocs/exec.library.md#remtask)
