---
title: 1 Introduction to Amiga System Devices / Example Device Programs
manual: devices
chapter: devices
section: 1-introduction-to-amiga-system-devices-example-device
functions: [CreateIORequest, CreateMsgPort]
libraries: [exec.library]
---

# 1 Introduction to Amiga System Devices / Example Device Programs

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following short programs are examples of how to use a device.  Both
send the serial device command SDCMD_QUERY to the serial device to
determine the status of the serial device lines and registers.  The first
program is for pre-V36 versions of the operating system (before Release 2)
and the second is for V36 and higher.  You may use the pre-V36 version
with V36 and higher, but you may not use the V36 version with older
systems.

The programs differ in the way they create the message port and I/O
request.  The pre-V36 version uses the amiga.lib functions [CreatePort()](autodocs-2.0/amiga-lib-createport.md) to
create the message port and [CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md) to create the I/O request; the
V36 version uses the Exec functions [CreateMsgPort()](autodocs-2.0/exec-library-createmsgport.md) to create the message
port and [CreateIORequest()](autodocs-2.0/exec-library-createiorequest.md) to create the I/O request.  Those are the only
differences.


```c
     [Device Usage Example (Pre-V36)](devices/devices-dev-examples-pre-v36-device-use-c.md) 
     [Device Usage Example (Kickstart V36 And Up)](devices/devices-dev-examples-v36-device-use-c.md) 
```

---

## See Also

- [CreateIORequest — exec.library](../autodocs/exec.library.md#createiorequest)
- [CreateMsgPort — exec.library](../autodocs/exec.library.md#createmsgport)
