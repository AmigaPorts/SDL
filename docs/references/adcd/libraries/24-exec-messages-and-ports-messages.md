---
title: 24 Exec Messages and Ports / Messages
manual: libraries
chapter: libraries
section: 24-exec-messages-and-ports-messages
functions: []
libraries: []
---

# 24 Exec Messages and Ports / Messages

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

As mentioned earlier, a message contains both system header information
and the actual message content.  The system header is of the Message form
defined in <exec/[ports.h](autodocs-2.0/includes-exec-ports-h.md)> and <exec/[ports.i](autodocs-2.0/includes-exec-ports-i.md)>.  In C this structure is as
follows:


```c
    struct Message {
        struct Node     mn_Node;
        struct MsgPort *mn_ReplyPort;
        UWORD           mn_Length;
    };
```
mn_Node

```c
    is a standard [Node](libraries/23-list-structure-node-structure-definition.md) structure used for port linkage.
```
mn_ReplyPort

    is used to indicate a port to which this message will be returned
    when a reply is necessary.
mn_Length

    indicates the total length of the message, including the Message
    structure itself.
This structure is always attached to the head of all messages.  For
example, if you want a message structure that contains the x and y
coordinates of a point on the screen, you could define it as follows:


```c
    struct XYMessage {
        struct Message xy_Msg;
        UWORD          xy_X;
        UWORD          xy_Y;
    }
```
For this structure, the mn_Length field should be set to sizeof(struct
XYMessage).

 [Putting a Message](libraries/24-messages-putting-a-message.md)        [Getting a Message](libraries/24-messages-getting-a-message.md) 
 [Waiting For a Message](libraries/24-messages-waiting-for-a-message.md)    [Replying](libraries/24-messages-replying.md) 

