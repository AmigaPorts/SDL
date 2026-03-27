# 24 / Message Ports / Deleting a Message Port


Before a message port is deleted, all outstanding messages from other
tasks must be returned.  This is done by getting and replying to all
messages at the port until message queue is empty.  Of course, there is no
need to reply to messages owned by the current task (the task performing
the port deletion).  Public ports attached to the system with [AddPort()](../Libraries_Manual_guide/node02EC.html)
must be removed from the system with [RemPort()](../Includes_and_Autodocs_2._guide/node0374.html) before deallocation.  This
amiga.lib functions [CreatePort()](../Libraries_Manual_guide/node02EC.html) and [DeletePort()](../Includes_and_Autodocs_2._guide/node0153.html) handle this
automatically.

The following example of port deletion is equivalent to the [DeletePort()](../Includes_and_Autodocs_2._guide/node0153.html)
function as supplied in amiga.lib.  Note that DeletePort() must only be
used on ports created with [CreatePort()](../Libraries_Manual_guide/node02EC.html).


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
To delete ports created with [CreateMsgPort()](../Libraries_Manual_guide/node02EC.html#line39), [DeleteMsgPort()](../Includes_and_Autodocs_2._guide/node0349.html) must be
used.  Note that these functions are only available in V36 and higher.  If
the port was made public with [AddPort()](../Libraries_Manual_guide/node02EC.html), [RemPort()](../Includes_and_Autodocs_2._guide/node0374.html) must be used first, to
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
