---
title: exec.library/SetTaskPri
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-settaskpri-2
functions: []
libraries: []
---

# exec.library/SetTaskPri

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SetTaskPri -- get and set the priority of a task

   SYNOPSIS
	oldPriority = SetTaskPri(task, priority)
	D0-0:8			 A1    D0-0:8

	[BYTE](autodocs-3.5/include-exec-types-h.md) SetTaskPri(struct [Task](autodocs-3.5/include-exec-tasks-h.md) *,LONG);

   FUNCTION
	This function changes the priority of a task regardless of its
	state.	The old priority of the task is returned.  A reschedule is
	performed, and a context switch may result.

	To change the priority of the currently running task, pass the
	result of FindTask(0); as the task pointer.

   INPUTS
	task - task to be affected
	priority - the new priority for the task

   RESULT
	oldPriority - the tasks previous priority

