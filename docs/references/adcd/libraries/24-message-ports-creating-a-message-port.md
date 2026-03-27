---
title: 24 / Message Ports / Creating a Message Port
manual: libraries
chapter: libraries
section: 24-message-ports-creating-a-message-port
functions: [AddPort, CreateMsgPort, RemPort]
libraries: [exec.library]
---

# 24 / Message Ports / Creating a Message Port

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To create a new message port using an operating system release prior to
V36, you must allocate and initialize a [MsgPort](libraries/24-exec-messages-and-ports-message-ports.md) structure. If you want to
make the port public, you will also need to call the [AddPort()](autodocs-2.0/exec-library-addport.md) function.
Don't make a port public when it is not necessary for it to be so.  The
easiest way to create a port is to use the amiga.lib function
[CreatePort](autodocs-2.0/amiga-lib-createport.md)(name,priority).  If NULL is passed for the name, the port will
not be made public. Port structure initialization involves setting up a
[Node](libraries/23-list-structure-node-structure-definition.md) structure, establishing the message arrival action with its
parameters, and initializing the list header.  The following example of
port creation is equivalent to the CreatePort() function as supplied in
amiga.lib:


```c
    struct MsgPort *CreatePort(UBYTE *name, LONG pri)
    {
        LONG sigBit;
        struct MsgPort *mp;

        if ((sigBit = AllocSignal(-1L)) == -1) return(NULL);

        mp = (struct MsgPort *) AllocMem((ULONG)sizeof(struct MsgPort),
                 (ULONG)MEMF_PUBLIC | MEMF_CLEAR);
        if (!mp) {
            FreeSignal(sigBit);
            return(NULL);
        }
        mp->mp_Node.ln_Name = name;
        mp->mp_Node.ln_Pri  = pri;
        mp->mp_Node.ln_Type = NT_MSGPORT;
        mp->mp_Flags        = PA_SIGNAL;
        mp->mp_SigBit       = sigBit;
        mp->mp_SigTask      = (struct Task *)FindTask(0L);
                                                  /* Find THIS task.   */

        if (name) AddPort(mp);
        else NewList(&(mp->mp_MsgList));          /* init message list */

        return(mp);
    }
```
As of V36 the Exec [CreateMsgPort()](autodocs-2.0/exec-library-createmsgport.md) function can be used to create a
message port.  This function allocates and initializes a new message port.
Just like [CreatePort()](autodocs-2.0/amiga-lib-createport.md), a signal bit will be allocated and the port will
be initialized to signal the creating task ([mp_SigTask](libraries/24-exec-messages-and-ports-message-ports.md)) when a message
arrives at this port.  To make the port public after CreateMsgPort(), you
must fill out the [ln_Name](libraries/23-list-structure-node-structure-definition.md) field and call [AddPort()](autodocs-2.0/exec-library-addport.md).  If you do this, you
must remember to [RemPort()](libraries/24-message-ports-deleting-a-message-port.md) the port from the public list in your cleanup.
If you need to create a message port and your application already requires
Release 2 or greater, you can use CreateMsgPort() instead of CreatePort().
The following is an example of the usage of CreateMsgPort().


```c
    struct MsgPort *newmp;
            /* A private message port has been created. CreateMsgPort() */
    if (newmp = CreateMsgPort())
            /* returns NULL if the creation of the message port failed. */
    {
        newmp->mp_Node.ln_Name = "Griffin";
        newmp->mp_Node.ln_Pri  = 0;
                                /* To make it public fill in the fields */
        AddPort(newmp);         /* with appropriate values.             */
    }
```

---

## See Also

- [AddPort — exec.library](../autodocs/exec.library.md#addport)
- [CreateMsgPort — exec.library](../autodocs/exec.library.md#createmsgport)
- [RemPort — exec.library](../autodocs/exec.library.md#remport)
