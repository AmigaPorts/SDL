# 11 / Device Interface / Closing The SCSI Device


Each [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html) must eventually be matched by a call to [CloseDevice()](../Includes_and_Autodocs_2._guide/node033F.html).
All I/O requests must be complete before calling [CloseDevice()](../Includes_and_Autodocs_2._guide/node033F.html).  If any
requests are still pending, abort them with [AbortIO()](../Includes_and_Autodocs_2._guide/node0323.html).


```c
    if (!(CheckIO(SCSIIO)))
        {
        AbortIO(SCSIIO);   /* Ask device to abort any pending requests */
        WaitIO(SCSIIO);    /* Wait for abort, then clean up */
        }
    CloseDevice(SCSIIO);   /* Close SCSI device */
```
