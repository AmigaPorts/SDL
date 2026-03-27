# exec.library/WaitPort



NAME

    WaitPort -- wait for a given port to be non-empty
SYNOPSIS

```c
    message = WaitPort(port)
    D0                 A0

    struct [Message](../Includes_and_Autodocs_2._guide/node0099.html#line48) *WaitPort(struct [MsgPort](../Includes_and_Autodocs_2._guide/node0099.html#line29) *);
```
FUNCTION

```c
    This function waits for the given port to become non-empty.  If
    necessary, the [Wait()](../Includes_and_Autodocs_2._guide/node038A.html) function will be called to wait for the port
    signal.  If a message is already present at the port, this function
    will return immediately.  The return value is always a pointer to
    the first message queued (but it is not removed from the queue).
```
CAUTION

```c
    More than one message may be at the port when this returns.  It is
    proper to call the [GetMsg()](../Includes_and_Autodocs_2._guide/node035A.html) function in a loop until all messages
    have been handled, then wait for more to arrive.

    To wait for more than one port, combine the signal bits from each
    port into one call to the [Wait()](../Includes_and_Autodocs_2._guide/node038A.html) function, then use a [GetMsg()](../Includes_and_Autodocs_2._guide/node035A.html) loop
    to collect any and all messages.  It is possible to get a signal
    for a port WITHOUT a message showing up.  Plan for this.
```
INPUT

    port - a pointer to the message port
RETURN

    message - a pointer to the first available message
SEE ALSO

```c
    [GetMsg](../Includes_and_Autodocs_2._guide/node035A.html)
```
