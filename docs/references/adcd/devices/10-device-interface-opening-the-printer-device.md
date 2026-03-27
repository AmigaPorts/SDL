---
title: 10 / Device Interface / Opening The Printer Device
manual: devices
chapter: devices
section: 10-device-interface-opening-the-printer-device
functions: [CreateMsgPort, OpenDevice]
libraries: [exec.library]
---

# 10 / Device Interface / Opening The Printer Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Three primary steps are required to open the printer device:

   *  Create a message port using [CreatePort()](autodocs-2.0/amiga-lib-createport.md).  Reply messages from the

      device must be directed to a message port.
   *  Create an extended I/O request structure of type [printerIO](devices/10-printer-device-device-interface.md) with the

```c
      [CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md) function.  This means that one memory area can be used
      to represent three distinct forms of memory layout for the three
      different types of data structures that must be used to pass commands
      to the printer device. By using CreateExtIO(), you automatically
      allocate enough memory to hold the largest structure in the union
      statement.
```
   *  Open the printer device.  Call [OpenDevice()](autodocs-2.0/exec-library-opendevice.md), passing the I/O request.


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
printer itself is placed into the appropriate fields of [printerIO](devices/10-printer-device-device-interface.md). (See
the [Obtaining Printer Specific Data](devices/10-printer-device-obtaining-printer-specific-data.md) section below.)

   Pre-V36 Tasks and [OpenDevice()](autodocs-2.0/exec-library-opendevice.md).
   -------------------------------
   Tasks in pre-V36 versions of the operating system are not able to
   safely OpenDevice() the printer device because it may be necessary to
   load it in from disk, something only a process could do under
   pre-V36.  V36 and higher versions of the operating system do not have
   such a limitation.

---

## See Also

- [CreateMsgPort — exec.library](../autodocs/exec.library.md#createmsgport)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
