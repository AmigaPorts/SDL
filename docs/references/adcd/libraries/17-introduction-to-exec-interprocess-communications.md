---
title: 17 Introduction to Exec / Interprocess Communications
manual: libraries
chapter: libraries
section: 17-introduction-to-exec-interprocess-communications
functions: [GetMsg, ReplyMsg, WaitPort]
libraries: [exec.library]
---

# 17 Introduction to Exec / Interprocess Communications

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Another feature of the Amiga OS is its system of message-based
interprocess communication.  Using this system, a task can send a message
to a message port owned by another task.  Tasks use this mechanism to do
things like trigger events or share data with other tasks, including
system tasks.  Exec's message system is built on top of Exec's task
signaling mechanism.  Most Amiga applications programming (especially
Intuition programming) relies heavily upon this message-based form of
interprocess communication.

When one task sends a message to another task's message port, the OS adds
the message to the port's message queue.  The message stays in this queue
until the task that owns the port is ready to check its port for messages.
Typically, a task has put itself to sleep while it is waiting for an
event, like a message to arrive at its message port. When the message
arrives, the task wakes up to look in its message port.  The messages in
the message port's queue are arranged in first-in-first-out ([FIFO](libraries/24-exec-messages-and-ports.md)) order
so that, when a task receives several messages, it will see the messages
in the order they arrived at the port.

A task can use a message to share any kind of data with another task. This
is possible because a task does not actually transmit an entire message,
it only passes a pointer to a message.  When a task creates a message
(which can have many Kilobytes of data attached to it) and sends it to
another task, the actual message does not move.

Essentially, when task A sends a message to task B, task A lends task B a
chunk of its memory, the memory occupied by the message.  After task A
sends the message, it has relinquished that memory to task B, so it cannot
touch the memory occupied by the message.  Task B has control of that
memory until task B returns the message to task A with the [ReplyMsg()](libraries/24-messages-replying.md)
function.

Let's look at an example.  Many applications use Intuition windows as a
source for user input.  Without getting into too much detail about
Intuition, when an application opens a window, it can set up the window so
Intuition will send messages about certain user input events.  Intuition
sends these messages to a message port created by Intuition for use with
this window.  When an application successfully opens a window, it receives
a pointer to a [Window](libraries/4-intuition-windows-the-window-structure.md) structure, which contains a pointer to this message
port (Window.UserPort). For this example, we'll assume the window has been
set up so Intuition will send a message only if the user clicks the
window's close gadget.

When Intuition opens the window in this example, it creates a message port
for the task that opened the [Window](libraries/4-intuition-windows-the-window-structure.md).  Because the most common message
passing system uses signals, creating this message port involves using one
of the example task's 32 signals.  The OS uses this signal to signal the
task when it receives a message at this message port.  This allows the
task to sleep while waiting for a "Close Window" event to arrive.  Since
this simple example is only waiting for activity at one message port, it
can use the [WaitPort()](libraries/24-messages-waiting-for-a-message.md) function.  WaitPort() accepts a pointer to a
message port and puts a task to sleep until a message arrives at that port.

This simple example needs two variables, one to hold the address of the
window and the other to hold the address of a message.


```c
    struct Message *mymsg; /*defined in <exec/ports.h> */
    struct Window *mywin;  /* defined in <intuition/intuition.h> */
            ...

    /* at some point, this application would have successfully opened a */
    /* window and stored a pointer to it in mywin.                      */
        ...

        /* Here the application goes to sleep until the user clicks */
        /* the window's close gadget. This window was set up so     */
        /* that the only time Intuition will send a message to this */
        /* window's port is if the user clicks the window's close   */
        /* gadget.                                                  */

        WaitPort(mywin->UserPort);
        while (mymsg = GetMsg(mywin->UserPort))
            /* process message now or copy information from message */
            ReplyMsg(mymsg);
        ...

    /* Close window, clean up */
```
The Exec function [GetMsg()](libraries/24-messages-getting-a-message.md) is used to extract messages from the message
port.  Since the memory for these messages belongs to Intuition, the
example relinquishes each message as it finishes with them by calling
[ReplyMsg()](libraries/24-messages-replying.md).  Notice that the example keeps on trying to get messages from
the message port until mymsg is NULL.  This is to make sure there are no
messages left in the message port's message queue.  It is possible for
several messages to pile up in the message queue while the task is asleep,
so the example has to make sure it replies to all of them.  Note that the
window should never be closed within this GetMsg() loop because the while
statement is still accessing the window's UserPort.

Note that each task with a [Process](libraries/17-introduction-to-exec-multitasking.md) structure (sometimes referred to as a
process) has a special process message port, [Process.pr_MsgPort](autodocs-2.0/includes-dos-dosextens-h.md).  This
message port is only for use by Workbench and the DOS library itself.  No
application should use this port for its own use!

 [Waiting on Message Ports and Signals at the Same Time](libraries/17-waiting-on-message-ports-and-signals-at-the-same-time.md) 

---

## See Also

- [GetMsg — exec.library](../autodocs/exec.library.md#getmsg)
- [ReplyMsg — exec.library](../autodocs/exec.library.md#replymsg)
- [WaitPort — exec.library](../autodocs/exec.library.md#waitport)
