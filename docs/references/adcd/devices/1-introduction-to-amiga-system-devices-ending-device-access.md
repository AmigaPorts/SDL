---
title: 1 Introduction to Amiga System Devices / Ending Device Access
manual: devices
chapter: devices
section: 1-introduction-to-amiga-system-devices-ending-device-access
functions: [AbortIO, AllocMem, CloseDevice, CreateIORequest, CreateMsgPort, DeleteIORequest, DeleteMsgPort, FreeMem, WaitIO]
libraries: [exec.library, timer.device]
---

# 1 Introduction to Amiga System Devices / Ending Device Access

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You end device access by reversing the steps you took to access it.  This
means you close the device, deallocate the I/O request memory and delete
the message port.  In that order!

Closing a device is how you tell Exec that you are finished using a device
and any associated resources.  This can result in housecleaning being
performed by the device.  However, before you close a device, you might
have to do some housecleaning of your own.

A device is closed by calling the CloseDevice() function. The
CloseDevice() function does not return a value. It has this format:

  CloseDevice(IORequest)

where [IORequest](autodocs-2.0/includes-exec-io-h.md) is the I/O request used to open the device.

You should not close a device while there are outstanding I/O requests,
otherwise you can cause major and minor problems.  Let's begin with the
minor problem: memory.  If an I/O request is outstanding at the time you
close a device, you won't be able to reclaim the memory you allocated for
it.

The major problem: the device will try to respond to the I/O request.  If
the device tries to respond to an I/O request, and you've deleted the
message port (which is covered below), you will probably crash the system.

One solution would be to wait until all I/O requests you sent to the
device return.  This is not always practical if you've sent a few requests
and the user wants to exit the application immediately.

In that case, the only solution is to abort and remove any outstanding I/O
requests. You do this with the functions [AbortIO()](autodocs-2.0/exec-library-abortio.md) and [WaitIO()](autodocs-2.0/exec-library-waitio.md).  They
must be used together for cleaning up. AbortIO() will abort an I/O
request, but will not prevent a reply message from being sent to the
application requesting the abort. [WaitIO()](autodocs-2.0/exec-library-waitio.md) will wait for an I/O request to
complete and remove it from the message port.  This is why they must be
used together.

   Be Careful With AbortIO().
   --------------------------
   Do not [AbortIO()](autodocs-2.0/exec-library-abortio.md) an I/O request which has not been sent to a device.
   If you do, you may crash the system.

After the device is closed, you must deallocate the I/O request memory.
The exact method you use depends on how you allocated the memory in the
first place.  For [AllocMem()](autodocs-2.0/exec-library-allocmem.md) you call [FreeMem()](autodocs-2.0/exec-library-freemem.md), for [CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md) you
call [DeleteExtIO()](autodocs-2.0/amiga-lib-deleteextio.md), and for [CreateIORequest()](autodocs-2.0/exec-library-createiorequest.md) you call [DeleteIORequest()](autodocs-2.0/exec-library-deleteiorequest.md).
If you allocated the I/O request memory at compile time, you naturally
have nothing to free.

Finally, you must delete the message port you created.  You delete the
message port by calling [DeleteMsgPort()](autodocs-2.0/exec-library-deletemsgport.md) if you used [CreateMsgPort()](autodocs-2.0/exec-library-createmsgport.md), or
[DeletePort()](autodocs-2.0/amiga-lib-deleteport.md) if you used [CreatePort()](autodocs-2.0/amiga-lib-createport.md).

Here is the checklist for gracefully exiting:

   1. Abort any outstanding I/O requests with [AbortIO()](autodocs-2.0/exec-library-abortio.md)

   2. Wait for the completion of any outstanding or aborted I/O requests

```c
      with [WaitIO()](autodocs-2.0/exec-library-waitio.md).
```
   3. Close the device with CloseDevice().

   4. Release the I/O request memory with either [DeleteIORequest()](autodocs-2.0/exec-library-deleteiorequest.md),

```c
      [DeleteExtIO()](autodocs-2.0/amiga-lib-deleteextio.md) or [FreeMem()](autodocs-2.0/exec-library-freemem.md) (as appropriate).
```
   5. Delete the message port with [DeleteMsgPort()](autodocs-2.0/exec-library-deletemsgport.md) or [DeletePort()](autodocs-2.0/amiga-lib-deleteport.md).

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [AllocMem — exec.library](../autodocs/exec.library.md#allocmem)
- [CloseDevice — exec.library](../autodocs/exec.library.md#closedevice)
- [CreateIORequest — exec.library](../autodocs/exec.library.md#createiorequest)
- [CreateMsgPort — exec.library](../autodocs/exec.library.md#createmsgport)
- [DeleteIORequest — exec.library](../autodocs/exec.library.md#deleteiorequest)
- [DeleteMsgPort — exec.library](../autodocs/exec.library.md#deletemsgport)
- [FreeMem — exec.library](../autodocs/exec.library.md#freemem)
- [WaitIO — exec.library](../autodocs/exec.library.md#waitio)
