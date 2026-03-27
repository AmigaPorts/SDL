---
title: 24 / Message Ports / Deleting a Message Port
manual: libraries
chapter: libraries
section: 24-message-ports-deleting-a-message-port
functions: [AddPort, CreateMsgPort, DeleteMsgPort, RemPort]
libraries: [exec.library]
---

# 24 / Message Ports / Deleting a Message Port

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Before a message port is deleted, all outstanding messages from other
tasks must be returned.  This is done by getting and replying to all
messages at the port until message queue is empty.  Of course, there is no
need to reply to messages owned by the current task (the task performing
the port deletion).  Public ports attached to the system with [AddPort()](libraries/24-message-ports-creating-a-message-port.md)
must be removed from the system with [RemPort()](autodocs-2.0/exec-library-remport.md) before deallocation.  This
amiga.lib functions [CreatePort()](libraries/24-message-ports-creating-a-message-port.md) and [DeletePort()](autodocs-2.0/amiga-lib-deleteport.md) handle this
automatically.

The following example of port deletion is equivalent to the [DeletePort()](autodocs-2.0/amiga-lib-deleteport.md)
function as supplied in amiga.lib.  Note that DeletePort() must only be
used on ports created with [CreatePort()](libraries/24-message-ports-creating-a-message-port.md).


```c
    void DeletePort(mp)
    struct MsgPort *mp;
    {
        if ( mp->mp_Node.ln_Name ) RemPort(mp);  /* if it was public... */

        mp->mp_SigTask         = (struct Task *) -1;
                                /* Make it difficult to re-use the port */
        mp->mp_MsgList.lh_Head = (struct Node *) -1;

        FreeSignal( mp->mp_SigBit );
        FreeMem( mp, (ULONG)sizeof(struct MsgPort) );
    }
```
To delete ports created with [CreateMsgPort()](libraries/24-message-ports-creating-a-message-port.md), [DeleteMsgPort()](autodocs-2.0/exec-library-deletemsgport.md) must be
used.  Note that these functions are only available in V36 and higher.  If
the port was made public with [AddPort()](libraries/24-message-ports-creating-a-message-port.md), [RemPort()](autodocs-2.0/exec-library-remport.md) must be used first, to
remove the port from the system.  Again, make sure all outstanding
messages are replied to, so that the message queue is empty.


```c
    struct MsgPort *newmp;

    if (newmp)
    {
        if ( newmp->mp_Node.ln_Name ) RemPort(newmp);
                                /* if it was public... */
        DeleteMsgPort(newmp);
    }
```

---

## See Also

- [AddPort — exec.library](../autodocs/exec.library.md#addport)
- [CreateMsgPort — exec.library](../autodocs/exec.library.md#createmsgport)
- [DeleteMsgPort — exec.library](../autodocs/exec.library.md#deletemsgport)
- [RemPort — exec.library](../autodocs/exec.library.md#remport)
