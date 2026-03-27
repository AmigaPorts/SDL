# dos.library/SendPkt



NAME

```c
    SendPkt -- Sends a packet to a handler (V36)
```
SYNOPSIS

```c
    SendPkt(packet, port, replyport)
             D1     D2      D3

    void SendPkt(struct [DosPacket](../Includes_and_Autodocs_2._guide/node0078.html#line109) *,struct [MsgPort](../Includes_and_Autodocs_2._guide/node0099.html#line29) *,struct [MsgPort](../Includes_and_Autodocs_2._guide/node0099.html#line29) *)
```
FUNCTION

```c
    Sends a packet to a handler and does not wait.  All fields in the
    packet must be initialized before calling this routine.  The packet
    will be returned to replyport.  If you wish to use this with
    [WaitPkt()](../Includes_and_Autodocs_2._guide/node030F.html), use the address or your pr_MsgPort for replyport.
```
INPUTS

```c
    packet - packet to send, must be initialized and have a message.
    port   - pr_MsgPort of handler process to send to.
    replyport - [MsgPort](../Includes_and_Autodocs_2._guide/node0099.html#line29) for the packet to come back to.
```
NOTES

    Callable from a task.
SEE ALSO

```c
    [DoPkt()](../Includes_and_Autodocs_2._guide/node0296.html), [WaitPkt()](../Includes_and_Autodocs_2._guide/node030F.html), [AllocDosObject()](../Includes_and_Autodocs_2._guide/node027F.html), [FreeDosObject()](../Includes_and_Autodocs_2._guide/node02B2.html), [AbortPkt()](../Includes_and_Autodocs_2._guide/node027A.html)
```
