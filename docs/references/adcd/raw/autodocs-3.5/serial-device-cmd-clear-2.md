# serial.device/CMD_CLEAR



   NAME

       Clear -- clear the serial port buffers
   FUNCTION

       This command resets the serial port's read buffer pointers.
   IO REQUEST

```c
       io_Message      mn_ReplyPort initialized
       io_Device       set by [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
       io_Unit         set by [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
       io_Command      CMD_CLEAR
```
   RESULTS

       Error -- If the Clear succeded, then io_Error will be null.
                If the Clear failed, then the io_Error will be non-zero.
