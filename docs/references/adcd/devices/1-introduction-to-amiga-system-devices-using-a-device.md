---
title: 1 Introduction to Amiga System Devices / Using a Device
manual: devices
chapter: devices
section: 1-introduction-to-amiga-system-devices-using-a-device
functions: [DoIO, SendIO]
libraries: [exec.library]
---

# 1 Introduction to Amiga System Devices / Using a Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Once a device has been opened, you use it by passing the I/O request to
it. When the device processes the I/O request, it acts on the information
the I/O request contains and returns a reply message, i.e., the I/O
request, to the reply port specified in the I/O request when it is
finished. The I/O request is passed to a device using one of three
functions, [DoIO()](autodocs-2.0/exec-library-doio.md), [SendIO()](autodocs-2.0/exec-library-sendio.md) and [BeginIO()](autodocs-2.0/amiga-lib-beginio.md). They take only one argument:
the I/O request you wish to pass to the device.


   *  [DoIO()](autodocs-2.0/exec-library-doio.md) is a synchronous function. It will not return until the device

      has responded to the I/O request.
   *  [SendIO()](autodocs-2.0/exec-library-sendio.md) is an asynchronous function.  It can return immediately, but

```c
      the I/O operation it initiates may take a short or long time.  Using
      [SendIO()](autodocs-2.0/exec-library-sendio.md) requires you to monitor the message port for a return
      message from the device.  In addition, some devices do not actually
      respond asynchronously even though you called SendIO(); they will
      return when the I/O operation is finished.
```
   *  [BeginIO()](autodocs-2.0/amiga-lib-beginio.md) is commonly used to control the quick I/O bit when sending

```c
      an I/O request to a device.  When the quick I/O flag (IOF_QUICK) is
      set in the I/O request, a device is allowed to take certain shortcuts
      in performing and completing a request.  If the request can complete
      immediately, the device will not return a reply message and the quick
      I/O flag will remain set.  If the request cannot be completed
      immediately, the QUICK_IO flag will be clear.  [DoIO()](autodocs-2.0/exec-library-doio.md) normally
      requests quick I/O; [SendIO()](autodocs-2.0/exec-library-sendio.md) does not.
```
[DoIO()](autodocs-2.0/exec-library-doio.md) and [SendIO()](autodocs-2.0/exec-library-sendio.md) are most commonly used.

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
CMD as the prefix.  They are defined in the include file exec/[io.h](autodocs-2.0/includes-exec-io-h.md).

 [Amiga Exec Commands](devices/1-using-a-device-amiga-exec-commands.md) 
 [Amiga System Device Command Prefixes and Examples](devices/1-using-a-device-amiga-system-device-command-prefixes-and.md) 

---

## See Also

- [DoIO — exec.library](../autodocs/exec.library.md#doio)
- [SendIO — exec.library](../autodocs/exec.library.md#sendio)
