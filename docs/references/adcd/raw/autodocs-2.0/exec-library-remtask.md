# exec.library/RemTask



NAME

    RemTask -- remove a task from the system
SYNOPSIS

```c
    RemTask(task)
            A1

    void RemTask(struct [Task](../Includes_and_Autodocs_2._guide/node008E.html#line25) *);
```
FUNCTION

```c
    This function removes a task from the system.  Deallocation of
    resources should have been performed prior to calling this
    function.  Removing some other task is very dangerous.  Generally
    is is best to arrange for tasks to call RemTask(0L) on themselves.

    RemTask will automagically free any memory lists attached to the
    task's TC_MEMENTRY list.
```
INPUTS

    task - pointer to the task node representing the task to be
           removed.  A zero value indicates self removal, and will
           cause the next ready task to begin execution.
BUGS

```c
    Before V36 if RemTask() was called on a task other than the current
    task, and that task was created with [amiga.lib/CreateTask](../Includes_and_Autodocs_2._guide/node014A.html), there was
    a slight chance of a crash.  The problem can be hidden by bracketing
    RemTask() with [Forbid()/Permit()](../Includes_and_Autodocs_2._guide/node0369.html).
```
SEE ALSO

```c
    [AddTask](../Includes_and_Autodocs_2._guide/node032D.html), [exec/AllocEntry](../Includes_and_Autodocs_2._guide/node0331.html), [amiga.lib/DeleteTask](../Includes_and_Autodocs_2._guide/node0155.html)
```
