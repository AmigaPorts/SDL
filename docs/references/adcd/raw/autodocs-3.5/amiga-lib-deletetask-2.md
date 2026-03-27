# amiga.lib/DeleteTask



   NAME
	DeleteTask -- delete a task created with [CreateTask()](../Includes_and_Autodocs_3._guide/node002C.html)

   SYNOPSIS
	DeleteTask(task)

	VOID DeleteTask(struct [Task](../Includes_and_Autodocs_3._guide/node064B.html#line23) *);

   FUNCTION
	This function simply calls [exec.library/RemTask()](../Includes_and_Autodocs_3._guide/node0234.html), deleting a task
	from the Exec task lists and automatically freeing any stack and
	structure memory allocated for it by [CreateTask()](../Includes_and_Autodocs_3._guide/node002C.html).

	Before deleting a task, you must first make sure that the task is
	not currently executing any system code which might try to signal
	the task after it is gone.

	This can be accomplished by stopping all sources that might reference
	the doomed task, then causing the subtask to execute a Wait(0L).
	Another option is to have the task call [DeleteTask()/RemTask()](../Includes_and_Autodocs_3._guide/node0234.html) on
	itself.

   INPUTS
	task - task to remove from the system

   NOTE
	This function simply calls [exec.library/RemTask()](../Includes_and_Autodocs_3._guide/node0234.html), so you can call
	[RemTask()](../Includes_and_Autodocs_3._guide/node0234.html) directly instead of calling this function.

   SEE ALSO
	[CreateTask()](../Includes_and_Autodocs_3._guide/node002C.html), [exec.library/RemTask()](../Includes_and_Autodocs_3._guide/node0234.html)

