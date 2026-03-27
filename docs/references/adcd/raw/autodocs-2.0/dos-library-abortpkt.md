# dos.library/AbortPkt



NAME

```c
    AbortPkt -- Aborts an asynchronous packet, if possible. (V36)
```
SYNOPSIS

```c
    AbortPkt(port, pkt)
              D1    D2

    void AbortPkt(struct [MsgPort](../Includes_and_Autodocs_2._guide/node0099.html#line29) *, struct [DosPacket](../Includes_and_Autodocs_2._guide/node0078.html#line109) *)
```
FUNCTION

```c
    This attempts to abort a packet sent earlier with [SendPkt](../Includes_and_Autodocs_2._guide/node02F0.html) to a
    handler.  There is no guarantee that any given handler will allow
    a packet to be aborted, or if it is aborted whether function
    requested completed first or completely.  After calling AbortPkt(),
    you must wait for the packet to return before reusing it or
    deallocating it.
```
INPUTS

    port - port the packet was sent to
    pkt  - the packet you wish aborted
BUGS

    As of V37, this function does nothing.
SEE ALSO

```c
    [SendPkt()](../Includes_and_Autodocs_2._guide/node02F0.html), [DoPkt()](../Includes_and_Autodocs_2._guide/node0296.html), [WaitPkt()](../Includes_and_Autodocs_2._guide/node030F.html)
```
