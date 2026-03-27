# 21 / Task Creation / Task Creation With Amiga.lib


A simpler method of creating a task is provided by the amiga.lib Exec
support function [CreateTask()](../Includes_and_Autodocs_2._guide/node014A.html), which can be accessed if your code is
linked with amiga.lib.


```c
    CreateTask(char *name, LONG priority, APTR initialPC, ULONG stacksize)
```
A task created with [CreateTask()](../Includes_and_Autodocs_2._guide/node014A.html) may be removed with the amiga.lib
[DeleteTask()](../Includes_and_Autodocs_2._guide/node0155.html) function, or it may simply return when it is finished.
CreateTask() adds a [MemList](../Libraries_Manual_guide/node02B1.html) to the [tc_MemEntry](../Libraries_Manual_guide/node02BB.html#line28) of the task it creates,
describing all memory it has allocated for the task, including the task
stack and the [Task](../Libraries_Manual_guide/node02BB.html) structure itself.  This memory will be deallocated by
Exec when the task is either explicitly removed ([RemTask()](../Libraries_Manual_guide/node02D0.html#line5) or
DeleteTask()) or when it exits to Exec's default task removal code
(RemTask()).

Note that a bug in the [CreateTask()](../Includes_and_Autodocs_2._guide/node014A.html) code caused a failed memory allocation
to go unnoticed in V33 and early versions of Release 2 amiga.lib.

If your development language is not linkable with amiga.lib, it may
provide an equivalent built-in function, or you can create your own based
on the "createtask.c" code in the Amiga ROM Kernel Reference Manual:
Includes and Autodocs.

Depending on the priority of a new task and the priorities of other tasks
in the system, the newly added task may begin execution immediately.


    Sharing Library Pointers
    ------------------------
    Although in most cases it is possible for a parent task to pass a
    library base to a child task so the child can use that library, for
    some libraries, this is not possible.  For this reason, the only
    library base sharable between tasks is Exec's library base.
Here is an example of simple task creation.  In this example there is no
coordination or communication between the main process and the simple task
it has created.  A more complex example might use named ports and messages
to coordinate the activities and shutdown of two tasks.  Because our task
is very simple and never calls any system functions which could cause it
to be signalled or awakened, we can safely remove the task at any time.


```c
    Keep This In Mind.
    ------------------
    Because the simple task's code is a function in our program, we must
    stop the subtask before exiting.

     [simpletask.c](../Libraries_Manual_guide/node058F.html) 
```
