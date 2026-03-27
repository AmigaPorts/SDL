# parallel.device/CMD_START



NAME

    Start -- restart paused I/O over the parallel port
FUNCTION

    This command restarts the current I/O activity on the parallel
    port by reactivating the handshaking sequence.
IO REQUEST

```c
    io_Message      mn_ReplyPort initialized
    io_Device       set by [OpenDevice](../Includes_and_Autodocs_2._guide/node04F2.html)
    io_Unit         set by [OpenDevice](../Includes_and_Autodocs_2._guide/node04F2.html)
    io_Command      CMD_START (07)
```
SEE ALSO

```c
    [parallel.device/CMD_STOP](../Includes_and_Autodocs_2._guide/node04F0.html)
```
