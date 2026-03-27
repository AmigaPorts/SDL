# 12 / Device Interface / Writing To The Serial Device


You write to the serial device by passing an [IOExtSer](../Devices_Manual_guide/node009C.html#line7) to the device with
[CMD_WRITE](../Includes_and_Autodocs_2._guide/node04D3.html) set in io_Command, the number of bytes to be written set in
io_Length and the address of the write buffer set in io_Data.

To write a NULL-terminated string, set the length to -1; the device will
output from your buffer until it encounters and transmits a value of zero
(0x00).

   SerialIO->IOSer.io_Length   = -1;
   SerialIO->IOSer.io_Data     = (APTR)"Life is but a dream. ";
   SerialIO->IOSer.io_Command  = CMD_WRITE;
   DoIO((struct IORequest *)SerialIO);             /* execute write */

The length of the request is -1, meaning we are writing a NULL-terminated
string. The number of characters sent can be found in io_Actual.

