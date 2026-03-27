# 2 / Device Interface / Closing The Audio Device


An [OpenDevice()](../Includes_and_Autodocs_2._guide/node04B8.html) must eventually be matched by a call to [CloseDevice()](../Includes_and_Autodocs_2._guide/node04AE.html).

All I/O requests must be complete before CloseDevice().  If any requests
are still pending, abort them with [AbortIO()](../Includes_and_Autodocs_2._guide/node04A5.html) :

  AbortIO((struct IORequest *)AudioIO);  /* Abort any pending requests */
  WaitPort(AudioMP);                     /* Wait for abort message */
  GetMsg(AudioMP);                       /* Get abort message */
  CloseDevice((struct IORequest *)AudioIO);

CloseDevice() performs an [ADCMD_FREE](../Devices_Manual_guide/node002F.html) command on any channels selected by
the ioa_Request.io_Unit field of the [IOAudio](../Devices_Manual_guide/node001E.html#line11) request.  This means that if
you close the device with the same IOAudio block that you used to allocate
your channels (or a copy of it), the channels will be automatically freed.

If you allocated channels with multiple allocation commands, you cannot
use this function to close all of them at once. Instead, you will have to
issue one [ADCMD_FREE](../Devices_Manual_guide/node002F.html) command for each allocation that you made. After
issuing the ADCMD_FREE commands for each of the allocations, you can call
CloseDevice().

