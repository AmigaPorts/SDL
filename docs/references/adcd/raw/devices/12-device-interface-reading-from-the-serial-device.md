# 12 / Device Interface / Reading From The Serial Device


You read from the serial device by passing an [IOExtSer](../Devices_Manual_guide/node009C.html#line7) to the device with
[CMD_READ](../Includes_and_Autodocs_2._guide/node04CF.html) set in io_Command, the number of bytes to be read set in
io_Length and the address of the read buffer set in io_Data.

   #define READ_BUFFER_SIZE 256
   char SerialReadBuffer[READ_BUFFER_SIZE]; /* Reserve SIZE bytes */

   SerialIO->IOSer.io_Length   = READ_BUFFER_SIZE;
   SerialIO->IOSer.io_Data     = (APTR)&SerialReadBuffer[0];
   SerialIO->IOSer.io_Command  = CMD_READ;
   DoIO((struct IORequest *)SerialIO);

If you use this example, your task will be put to sleep waiting until the
serial device reads 256 bytes (or terminates early).  Early termination
can be caused by error conditions such as a break.  The number of
characters actually received will be recorded in the io_Actual field of the
[IOExtSer](../Devices_Manual_guide/node009C.html#line7) structure you passed to the serial device.

