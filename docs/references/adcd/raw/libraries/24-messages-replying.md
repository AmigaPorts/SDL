# 24 / Messages / Replying


When the operations associated with receiving a new message are finished,
it is usually necessary to send the message back to the originator.  The
receiver replies the message by returning it to the originator using the
[ReplyMsg()](../Includes_and_Autodocs_2._guide/node0379.html) function.  This is important because it notifies the originator
that the message can be reused or deallocated. The ReplyMsg() function
serves this purpose.  It returns the message to the port specified in the
[mn_ReplyPort](../Libraries_Manual_guide/node02EF.html#line14) field of the message.  If this field is zero, no reply is
returned.

The [previous example](../Libraries_Manual_guide/node02F2.html#line5) can be enhanced to reply to each of its messages:


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
     [Port1.c](../Libraries_Manual_guide/node05E8.html)    [Port2.c](../Libraries_Manual_guide/node05E7.html) 
```
