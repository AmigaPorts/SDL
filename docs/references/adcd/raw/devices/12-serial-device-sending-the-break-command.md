# 12 Serial Device / Sending the Break Command


You send a break through the serial device by passing an [IOExtSer](../Devices_Manual_guide/node009C.html#line7) to the
device with [SDCMD_BREAK](../Includes_and_Autodocs_2._guide/node04D5.html) set in io_Command.  The break may be immediate or
queued.  The choice is determined by the state of flag [SERF_QUEUEDBRK](../Devices_Manual_guide/node00A7.html#line47) in
io_SerFlags.

   SerialIO->IOSer.io_Command  = SDCMD_BREAK; /* send break */
   SendIO((struct IORequest *)SerialIO);

The duration of the break (in microseconds) can be set in io_BrkTime. The
default is 250,000 microseconds (.25 seconds).

