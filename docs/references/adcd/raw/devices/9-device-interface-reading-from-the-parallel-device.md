# 9 / Device Interface / Reading From The Parallel Device


You read from the parallel device by passing an [IOExtPar](../Devices_Manual_guide/node0010.html#line7) to the device
with [CMD_READ](../Includes_and_Autodocs_2._guide/node04ED.html) set in io_Command, the number of bytes to be read set in
io_Length and the address of the read buffer set in io_Data.

   #define READ_BUFFER_SIZE 256
   /* Reserve SIZE bytes of storage */
   char ParallelReadBuffer[READ_BUFFER_SIZE];

   ParallelIO->IOPar.io_Length   = READ_BUFFER_SIZE;
   ParallelIO->IOPar.io_Data     = (APTR)&ParallelReadBuffer[0];
   ParallelIO->IOPar.io_Command  = CMD_READ;
   DoIO((struct IORequest *)ParallelIO);

If you use this example, your task will be put to sleep waiting until the
parallel device reads 256 bytes (or terminates early).  Early termination
can be caused by error conditions.

