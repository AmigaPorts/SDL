# narrator.device/CMD_RESET



NAME

    CMD_RESET - Reset the device to a known state
SYNOPSIS

    Standard device command.
FUNCTION

    Resets the device as though it has just be initialized.
    Aborts all read/write requests whether active of enqueued.
    Restarts device if it has been stopped.
INPUTS

```c
    Valid [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) block with the io_Command field set to CMD_RESET.
    A valid [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) block is one with its io_Message structure, and
    io_Device and io_Unit fields properly initialized.  The easiest
    way to insure proper initialization is to make a copy of the
    [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) block after a successful [OpenDevice](../Includes_and_Autodocs_2._guide/node04C8.html) call.
```
RESULTS

SEE ALSO

    Exec input/output documentation.
