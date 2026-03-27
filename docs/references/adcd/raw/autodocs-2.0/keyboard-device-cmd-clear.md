# keyboard.device/CMD_CLEAR



NAME

    CMD_CLEAR -- Clear the keyboard input buffer.
FUNCTION

    Remove from the input buffer any keys transitions waiting to
    satisfy read requests.
IO REQUEST

```c
    io_Message      mn_ReplyPort set if quick I/O is not possible
    io_Device       preset by the call to [OpenDevice](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Command      CMD_CLEAR
    io_Flags        IOB_QUICK set if quick I/O is possible
```
