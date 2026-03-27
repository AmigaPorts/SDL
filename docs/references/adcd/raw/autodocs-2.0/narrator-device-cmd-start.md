# narrator.device/CMD_START



NAME

```c
    CMD_START - Restarts the device after a [CMD_STOP](../Includes_and_Autodocs_2._guide/node04C6.html) command
```
SYNOPSIS

    Standard device command.
FUNCTION

```c
    CMD_START restarts the currently active speech (if any) and
    allows queued requests to start.
```
INPUTS

```c
    Valid [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) block with the io_Command field set to CMD_START
    A valid [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) block is one with its io_Message structure, and
    io_Device and io_Unit fields properly initialized.  The easiest
    way to insure proper initialization is to make a copy of the
    [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) block after a successful [OpenDevice](../Includes_and_Autodocs_2._guide/node04C8.html) call.
```
RESULTS

    io_Error set to 0.
SEE ALSO

    Exec input/output documentation.
