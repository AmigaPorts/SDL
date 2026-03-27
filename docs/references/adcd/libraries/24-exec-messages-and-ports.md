---
title: 24 Exec Messages and Ports
manual: libraries
chapter: libraries
section: 24-exec-messages-and-ports
functions: [ReplyMsg]
libraries: [exec.library]
---

# 24 Exec Messages and Ports

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

For interprocess communication, Exec provides a consistent,
high-performance mechanism of messages and ports.  This mechanism is used
to pass message structures of arbitrary sizes from task to task, interrupt
to task, or task to software interrupt.  In addition, messages are often
used to coordinate operations between cooperating tasks.  This chapter
describes many of the details of using messages and ports that the casual
Amiga programmer won't need.  See the "[Introduction to Exec](libraries/17-introduction-to-exec-interprocess-communications.md)" chapter of
this manual for a general introduction to using messages and ports.

A message data structure has two parts: system linkage and message body.
The system linkage is used by Exec to attach a given message to its
destination.  The message body contains the actual data of interest.  The
message body is any arbitrary data up to 64K bytes in size.  The message
body data can include pointers to other data blocks of any size.

Messages are always sent to a predetermined destination port. At a port,
incoming messages are queued in a first-in-first-out (FIFO) order.  There
are no system restrictions on the number of ports or the number of
messages that may be queued to a port (other than the amount of available
system memory).

Messages are always queued by reference, i.e., by a pointer to the
message.  For performance reasons message copying is not performed.  In
essence, a message between two tasks is a temporary license for the
receiving task to use a portion of the memory space of the sending task;
that portion being the message itself.  This means that if task A sends a
message to task B, the message is still part of the task A context.  Task
A, however, should not access the message until it has been replied; that
is, until task B has sent the message back, using the [ReplyMsg()](libraries/24-messages-replying.md) function.
This technique of message exchange imposes important restrictions on
message access.

 [Message Ports](libraries/24-exec-messages-and-ports-message-ports.md)    [Messages](libraries/24-exec-messages-and-ports-messages.md)    [Function Reference](libraries/24-exec-messages-and-ports-function-reference.md) 

---

## See Also

- [ReplyMsg — exec.library](../autodocs/exec.library.md#replymsg)
