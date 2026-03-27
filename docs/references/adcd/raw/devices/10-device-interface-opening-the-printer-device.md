# 10 / Device Interface / Opening The Printer Device


Three primary steps are required to open the printer device:

   *  Create a message port using [CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html).  Reply messages from the

      device must be directed to a message port.
   *  Create an extended I/O request structure of type [printerIO](../Devices_Manual_guide/node0044.html#line16) with the

```c
      [CreateExtIO()](../Includes_and_Autodocs_2._guide/node0147.html) function.  This means that one memory area can be used
      to represent three distinct forms of memory layout for the three
      different types of data structures that must be used to pass commands
      to the printer device. By using CreateExtIO(), you automatically
      allocate enough memory to hold the largest structure in the union
      statement.
```
   *  Open the printer device.  Call [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html), passing the I/O request.


```c
    union printerIO
    {
        struct IOStdReq    ios;
        struct IODRPReq    iodrp;
        struct IOPrtCmdReq iopc;
    };

    struct MsgPort  *PrintMP;         /* Message port pointer */
    union printerIO *PrintIO;         /* I/O request pointer */

    if (PrintMP=CreateMsgPort() )
      if (PrintIO=(union printerIO *)
                   CreateExtIO(PrintMP,sizeof(union printerIO)) )
         if (OpenDevice("printer.device",0L,(struct IORequest *)PrintIO,0))
              printf("printer.device did not open\n");
```
The printer device automatically fills in default settings for all printer
device parameters from Preferences.  In addition, information about the
printer itself is placed into the appropriate fields of [printerIO](../Devices_Manual_guide/node0044.html#line16). (See
the [Obtaining Printer Specific Data](../Devices_Manual_guide/node004B.html) section below.)

   Pre-V36 Tasks and [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html).
   -------------------------------
   Tasks in pre-V36 versions of the operating system are not able to
   safely OpenDevice() the printer device because it may be necessary to
   load it in from disk, something only a process could do under
   pre-V36.  V36 and higher versions of the operating system do not have
   such a limitation.

