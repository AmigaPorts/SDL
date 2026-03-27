# serial.device/SDCMD_BREAK



   NAME

       Break -- send a break signal over the serial line
   FUNCTION
```c
       This command sends a break signal (serial line held low for an
       extended period) out the serial port. For the built-in port,
       This is accomplished by setting the UARTBRK bit of regisrer ADKCON.

       After a duration (user specifiable via setparams, default 250000
       microseconds) the bit is reset and the signal discontinued.
       If the QUEUEDBRK bit of io_SerFlags is set in the io_Request
       block, the request is placed at the back of the write-request
       queue and executed in turn. If the QUEUEDBRK bit is not set,
       the break is started immediately, control returns to the
       caller, and the timer discontinues the signal after the
       duration is completed. Be aware that calling BREAK may
```
	affect other commands such as ABORT, FLUSH, STOP, START, etc...

   IO REQUEST

```c
       io_Message      mn_ReplyPort initialized
       io_Device       set by [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
       io_Unit         set by [OpenDevice](../Includes_and_Autodocs_3._guide/node0560.html)
       io_Command      SDCMD_BREAK
       io_Flags        set/reset IO_QUICK per above description
```
   RESULTS

       Error -- if the Break succeded, then Error will be null.
           If the Break failed, then the Error will be non-zero.
