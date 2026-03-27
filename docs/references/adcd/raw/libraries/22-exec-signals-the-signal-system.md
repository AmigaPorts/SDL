# 22 Exec Signals / The Signal System


The signal system is designed to support independent simultaneous events,
so several signals can occur at the same time.  Each task has 32
independent signals, 16 of which are pre-allocated for use by the
operating system.  The signals in use by a particular task are represented
as bits in a 32-bit field in its [Task](../Libraries_Manual_guide/node02BB.html) structure (<exec/[tasks.h](../Includes_and_Autodocs_2._guide/node008E.html#line23)>).  Two
other 32-bit fields in the Task structure indicate which signals the task
is waiting for, and which signals have been received.

Signals are task relative.  A task can only allocate its own signals, and
may only wait on its own signals.  In addition, a task may assign its own
significance to a particular signal.  Signals are not broadcast to all
tasks; they are directed only to individual tasks. A signal has meaning to
the task that defined it and to those tasks that have been informed of its
meaning.

For example, signal bit 12 may indicate a timeout event to one task, but
to another task it may indicate a message arrival event. You can never
wait on a signal that you did not directly or indirectly allocate
yourself, and any other task that wishes to signal you must use a signal
that you allocated.

 [Signal Allocation](../Libraries_Manual_guide/node02D3.html)    [Waiting for a Signal](../Libraries_Manual_guide/node02D4.html)    [Generating a Signal](../Libraries_Manual_guide/node02D5.html) 

