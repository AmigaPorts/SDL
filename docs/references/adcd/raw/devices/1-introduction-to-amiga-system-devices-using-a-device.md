# 1 Introduction to Amiga System Devices / Using a Device


Once a device has been opened, you use it by passing the I/O request to
it. When the device processes the I/O request, it acts on the information
the I/O request contains and returns a reply message, i.e., the I/O
request, to the reply port specified in the I/O request when it is
finished. The I/O request is passed to a device using one of three
functions, [DoIO()](../Includes_and_Autodocs_2._guide/node034B.html), [SendIO()](../Includes_and_Autodocs_2._guide/node037A.html) and [BeginIO()](../Includes_and_Autodocs_2._guide/node0141.html). They take only one argument:
the I/O request you wish to pass to the device.


   *  [DoIO()](../Includes_and_Autodocs_2._guide/node034B.html) is a synchronous function. It will not return until the device

      has responded to the I/O request.
   *  [SendIO()](../Includes_and_Autodocs_2._guide/node037A.html) is an asynchronous function.  It can return immediately, but

```c
      the I/O operation it initiates may take a short or long time.  Using
      [SendIO()](../Includes_and_Autodocs_2._guide/node037A.html) requires you to monitor the message port for a return
      message from the device.  In addition, some devices do not actually
      respond asynchronously even though you called SendIO(); they will
      return when the I/O operation is finished.
```
   *  [BeginIO()](../Includes_and_Autodocs_2._guide/node0141.html) is commonly used to control the quick I/O bit when sending

```c
      an I/O request to a device.  When the quick I/O flag (IOF_QUICK) is
      set in the I/O request, a device is allowed to take certain shortcuts
      in performing and completing a request.  If the request can complete
      immediately, the device will not return a reply message and the quick
      I/O flag will remain set.  If the request cannot be completed
      immediately, the QUICK_IO flag will be clear.  [DoIO()](../Includes_and_Autodocs_2._guide/node034B.html) normally
      requests quick I/O; [SendIO()](../Includes_and_Autodocs_2._guide/node037A.html) does not.
```
[DoIO()](../Includes_and_Autodocs_2._guide/node034B.html) and [SendIO()](../Includes_and_Autodocs_2._guide/node037A.html) are most commonly used.

An I/O request typically has three fields set for every command sent to a
device.  You set the command itself in the io_Command field, a pointer to
the data for the command in the io_Data field, and the length of the data
in the io_Length field.

  SerialIO->IOSer.io_Length = sizeof(ReadBuffer);
  SerialIO->IOSer.io_Data = ReadBuffer;
  SerialIO->IOSer.io_Command  = CMD_READ;
  SendIO((struct IORequest *)SerialIO);

Commands consist of two parts - a prefix and the command word separated by
an underscore, all in upper case.  The prefix indicates whether the
 command is an Exec or device specific command.  All Exec commands have
CMD as the prefix.  They are defined in the include file exec/[io.h](../Includes_and_Autodocs_2._guide/node0094.html).

 [Amiga Exec Commands](../Devices_Manual_guide/node0007.html) 
 [Amiga System Device Command Prefixes and Examples](../Devices_Manual_guide/node0008.html) 

