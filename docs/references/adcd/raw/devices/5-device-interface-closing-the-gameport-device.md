# 5 / Device Interface / Closing The Gameport Device


Each [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html) must eventually be matched by a call to [CloseDevice()](../Includes_and_Autodocs_2._guide/node033F.html).

All I/O requests must be complete before [CloseDevice()](../Includes_and_Autodocs_2._guide/node033F.html).  If any requests
are still pending, abort them with [AbortIO()](../Includes_and_Autodocs_2._guide/node0323.html) and remove them with [WaitIO()](../Includes_and_Autodocs_2._guide/node038B.html).


```c
    if (!(CheckIO(GameIO)))
        {
        AbortIO(GameIO);  /* Ask device to abort request, if pending */
        }
    WaitIO((GameIO);   /* Wait for abort, then clean up */
    CloseDevice(GameIO);
```
