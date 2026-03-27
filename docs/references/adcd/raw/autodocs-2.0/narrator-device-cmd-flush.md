# narrator.device/CMD_FLUSH



NAME

    CMD_FLUSH - Aborts all inprogress and queued requests
SYNOPSIS

    Standard device command.
FUNCTION

    Aborts all inprogress and queued speech requests.
INPUTS

```c
    Valid [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) block with the io_Command field set to CMD_FLUSH.
    A valid [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) block is one with its io_Message structure, and
    io_Device and io_Unit fields properly initialized.  The easiest
    way to insure proper initialization is to make a copy of the
    [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) block after a successful [OpenDevice](../Includes_and_Autodocs_2._guide/node04C8.html) call.
```
RESULTS

```c
    io_Error in [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) block set to 0
```
SEE ALSO

    Exec input/output documentation.
