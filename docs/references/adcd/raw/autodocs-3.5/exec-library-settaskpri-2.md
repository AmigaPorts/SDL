# exec.library/SetTaskPri



   NAME
	SetTaskPri -- get and set the priority of a task

   SYNOPSIS
	oldPriority = SetTaskPri(task, priority)
	D0-0:8			 A1    D0-0:8

	[BYTE](../Includes_and_Autodocs_3._guide/node0654.html#line48) SetTaskPri(struct [Task](../Includes_and_Autodocs_3._guide/node064B.html#line23) *,LONG);

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

