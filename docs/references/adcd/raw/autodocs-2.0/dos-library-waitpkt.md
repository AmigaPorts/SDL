# dos.library/WaitPkt



NAME

```c
    WaitPkt -- Waits for a packet to arrive at your pr_MsgPort (V36)
```
SYNOPSIS

```c
    packet = WaitPkt()
    D0

    struct [DosPacket](../Includes_and_Autodocs_2._guide/node0078.html#line109) *WaitPkt(void);
```
FUNCTION

```c
    Waits for a packet to arrive at your pr_MsgPort.  If anyone has
    installed a packet wait function in pr_PktWait, it will be called.
    The message will be automatically GetMsg()ed so that it is no longer
    on the port.  It assumes the message is a dos packet.  It is NOT
    guaranteed to clear the signal for the port.
```
RESULT

```c
    packet - the packet that arrived at the port (from ln_Name of message).
```
SEE ALSO

```c
    [SendPkt()](../Includes_and_Autodocs_2._guide/node02F0.html), [DoPkt()](../Includes_and_Autodocs_2._guide/node0296.html), [AbortPkt()](../Includes_and_Autodocs_2._guide/node027A.html)
```
