# 12 Serial Device / Error Codes from the Serial Device


The serial device returns error codes whenever an operation is attempted.

   SerialIO->IOSer.io_Command  = SDCMD_SETPARAMS; /* Set parameters */
   if (DoIO((struct IORequest *)SerialIO))

```c
       printf("Set Params failed. Error: %ld ",SerialIO->IOSer.io_Error);
```
The error is returned in the io_Error field of the [IOExtSer](../Devices_Manual_guide/node009C.html#line7) structure.


```c
                    SERIAL DEVICE ERROR CODES

    Error                   Value    Explanation
    -----                   -----    ----------
    SerErr_DevBusy          1        Device in use
    SerErr_BaudMismatch     2        Baud rate not supported by hardware
    SerErr_BufErr           4        Failed to allocate new read buffer
    SerErr_InvParam         5        Bad parameter
    SerErr_LineErr          6        Hardware data overrun
    SerErr_ParityErr        9        Parity error
    SerErr_TimerErr         11       Timeout (if using 7-wire handshaking)
    SerErr_BufOverflow      12       Read buffer overflowed
    SerErr_NoDSR            13       No Data Set Ready
    SerErr_DetectedBreak    15       Break detected
    SerErr_UnitBusy         16       Selected unit already in use
```
