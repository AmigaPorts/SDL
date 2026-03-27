# exec.library/Signal



   NAME
	Signal -- signal a task

   SYNOPSIS
	Signal(task, signals)
	       A1    D0

	void Signal(struct [Task](../Includes_and_Autodocs_3._guide/node064B.html#line23) *,ULONG);

   FUNCTION
	This function signals a task with the given signals.  If the task
	is currently waiting for one or more of these signals, it will be
	made ready and a reschedule will occur. If the task is not waiting
	for any of these signals, the signals will be posted to the task
	for possible later use. A signal may be sent to a task regardless
	of whether it is running, ready, or waiting.

	This function is considered "low level".  Its main purpose is to
	support multiple higher level functions like [PutMsg](../Includes_and_Autodocs_3._guide/node0226.html).

	This function is safe to call from interrupts.

   INPUT
	task - the task to be signalled
	signals - the signals to be sent

   SEE ALSO
	[Wait()](../Includes_and_Autodocs_3._guide/node0246.html), [SetSignal()](../Includes_and_Autodocs_3._guide/node023A.html)

