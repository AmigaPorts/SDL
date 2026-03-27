# exec.library/FindTask



   NAME
	FindTask -- find a task with the given name or find oneself

   SYNOPSIS
	task = FindTask(name)
	D0		A1

	struct [Task](../Includes_and_Autodocs_3._guide/node064B.html#line23) *FindTask(STRPTR);

   FUNCTION
	This function will check all task queues for a task with the given
	name, and return a pointer to its task control block.  If a NULL
	name pointer is given a pointer to the current task will be
	returned.

	Finding oneself with a NULL for the name is very quick.  Finding a
	task by name is very system expensive, and will disable interrupts
	for a long time.  Since a task may remove itself at any time,
	a [Forbid()/Permit()](../Includes_and_Autodocs_3._guide/node0224.html) pair may be needed to ensure the pointer
	returned by FindTask() is still valid when used.

   INPUT
	name - pointer to a name string

   RESULT
	task - pointer to the task (or Process)

