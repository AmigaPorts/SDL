# printer.device/CMD_START



NAME

```c
    CMD_START -- restart after stop (immediate)
```
FUNCTION

    CMD_START restarts the unit after a stop command.
IO REQUEST

```c
    io_Message      mn_ReplyPort set if quick I/O is not possible
    io_Device       preset by the call to [OpenDevice](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Command      CMD_START
    io_Flags        IOB_QUICK set if quick I/O is possible
```
