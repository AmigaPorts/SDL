# parallel.device/CMD_FLUSH



NAME

    Flush -- clear all queued I/O requests for the parallel port
FUNCTION

    This command purges the read and write request queues for the
    parallel device. The currently active request is not purged.
IO REQUEST

```c
    io_Message      mn_ReplyPort initialized
    io_Device       set by [OpenDevice](../Includes_and_Autodocs_2._guide/node04F2.html)
    io_Unit         set by [OpenDevice](../Includes_and_Autodocs_2._guide/node04F2.html)
    io_Command      CMD_FLUSH (08)
```
