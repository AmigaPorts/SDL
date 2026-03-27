# 24 Exec Messages and Ports / Message Ports


Message ports are rendezvous points at which messages are collected. A
port may contain any number of outstanding messages from many different
originators.  When a message arrives at a port, the message is appended to
the end of the list of messages for that port, and a prespecified arrival
action is invoked.  This action may do nothing, or it may cause a
predefined task signal or software interrupt (see the "[Exec Interrupts](../Libraries_Manual_guide/node0302.html)"
chapter).

Like many Exec structures, ports may be given a symbolic name.  Such names
are particularly useful for tasks that must rendezvous with dynamically
created ports.  They are also useful for debugging purposes.

A message port consists of a MsgPort structure as defined in the
<exec/[ports.h](../Includes_and_Autodocs_2._guide/node0099.html#line27)> and <exec/[ports.i](../Includes_and_Autodocs_2._guide/node009D.html#line23)> include files.  The C structure for a
port is as follows:


```c
    struct MsgPort {
        struct Node  mp_Node;
        UBYTE        mp_Flags;
        UBYTE        mp_SigBit;
        void        *mp_SigTask;
        struct List  mp_MsgList;
    };
```
mp_Node

```c
    is a standard [Node](../Libraries_Manual_guide/node02D9.html#line19) structure.  This is useful for tasks that might
    want to rendezvous with a particular message port by name.
```
mp_Flags

    are used to indicate message arrival actions.  See the explanation
    below.
mp_SigBit

    is the signal bit number when a port is used with the task signal
    arrival action.
mp_SigTask

    is a pointer to the task to be signaled.  If a software interrupt
    arrival action is specified, this is a pointer to the interrupt
    structure.
mp_MsgList

```c
    is the list header for all messages queued to this port.  (See the
    "[Exec Lists and Queues](../Libraries_Manual_guide/node02D8.html)" chapter).
```
The mp_Flags field contains a subfield indicated by the PF_ACTION mask.
This sub-field specifies the message arrival action that occurs when a
port receives a new message. The possibilities are as follows:

PA_SIGNAL

    This flag tells Exec to signal the mp_SigTask using signal number
    mp_SigBit on the arrival of a new message.  Every time a message is
    put to the port another signal will occur regardless of how many
    messages have been queued to the port.
PA_SOFTINT

```c
    This flag tells Exec to [Cause()](../Libraries_Manual_guide/node030D.html#line9) a software interrupt when a message
    arrives at the port.  In this case, the mp_SigTask field must contain
    a pointer to a struct Interrupt rather than a Task pointer.  The
    software interrupt will be Caused every time a message is received.
```
PA_IGNORE

    This flag tells Exec to perform no operation other than queuing the
    message.  This action is often used to stop signaling or software
    interrupts without disturbing the contents of the mp_SigTask field.
It is important to realize that a port's arrival action will occur for
each new message queued, and that there is not a one-to-one correspondence
between messages and signals.  Task signals are only single-bit flags so
there is no record of how many times a particular signal occurred.  There
may be many messages queued and only a single task signal; sometimes
however there may be a signal, but no messages.  All of this has certain
implications when designing code that deals with these actions.  Your code
should not depend on receiving a signal for every message at your port.
All of this is also true for software interrupts.

 [Creating a Message Port](../Libraries_Manual_guide/node02EC.html)    [How To Rendezvous at a Message Port](../Libraries_Manual_guide/node02EE.html) 
 [Deleting a Message Port](../Libraries_Manual_guide/node02ED.html) 

