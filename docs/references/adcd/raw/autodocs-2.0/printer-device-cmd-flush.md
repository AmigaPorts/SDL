# printer.device/CMD_FLUSH



NAME

```c
    CMD_FLUSH -- abort all I/O requests (immediate)
```
FUNCTION

    CMD_FLUSH aborts all stopped I/O at the unit.
IO REQUEST

```c
    io_Message      mn_ReplyPort set if quick I/O is not possible
    io_Device       preset by the call to [OpenDevice](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Command      CMD_FLUSH
    io_Flags        IOB_QUICK set if quick I/O is possible
```
