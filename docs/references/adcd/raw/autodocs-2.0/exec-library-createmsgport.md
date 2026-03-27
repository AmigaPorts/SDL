# exec.library/CreateMsgPort



NAME

```c
    CreateMsgPort - Allocate and initialize a new message port  (V36)
```
SYNOPSIS

```c
    CreateMsgPort()

    struct [MsgPort](../Includes_and_Autodocs_2._guide/node0099.html#line29) * CreateMsgPort(void);
```
FUNCTION

```c
    Allocates and initializes a new message port.  The message list
    of the new port will be prepared for use (via NewList).  A signal
    bit will be allocated, and the port will be set to signal your
    task when a message arrives (PA_SIGNAL).

    You *must* use [DeleteMsgPort()](../Includes_and_Autodocs_2._guide/node0349.html) to delete ports created with
    CreateMsgPort()!
```
RESULT

```c
    [MsgPort](../Includes_and_Autodocs_2._guide/node0099.html#line29) - A new [MsgPort](../Includes_and_Autodocs_2._guide/node0099.html#line29) structure ready for use, or NULL if out of
            memory or signals.  If you wish to add this port to the public
            port list, fill in the ln_Name and ln_Pri fields, then call
            [AddPort()](../Includes_and_Autodocs_2._guide/node0329.html).  Don't forget RemPort()!
```
SEE ALSO

```c
    [DeleteMsgPort()](../Includes_and_Autodocs_2._guide/node0349.html), [exec/AddPort()](../Includes_and_Autodocs_2._guide/node0329.html), [exec/ports.h](../Includes_and_Autodocs_2._guide/node0099.html), [amiga.lib/CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html)
```
