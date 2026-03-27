# serial.device/CMD_START



   NAME

       Start -- restart paused I/O over the serial port
   FUNCTION

       This function restarts all current I/O on the serial port by
       sending an xON to the "other side", and submitting a "logical
       xON" to "our side", if/when appropriate to current activity.
   IO REQUEST

```c
       io_Message      mn_ReplyPort initialized
       io_Device       set by [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
       io_Unit         set by [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
       io_Command      CMD_START
```
   RESULTS

   SEE ALSO

```c
       [serial.device/CMD_STOP](../Includes_and_Autodocs_3._guide/node055E.html)
```
