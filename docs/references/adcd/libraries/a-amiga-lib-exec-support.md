---
title: A / Amiga.lib / Exec Support
manual: libraries
chapter: libraries
section: a-amiga-lib-exec-support
functions: [SendIO]
libraries: [exec.library]
---

# A / Amiga.lib / Exec Support

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[BeginIO()](autodocs-2.0/amiga-lib-beginio.md)

```c
    This function takes an [IORequest](libraries/19-accessing-a-device-creating-an-i-o-request.md) and passes it directly to the
    BEGINIO vector of the proper device.  This works exactly like
    [SendIO()](autodocs-2.0/exec-library-sendio.md), but does not clear the [io_Flags](autodocs-2.0/includes-exec-io-h.md) field first. This function
    does not wait for the I/O to complete.
```
[CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md) and [DeleteExtIO()](autodocs-2.0/amiga-lib-deleteextio.md)

```c
    CreateExtIO() allocates memory for and initializes a new I/O request
    block of a program-specified number of bytes.  The number of bytes
    must be the size of a legal [IORequest](libraries/9-intuition-input-receiving-input-events-from-intuition.md) (or extended request) or very
    nasty things will happen. DeleteExtIO() frees up an I/O request as
    allocated by CreateExtIO(). The [mn_Length](autodocs-2.0/includes-exec-ports-h.md) field determines how much
    memory to deallocate.
```
[CreatePort()](autodocs-2.0/amiga-lib-createport.md) and [DeletePort()](autodocs-2.0/amiga-lib-deleteport.md)

```c
    CreatePort() allocates and initializes a new message port. The
    message list of the new port will be prepared for use via NewList().
    The port will be set to signal your task when a message arrives
    ([PA_SIGNAL](libraries/24-exec-messages-and-ports-message-ports.md)). DeletePort() deletes the port created by CreatePort().
    All messages that may have been attached to that port must already
    have been replied to.
```
[CreateStdIO()](autodocs-2.0/amiga-lib-createstdio.md) and [DeleteStdIO()](autodocs-2.0/amiga-lib-deletestdio.md)

```c
    CreateStdIO() allocates memory for and initializes a new [IOStdReq](autodocs-2.0/includes-exec-io-h.md)
    structure. DeleteStdIO() frees up an IOStdReq allocated by
    CreateStdIO().
```
[CreateTask()](autodocs-2.0/amiga-lib-createtask.md) and [DeleteTask()](autodocs-2.0/amiga-lib-deletetask.md)

```c
    These functions simplify creation and deletion of subtasks by
    dynamically allocating and initializing the required structures and
    stack space.  They also add the task to Exec's task list with the
    given name and priority.  A [tc_MemEntry](autodocs-2.0/includes-exec-tasks-h.md) list is provided so that all
    stack and structure memory allocated by CreateTask() is automatically
    deallocated when the task is removed. Before deleting a  task with
    DeleteTask(), you must first make sure that the task is not currently
    executing any system code which might try to signal the task after it
    is gone.
```
[NewList()](autodocs-2.0/amiga-lib-newlist.md)

```c
    Prepares a List structure for use; the list will be empty and ready
    to use.
```

---

## See Also

- [SendIO — exec.library](../autodocs/exec.library.md#sendio)
