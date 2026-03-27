# 21 / Task Exclusion / Forbidding Task Switching


Forbidding is used when a task is accessing shared structures that might
also be accessed at the same time from another task.  It effectively
eliminates the possibility of simultaneous access by imposing
nonpreemptive task scheduling.  This has the net effect of disabling
multitasking for as long as your task remains in its running state. While
forbidden, your task will continue running until it performs a call to
[Wait()](../Libraries_Manual_guide/node02D4.html) or exits from the forbidden state.  Interrupts will occur normally,
but no new tasks will be dispatched, regardless of their priorities.

When a task running in the forbidden state calls the [Wait()](../Libraries_Manual_guide/node02D4.html) function,
directly or indirectly, it implies a temporary exit from its forbidden
state. Since almost all stdio, device I/O, and file I/O functions must
Wait() for I/O completion, performing such calls will cause your task to
Wait(), temporarily breaking the forbid.  While the task is waiting, the
system will perform normally.  When the task receives one of the signals
it is waiting for, it will again reenter the forbidden state. To become
forbidden, a task calls the [Forbid()](../Includes_and_Autodocs_2._guide/node0353.html) function.  To escape, the [Permit()](../Includes_and_Autodocs_2._guide/node0369.html)
function is used.  The use of these functions may be nested with the
expected affects; you will not exit the forbidden mode until you call the
outermost Permit().

As an example, the Exec task list should only be accessed when in a
[Forbid()](../Includes_and_Autodocs_2._guide/node0353.html) state.  Accessing the list without forbidding could lead to
incorrect results or it could crash the entire system.  To access the task
list also requires the program to disable interrupts which is discussed in
the [next section](../Libraries_Manual_guide/node02C3.html).

