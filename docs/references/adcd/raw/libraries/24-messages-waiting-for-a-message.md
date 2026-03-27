# 24 / Messages / Waiting For a Message


A task may go to sleep waiting for a message to arrive at one or more
ports.  This technique is widely used on the Amiga as a general form of
event notification.  For example, it is used extensively by tasks for I/O
request completion.

The [MsgPort.mp_SigTask](../Libraries_Manual_guide/node02EB.html#line36) field contains the address of the task to be
signaled and [mp_SigBit](../Libraries_Manual_guide/node02EB.html#line32) contains a preallocated signal number (as described
in the "[Exec Tasks](../Libraries_Manual_guide/node02BA.html)" chapter).

You can call the [WaitPort()](../Includes_and_Autodocs_2._guide/node038C.html) function to wait for a message to arrive at a
port.  This function will return the first message (it may not be the
only) queued to a port.  Note that your application must still call
[GetMsg()](../Libraries_Manual_guide/node02F2.html) to remove the message from the port.  If the port is empty, your
task will go to sleep waiting for the first message.  If the port is not
empty, your task will not go to sleep.  It is possible to receive a signal
for a port without a message being present yet.  The code processing the
messages should be able to handle this.  The following code illustrates
WaitPort().


```c
    struct XYMessage *xy_msg;
    struct MsgPort   *xyport;

    xyport = CreatePort("xyport", 0);
    if (xyport == 0)
    {
        printf("Couldn't create xyport\n");
        exit(31);
    }

    xy_msg = WaitPort(xyport);     /* go to sleep until message arrives */
```
A more general form of waiting for a message involves the use of the
[Wait()](../Libraries_Manual_guide/node02D4.html) function (see the "[Exec Signals](../Libraries_Manual_guide/node02D4.html)" chapter).  This function waits for
task event signals directly.  If the signal assigned to the message port
occurs, the task will awaken.  Using the Wait() function is more general
because you can wait for more than one signal.  By combining the signal
bits from each port into one mask for the Wait() function, a loop can be
set up to process all messages at all ports.

Here's an example using [Wait()](../Libraries_Manual_guide/node02D4.html):


```c
    struct XYMessage *xy_msg;
    struct MsgPort   *xyport;
    ULONG usersig, portsig;
    BOOL ABORT = FALSE;

    if (xyport = CreatePort("xyport", 0))
    {
        portsig = 1 << xyport->mp_SigBit;
        usersig = SIGBREAKF_CTRL_C;     /* User can break with CTRL-C.  */
        for (;;)
        {
            signal = Wait(portsig | usersig);
                                        /* Sleep till someone signals.  */

            if (signal & portsig)       /* Got a signal at the msgport. */
            {   .  .  .
            }
            if (signal & usersig)       /* Got a signal from the user.  */
            {
                ABORT = TRUE;           /* Time to clean up.            */
                 . . .
            }
            if (ABORT) break;
        }
        DeletePort(xyport);
    }
    else printf("Couldn't create xyport\n");


    WaitPort() Does Not Remove A Message.
    -------------------------------------
    [WaitPort()](../Includes_and_Autodocs_2._guide/node038C.html) only returns a pointer to the first message in a port.
    It does not actually remove the message from the port queue.
```
