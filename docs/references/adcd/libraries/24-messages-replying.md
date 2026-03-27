---
title: 24 / Messages / Replying
manual: libraries
chapter: libraries
section: 24-messages-replying
functions: [ReplyMsg]
libraries: [exec.library]
---

# 24 / Messages / Replying

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When the operations associated with receiving a new message are finished,
it is usually necessary to send the message back to the originator.  The
receiver replies the message by returning it to the originator using the
[ReplyMsg()](autodocs-2.0/exec-library-replymsg.md) function.  This is important because it notifies the originator
that the message can be reused or deallocated. The ReplyMsg() function
serves this purpose.  It returns the message to the port specified in the
[mn_ReplyPort](libraries/24-exec-messages-and-ports-messages.md) field of the message.  If this field is zero, no reply is
returned.

The [previous example](libraries/24-messages-getting-a-message.md) can be enhanced to reply to each of its messages:


```c
    while (xymsg = GetMsg(xyport)) {
        printf("x=%ld y=%ld\n", xymsg->xy_X, xymsg->xy_Y);
        ReplyMsg(xymsg);
    }
```
Notice that the reply does not occur until after the message values have
been used.

Often the operations associated with receiving a message involve returning
results to the originator.  Typically this is done within the message
itself.  The receiver places the results in fields defined (or perhaps
reused) within the message body before replying the message back to the
originator.  Receipt of the replied message at the originator's reply port
indicates it is once again safe for the originator to use or change the
values found within the message.

The following are two short example tasks that communicate by sending,
waiting for and replying to messages.  Run these two programs together.


```c
     [Port1.c](libraries/lib-examples-port1-c.md)    [Port2.c](libraries/lib-examples-port2-c.md) 
```

---

## See Also

- [ReplyMsg — exec.library](../autodocs/exec.library.md#replymsg)
