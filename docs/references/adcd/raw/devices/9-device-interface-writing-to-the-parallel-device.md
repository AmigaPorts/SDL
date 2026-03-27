# 9 / Device Interface / Writing To The Parallel Device


You write to the parallel device by passing an [IOExtPar](../Devices_Manual_guide/node0010.html#line7) to the device with
[CMD_WRITE](../Includes_and_Autodocs_2._guide/node04F1.html) set in io_Command, the number of bytes to be written set in
io_Length and the address of the write buffer set in io_Data.

To write a NULL-terminated string, set the length to -1; the device will
output from your buffer until it encounters and transmits a value of zero
(0x00).

   ParallelIO->IOPar.io_Length   = -1;
   ParallelIO->IOPar.io_Data     = (APTR)"Parallel lines cross 7 times...";
   ParallelIO->IOPar.io_Command  = CMD_WRITE;
   DoIO((struct IORequest *)ParallelIO);             /* execute write */

The length of the request is -1, meaning we are writing a NULL-terminated
string. The number of characters sent can be found in io_Actual.

