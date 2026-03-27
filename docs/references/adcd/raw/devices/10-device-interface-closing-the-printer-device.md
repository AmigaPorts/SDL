# 10 / Device Interface / Closing The Printer Device


Each [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html) must eventually be matched by a call to [CloseDevice()](../Includes_and_Autodocs_2._guide/node033F.html).

All I/O requests must be complete before [CloseDevice()](../Includes_and_Autodocs_2._guide/node033F.html).  If any requests
are still pending, abort them with [AbortIO()](../Includes_and_Autodocs_2._guide/node0323.html).

   AbortIO(PrintIO);  /* Ask device to abort request, if pending */
   WaitIO(PrintIO);   /* Wait for abort, then clean up */

   CloseDevice((struct IORequest *)PrintIO);

   Use [AbortIO()](../Includes_and_Autodocs_2._guide/node0323.html) / [WaitIO()](../Includes_and_Autodocs_2._guide/node038B.html) Intelligently.
   -------------------------------------
   Only call AbortIO()/WaitIO() for requests which have already been
   sent to the printer device.  Using the AbortIO()/WaitIO() sequence on
   requests which have not been sent results in a hung condition.

