# A / Amiga.lib / Exec Support


[BeginIO()](../Includes_and_Autodocs_2._guide/node0141.html)

```c
    This function takes an [IORequest](../Libraries_Manual_guide/node029D.html) and passes it directly to the
    BEGINIO vector of the proper device.  This works exactly like
    [SendIO()](../Includes_and_Autodocs_2._guide/node037A.html), but does not clear the [io_Flags](../Includes_and_Autodocs_2._guide/node0094.html#line28) field first. This function
    does not wait for the I/O to complete.
```
[CreateExtIO()](../Includes_and_Autodocs_2._guide/node0147.html) and [DeleteExtIO()](../Includes_and_Autodocs_2._guide/node0152.html)

```c
    CreateExtIO() allocates memory for and initializes a new I/O request
    block of a program-specified number of bytes.  The number of bytes
    must be the size of a legal [IORequest](../Libraries_Manual_guide/node01D2.html) (or extended request) or very
    nasty things will happen. DeleteExtIO() frees up an I/O request as
    allocated by CreateExtIO(). The [mn_Length](../Includes_and_Autodocs_2._guide/node0099.html#line46) field determines how much
    memory to deallocate.
```
[CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html) and [DeletePort()](../Includes_and_Autodocs_2._guide/node0153.html)

```c
    CreatePort() allocates and initializes a new message port. The
    message list of the new port will be prepared for use via NewList().
    The port will be set to signal your task when a message arrives
    ([PA_SIGNAL](../Libraries_Manual_guide/node02EB.html#line49)). DeletePort() deletes the port created by CreatePort().
    All messages that may have been attached to that port must already
    have been replied to.
```
[CreateStdIO()](../Includes_and_Autodocs_2._guide/node0149.html) and [DeleteStdIO()](../Includes_and_Autodocs_2._guide/node0154.html)

```c
    CreateStdIO() allocates memory for and initializes a new [IOStdReq](../Includes_and_Autodocs_2._guide/node0094.html#line28)
    structure. DeleteStdIO() frees up an IOStdReq allocated by
    CreateStdIO().
```
[CreateTask()](../Includes_and_Autodocs_2._guide/node014A.html) and [DeleteTask()](../Includes_and_Autodocs_2._guide/node0155.html)

```c
    These functions simplify creation and deletion of subtasks by
    dynamically allocating and initializing the required structures and
    stack space.  They also add the task to Exec's task list with the
    given name and priority.  A [tc_MemEntry](../Includes_and_Autodocs_2._guide/node008E.html#line25) list is provided so that all
    stack and structure memory allocated by CreateTask() is automatically
    deallocated when the task is removed. Before deleting a  task with
    DeleteTask(), you must first make sure that the task is not currently
    executing any system code which might try to signal the task after it
    is gone.
```
[NewList()](../Includes_and_Autodocs_2._guide/node0161.html)

```c
    Prepares a List structure for use; the list will be empty and ready
    to use.
```
