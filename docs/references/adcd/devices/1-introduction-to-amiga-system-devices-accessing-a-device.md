---
title: 1 Introduction to Amiga System Devices / Accessing a Device
manual: devices
chapter: devices
section: 1-introduction-to-amiga-system-devices-accessing-a-device
functions: [AllocMem, CreateIORequest, CreateMsgPort, DeleteIORequest, DeleteMsgPort, FreeMem, OpenDevice]
libraries: [exec.library]
---

# 1 Introduction to Amiga System Devices / Accessing a Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Accessing a device requires obtaining a message port, allocating memory
for a specialized message packet called an I/O request, setting a pointer
to the message port in the I/O request, and finally, establishing the link
to the device itself by opening it.  An example of how to do this will be
provided later in this chapter.

The message port is used by the device to return messages to you.  A
message port is obtained by calling the [CreateMsgPort()](autodocs-2.0/exec-library-createmsgport.md) or [CreatePort()](autodocs-2.0/amiga-lib-createport.md)
function.  You must delete the message port when you are finished by
calling the [DeleteMsgPort()](autodocs-2.0/exec-library-deletemsgport.md) or [DeletePort()](autodocs-2.0/amiga-lib-deleteport.md) function.

For pre-V36 versions of the operating system (before Release 2.0), use the
amiga.lib functions [CreatePort()](autodocs-2.0/amiga-lib-createport.md) and [DeletePort()](autodocs-2.0/amiga-lib-deleteport.md); for V36 and higher, use
the Exec functions [CreateMsgPort()](autodocs-2.0/exec-library-createmsgport.md) and [DeleteMsgPort()](autodocs-2.0/exec-library-deletemsgport.md). [CreatePort()](autodocs-2.0/amiga-lib-createport.md) and
[DeletePort()](autodocs-2.0/amiga-lib-deleteport.md) are upward compatible, you can use them with V36/V37;
[CreateMsgPort()](autodocs-2.0/exec-library-createmsgport.md) and [DeleteMsgPort()](autodocs-2.0/exec-library-deletemsgport.md) are not backward compatible, however.

The I/O request is used to send commands and data from your application to
the device.  The I/O request consists of fields used to hold the command
you wish to execute and any parameters it requires.  You set up the fields
with the appropriate information and send it to the device by using Exec
I/O functions.

At least four methods exist for creating an I/O request:

   *  Declaring it as a structure.  The memory required will be allocated

      at compile time.
   *  Declaring it as a pointer and calling the [AllocMem()](autodocs-2.0/exec-library-allocmem.md) function.  You

```c
      will have to call the [FreeMem()](autodocs-2.0/exec-library-freemem.md) function to release the memory when
      you are done.
```
   *  Declaring it as a pointer and calling the [CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md) function.

```c
      This function not only allocates the memory for the request, it also
      puts the message port in the I/O request.  You will have to call the
      [DeleteExtIO()](autodocs-2.0/amiga-lib-deleteextio.md) function to delete the I/O request when you are done.
      This is the pre-V36 method (used in 1.3 and earlier versions of the
      operating system), but is upward compatible.
```
   *  Declaring it as a pointer and calling the [CreateIORequest()](autodocs-2.0/exec-library-createiorequest.md) function.

```c
      This function not only allocates the memory for the request, it also
      puts the message port in the I/O request.  You will have to call the
      [DeleteIORequest()](autodocs-2.0/exec-library-deleteiorequest.md) function to delete the I/O request when you are
      done.  This is the V36/V37 method; it is not backwards compatible.
```
The message port pointer in the I/O request tells the device where to
respond with messages for your application.  You must set a pointer to the
message port in the I/O request if you declare it as a structure or
allocate memory for it using [AllocMem()](autodocs-2.0/exec-library-allocmem.md).

The device is opened by calling the [OpenDevice()](autodocs-2.0/exec-library-opendevice.md) function.  In addition to
establishing the link to the device, OpenDevice() also initializes fields
in the I/O request.  OpenDevice() has this format:

  return = OpenDevice(device_name,unit_number,

```c
                     (struct IORequest *)IORequest,flags)
```
where:

   *  device_name is one of the following NULL-terminated strings for

      system devices:

        audio.device        keyboard.device    serial.device
        clipboard.device    narrator.device    timer.device
        console.device      parallel.device    trackdisk.device
        gameport.device     printer.device     input.device
        scsi.device
   *  unit_number refers to one of the logical units of the device. Devices

      with one unit always use unit 0.  Multiple unit devices like the
      trackdisk device and the timer device use the different units for
      specific purposes.  The device chapters discuss the units in detail.
   *  [IORequest](autodocs-2.0/includes-exec-io-h.md) is the structure discussed above.  Some of the devices have

```c
      their own I/O requests defined in their include files and others use
      standard I/O requests, ([IOStdReq](autodocs-2.0/includes-exec-io-h.md)).  The device chapters list the I/O
      request that each device requires.
```
   *  flags are bits set to indicate options for some of the devices.  This

      field is set to zero for devices which don't accept options when they
      are opened.  The device chapters and autodocs list the flags values
      and uses.
   *  return is an indication of whether the [OpenDevice()](autodocs-2.0/exec-library-opendevice.md) was successful

      with zero indicating success.  Never assume that a device will
      successfully open.  Check the return value and act accordingly.
   Zero Equals Success for OpenDevice().
   -------------------------------------
   Unlike most Amiga system functions, [OpenDevice()](autodocs-2.0/exec-library-opendevice.md) returns zero for
   success and a device-specific error value for failure.

---

## See Also

- [AllocMem — exec.library](../autodocs/exec.library.md#allocmem)
- [CreateIORequest — exec.library](../autodocs/exec.library.md#createiorequest)
- [CreateMsgPort — exec.library](../autodocs/exec.library.md#createmsgport)
- [DeleteIORequest — exec.library](../autodocs/exec.library.md#deleteiorequest)
- [DeleteMsgPort — exec.library](../autodocs/exec.library.md#deletemsgport)
- [FreeMem — exec.library](../autodocs/exec.library.md#freemem)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
