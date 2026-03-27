# serial.device/CMD_STOP



NAME

    Stop -- pause all current I/O over the serial port
FUNCTION

    This command halts all current I/O on the serial port by
    sending an xOFF to the "other side", and submitting a "logical
    xOFF" to "our side", if/when appropriate to current activity.
IO REQUEST

```c
    io_Message      mn_ReplyPort initialized
    io_Device       set by [OpenDevice](../Includes_and_Autodocs_2._guide/node04D4.html)
    io_Unit         set by [OpenDevice](../Includes_and_Autodocs_2._guide/node04D4.html)
    io_Command      CMD_STOP
```
RESULTS

SEE ALSO

```c
    [serial.device/CMD_START](../Includes_and_Autodocs_2._guide/node04D1.html)
```
