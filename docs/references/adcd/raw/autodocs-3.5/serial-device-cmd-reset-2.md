# serial.device/CMD_RESET



   NAME

       Reset -- reinitializes the serial port
   FUNCTION

       This command resets the serial port to its freshly initialized
       condition. It aborts all I/O requests both queued and current,
       relinquishes the current buffer, obtains a new default sized
       buffer, and sets the port's flags and parameters to their
       boot-up time default values. The functions places the reset
       parameter values in the ioRequest block.
   IO REQUEST

```c
       io_Message      mn_ReplyPort initialized
       io_Device       set by [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
       io_Unit         set by [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
       io_Command      CMD_RESET
```
   RESULTS

       Error -- if the Reset succeded, then Error will be null.
           If the Reset failed, then the Error will be non-zero.
