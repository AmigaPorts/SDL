# 12 / Device Interface / Closing The Serial Device


Each [OpenDevice()](../Includes_and_Autodocs_2._guide/node04D4.html) must eventually be matched by a call to [CloseDevice()](../Includes_and_Autodocs_2._guide/node04CC.html).
When the last close is performed, the device will deallocate all resources
and buffers.

All IORequests must be complete before [CloseDevice()](../Includes_and_Autodocs_2._guide/node04CC.html).  Abort any pending
requests with [AbortIO()](../Includes_and_Autodocs_2._guide/node04CA.html).

   if (!(CheckIO(SerialIO)))
```c
       {
       AbortIO((struct IORequest *)SerialIO); /* Ask device to abort */
       }			              /*   request, if pending */
```
   WaitIO((struct IORequest *)SerialIO);      /* Wait for abort, then */
   CloseDevice((struct IORequest *)SerialIO); /*  clean up */

