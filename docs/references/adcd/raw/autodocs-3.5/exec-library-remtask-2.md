# exec.library/RemTask



   NAME
	RemTask -- remove a task from the system

   SYNOPSIS
	RemTask(task)
		A1

	void RemTask(struct [Task](../Includes_and_Autodocs_3._guide/node064B.html#line23) *);

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
	task, and that task was created with [amiga.lib/CreateTask](../Includes_and_Autodocs_3._guide/node002C.html), there was
	a slight chance of a crash.  The problem can be hidden by bracketing
	RemTask() with [Forbid()/Permit()](../Includes_and_Autodocs_3._guide/node0224.html).

   SEE ALSO
	[AddTask()](../Includes_and_Autodocs_3._guide/node01E2.html), [AllocEntry()](../Includes_and_Autodocs_3._guide/node01E6.html), [amiga.lib/DeleteTask()](../Includes_and_Autodocs_3._guide/node0037.html)

