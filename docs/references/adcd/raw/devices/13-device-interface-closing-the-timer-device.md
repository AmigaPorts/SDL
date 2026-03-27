# 13 / Device Interface / Closing The Timer Device


Each [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html) must eventually be matched by a call to [CloseDevice()](../Includes_and_Autodocs_2._guide/node033F.html).

All I/O requests must be complete before [CloseDevice()](../Includes_and_Autodocs_2._guide/node033F.html).  If any requests
are still pending, abort them with [AbortIO()](../Includes_and_Autodocs_2._guide/node0323.html).

   if (!(CheckIO(TimerIO)))
```c
       {
       AbortIO(TimerIO);    /* Ask device to abort any pending requests */
       }
```
   WaitIO(TimerIO);         /* Clean up */
   CloseDevice((struct IORequest *)TimerIO);  /* Close Timer device */

