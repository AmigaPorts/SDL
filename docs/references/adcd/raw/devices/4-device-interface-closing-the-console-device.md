# 4 / Device Interface / Closing The Console Device


Each [OpenDevice()](../Includes_and_Autodocs_2._guide/node0509.html) must eventually be matched by a call to [CloseDevice()](../Includes_and_Autodocs_2._guide/node033F.html).

All I/O requests must be complete before [CloseDevice()](../Includes_and_Autodocs_2._guide/node033F.html).  If any requests
are still pending, abort them with [AbortIO()](../Includes_and_Autodocs_2._guide/node0323.html).


```c
    if (!(CheckIO(ConsIO)))
        AbortIO(ConsIO);    /* Ask device to abort any pending requests */

    WaitIO(ConsIO);         /* Wait for abort, then clean up */
    CloseDevice(ConsIO);    /* Close console device */
```
