# serial.device/CMD_FLUSH



NAME

    Flush -- clear all queued I/O requests for the serial port
FUNCTION

    This command purges the read and write request queues for the
    serial device. Flush will not affect active requests.
IO REQUEST

```c
    io_Message      mn_ReplyPort initialized
    io_Device       set by [OpenDevice](../Includes_and_Autodocs_2._guide/node04D4.html)
    io_Unit         set by [OpenDevice](../Includes_and_Autodocs_2._guide/node04D4.html)
    io_Command      CMD_FLUSH
```
RESULTS

    Error -- if the Flush succeded, then io_Error will be null.
             If the Flush failed, then the io_Error will be non-zero.
