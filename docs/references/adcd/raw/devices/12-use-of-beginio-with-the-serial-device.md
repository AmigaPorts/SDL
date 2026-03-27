# 12 / / Use Of BeginIO() With The Serial Device


Instead of transmitting the read command with either [DoIO()](../Includes_and_Autodocs_2._guide/node034B.html) or [SendIO()](../Includes_and_Autodocs_2._guide/node037A.html),
you might elect to use the low level [BeginIO()](../Includes_and_Autodocs_2._guide/node04CB.html) interface to a device.

[BeginIO()](../Includes_and_Autodocs_2._guide/node04CB.html) works much like [SendIO()](../Includes_and_Autodocs_2._guide/node037A.html), i.e., asynchronously, except it gives
you control over the quick I/O bit (IOB_QUICK) in the io_Flags field.
Quick I/O saves the overhead of a reply message, and perhaps the overhead
of a task switch. If a quick I/O request is actually completed quickly,
the entire command will execute in the context of the caller. See the
"[Exec: Device Input/Output](../Libraries_Manual_guide/node0299.html)" chapter of the Amiga ROM Kernel Reference
Manual: Libraries for more detailed information on quick I/O.

The device will determine if a quick I/O request will be handled quickly.
Most non-I/O commands will execute quickly; read and write commands may or
may not finish quickly.

   SerialIO.IOSer.io_Flags |= IOF_QUICK;  /* Set QuickIO Flag */

   BeginIO((struct IORequest *)SerialIO);
   if (SerialIO->IOSer.io_Flags & IOF_QUICK )
```c
       /* If flag is still set, I/O was synchronous and is now finished.
        * The IORequest was NOT appended a reply port.  There is no
        * need to remove or WaitIO() for the message.
        */
       printf("QuickIO\n");
```
   else
```c
        /* The device cleared the QuickIO bit.  QuickIO could not happen
         * for some reason; the device processed the command normally.
         * In this case BeginIO() acted exactly like SendIO().
         */
        printf("Regular I/O\n");
```
   WaitIO(SerialIO);

The way you read from the device depends on your need for processing
speed. Generally the [BeginIO()](../Includes_and_Autodocs_2._guide/node04CB.html) route provides the lowest system overhead
when quick I/O is possible.  However, if quick I/O does not work, the same
reply message overhead still exists.

