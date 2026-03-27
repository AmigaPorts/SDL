---
title: 19 / Accessing a Device / Opening a Device
manual: libraries
chapter: libraries
section: 19-accessing-a-device-opening-a-device
functions: [OpenDevice]
libraries: [exec.library]
---

# 19 / Accessing a Device / Opening a Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The device is opened by calling the [OpenDevice()](autodocs-2.0/exec-library-opendevice.md) function.  In addition to
establishing the link to the device, OpenDevice() also initializes fields
in the I/O request.  OpenDevice() has this format:


```c
    return = OpenDevice(device_name,
                        unit_number,
      			(struct IORequest *)IORequest,
                        flags)
```
  * device_name is one of the following NULL-terminated strings for

```c
    system devices:

        [Audio](devices/2-audio-device.md).device     [Parallel](devices/9-parallel-device.md).device  [Clipboard](devices/3-clipboard-device.md).device
        [Printer](devices/10-printer-device.md).device   [Console](devices/4-console-device.md).device   [scsi](devices/11-scsi-device.md).device
        [Gameport](devices/5-gameport-device.md).device  [Serial](devices/12-serial-device.md).device    [Input](devices/6-input-device.md).device
        [Timer](devices/13-timer-device.md).device     [Keyboard](devices/7-keyboard-device.md).device  [Trackdisk](devices/14-trackdisk-device.md).device
                         [Narrator](devices/8-narrator-device.md).device
```
  * unit_number is refers to one of the logical units of the device.

    Devices with one unit always use unit 0.  Multiple unit devices like
    the trackdisk device and the timer device use the different units for
    specific purposes.
  * [IORequest](autodocs-2.0/includes-exec-io-h.md) is the structure [discussed above](libraries/19-accessing-a-device-creating-an-i-o-request.md).  Some of the devices have

```c
    their own I/O requests defined in their include files and others use
    standard I/O requests, ([IOStdReq](autodocs-2.0/includes-exec-io-h.md)).  Refer to the Amiga ROM Kernel
    Reference Manual: [Devices](devices/contents-2.md) for more information.
```
  * flags are bits set to indicate options for some of the devices. This

```c
    field is set to zero for devices which don't accept options when they
    are opened.  The flags for each device are explained in the Amiga ROM
    Kernel Reference Manual: [Devices](devices/contents-2.md).
```
  * return is an indication of whether the [OpenDevice()](autodocs-2.0/exec-library-opendevice.md) was successful

```c
    with zero indicating success.  Never assume that a device will
    successfully open.  Check the return value and act accordingly.

    Zero Equals Success for [OpenDevice()](autodocs-2.0/exec-library-opendevice.md).
    -------------------------------------
    Unlike most Amiga system functions, OpenDevice() returns zero for
    success and a device-specific error value for failure.
```

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
