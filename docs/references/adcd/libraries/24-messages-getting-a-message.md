---
title: 24 / Messages / Getting a Message
manual: libraries
chapter: libraries
section: 24-messages-getting-a-message
functions: [GetMsg]
libraries: [exec.library]
---

# 24 / Messages / Getting a Message

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Messages are usually removed from ports with the [GetMsg()](autodocs-2.0/exec-library-getmsg.md) function.  This
function removes the next message at the head of the port queue and
returns a pointer to it.  If there are no messages in a port, this
function returns a zero.

The example below illustrates the use of [GetMsg()](autodocs-2.0/exec-library-getmsg.md) to print the contents of
all messages in a port:


```c
    while (xymsg = GetMsg(xyport)) printf("x=%ld y=%ld\n", xymsg->xy_X,
                                           xymsg->xy_Y);
```
Certain messages may be more important than others.  Because ports impose
FIFO ordering, these important messages may get queued behind other
messages regardless of their priority.  If it is necessary to recognize
more important messages, it is easiest to create another port for these
special messages.

---

## See Also

- [GetMsg — exec.library](../autodocs/exec.library.md#getmsg)
