# 24 Exec Messages and Ports / Messages


As mentioned earlier, a message contains both system header information
and the actual message content.  The system header is of the Message form
defined in <exec/[ports.h](../Includes_and_Autodocs_2._guide/node0099.html#line46)> and <exec/[ports.i](../Includes_and_Autodocs_2._guide/node009D.html#line48)>.  In C this structure is as
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
    is a standard [Node](../Libraries_Manual_guide/node02D9.html#line19) structure used for port linkage.
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

 [Putting a Message](../Libraries_Manual_guide/node02F0.html)        [Getting a Message](../Libraries_Manual_guide/node02F2.html) 
 [Waiting For a Message](../Libraries_Manual_guide/node02F1.html)    [Replying](../Libraries_Manual_guide/node02F3.html) 

