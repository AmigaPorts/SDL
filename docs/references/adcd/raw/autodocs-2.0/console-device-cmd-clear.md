# console.device/CMD_CLEAR



NAME

    CMD_CLEAR -- Clear console input buffer.
FUNCTION

    Remove from the console input buffer any reports waiting to
    satisfy read requests.
IO REQUEST INPUT

```c
    io_Message      mn_ReplyPort set if quick I/O is not possible
    io_Device       preset by the call to [OpenDevice](../Includes_and_Autodocs_2._guide/node0509.html)
    io_Unit         preset by the call to [OpenDevice](../Includes_and_Autodocs_2._guide/node0509.html)
    io_Command      CMD_CLEAR
    io_Flags        IOB_QUICK set if quick I/O is possible, else 0
```
SEE ALSO

```c
    [exec/io.h](../Includes_and_Autodocs_2._guide/node0094.html), [devices/console.h](../Includes_and_Autodocs_2._guide/node0050.html)
```
