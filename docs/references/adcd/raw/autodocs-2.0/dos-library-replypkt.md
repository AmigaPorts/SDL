# dos.library/ReplyPkt



NAME

```c
    ReplyPkt -- replies a packet to the person who sent it to you (V36)
```
SYNOPSIS

```c
    ReplyPkt(packet, result1, result2)
               D1      D2       D3

    void ReplyPkt(struct [DosPacket](../Includes_and_Autodocs_2._guide/node0078.html#line109) *, LONG, LONG)
```
FUNCTION

```c
    This returns a packet to the process which sent it to you.  In
    addition, puts your pr_MsgPort address in dp_Port, so using ReplyPkt()
    again will send the message to you.  (This is used in "ping-ponging"
    packets between two processes).  It uses result 1 & 2 to set the
    dp_Res1 and dp_Res2 fields of the packet.
```
INPUTS

    packet  - packet to reply, assumed to set up correctly.
    result1 - first result
    result2 - secondary result
SEE ALSO

```c
    [DoPkt()](../Includes_and_Autodocs_2._guide/node0296.html), [SendPkt()](../Includes_and_Autodocs_2._guide/node02F0.html), [WaitPkt()](../Includes_and_Autodocs_2._guide/node030F.html), [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html)
```
