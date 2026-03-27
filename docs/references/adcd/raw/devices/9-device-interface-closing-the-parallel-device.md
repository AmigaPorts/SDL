# 9 / Device Interface / Closing The Parallel Device


Each [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html) must eventually be matched by a call to [CloseDevice()](../Includes_and_Autodocs_2._guide/node033F.html).
When the last close is performed, the device will deallocate all resources
and buffers.  The latest parameter settings will be saved for the next
open.

All I/O requests must be complete before [CloseDevice()](../Includes_and_Autodocs_2._guide/node033F.html).  If any requests
are still pending, abort them with AbortIO():

   if (!(CheckIO(ParallelIO)))
```c
       {
       AbortIO(ParallelIO);  /* Ask device to abort request, if pending */
       }
```
   WaitIO(ParallelIO);       /* Wait for abort, then clean up */
   CloseDevice((struct IORequest *)ParallelIO);

