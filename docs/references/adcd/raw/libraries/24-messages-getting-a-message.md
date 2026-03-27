# 24 / Messages / Getting a Message


Messages are usually removed from ports with the [GetMsg()](../Includes_and_Autodocs_2._guide/node035A.html) function.  This
function removes the next message at the head of the port queue and
returns a pointer to it.  If there are no messages in a port, this
function returns a zero.

The example below illustrates the use of [GetMsg()](../Includes_and_Autodocs_2._guide/node035A.html) to print the contents of
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

