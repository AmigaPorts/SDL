# 6 / Device Interface / Closing The Input Device


Each [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html) must eventually be matched by a call to [CloseDevice()](../Includes_and_Autodocs_2._guide/node033F.html).
All I/O requests must be complete before CloseDevice().  If any requests
are still pending, abort them with [AbortIO()](../Includes_and_Autodocs_2._guide/node0323.html):

   if (!(CheckIO(InputIO)))
```c
       {
       AbortIO(InputIO);  /* Ask device to abort request, if pending */
       }
```
   WaitIO(InputIO);       /* Wait for abort, then clean up */
   CloseDevice((struct IORequest *)InputIO);

