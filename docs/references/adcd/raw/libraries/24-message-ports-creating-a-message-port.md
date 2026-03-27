# 24 / Message Ports / Creating a Message Port


To create a new message port using an operating system release prior to
V36, you must allocate and initialize a [MsgPort](../Libraries_Manual_guide/node02EB.html#line12) structure. If you want to
make the port public, you will also need to call the [AddPort()](../Includes_and_Autodocs_2._guide/node0329.html) function.
Don't make a port public when it is not necessary for it to be so.  The
easiest way to create a port is to use the amiga.lib function
[CreatePort](../Includes_and_Autodocs_2._guide/node0148.html)(name,priority).  If NULL is passed for the name, the port will
not be made public. Port structure initialization involves setting up a
[Node](../Libraries_Manual_guide/node02D9.html#line19) structure, establishing the message arrival action with its
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
As of V36 the Exec [CreateMsgPort()](../Includes_and_Autodocs_2._guide/node0345.html) function can be used to create a
message port.  This function allocates and initializes a new message port.
Just like [CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html), a signal bit will be allocated and the port will
be initialized to signal the creating task ([mp_SigTask](../Libraries_Manual_guide/node02EB.html#line36)) when a message
arrives at this port.  To make the port public after CreateMsgPort(), you
must fill out the [ln_Name](../Libraries_Manual_guide/node02D9.html#line38) field and call [AddPort()](../Includes_and_Autodocs_2._guide/node0329.html).  If you do this, you
must remember to [RemPort()](../Libraries_Manual_guide/node02ED.html) the port from the public list in your cleanup.
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
