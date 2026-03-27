---
title: serial.device/BeginIO
manual: autodocs-3.5
chapter: autodocs-3.5
section: serial-device-beginio-2
functions: [DoIO, SendIO]
libraries: [exec.library]
---

# serial.device/BeginIO

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
```c
       BeginIO(ioRequest),deviceNode -- start up an I/O process
                A1        A6
```
   FUNCTION

```c
       This is a direct function call to the device.  It is intended for
       more advanced programmers.  See exec's [DoIO()](autodocs-3.5/exec-library-doio-2.md) and [SendIO()](autodocs-3.5/exec-library-sendio-2.md) for
       the normal method of calling devices.

       This function initiates a I/O request made to the serial
       device. Other than read or write, the functions are performed
       synchronously, and do not depend on any interrupt handling
       logic (or it's associated discontinuities), and hence should
       be performed as IO_QUICK.
       With some exceptions, reads and writes are merely initiated by
       BeginIO, and thusly return to the caller as begun, not completed.
       Completion is signalled via the standard [ReplyMsg](autodocs-3.5/exec-library-replymsg-2.md) routine.
       Multiple requests are handled via FIFO queueing.
       One exception to this non-QUICK handling of reads and writes
       is for READS when:
         - IO_QUICK bit is set
         - There are no pending read requests
         - There is already enough data in the input buffer to satisfy
           this I/O [Request](autodocs-3.5/intuition-library-request-2.md) immediately.
       In this case, the IO_QUICK flag is not cleared, and the request
       is completed by the time it returns to the caller. There is no
       [ReplyMsg](autodocs-3.5/exec-library-replymsg-2.md) or signal bit activity in this case.
```
   INPUTS

```c
       ioRequest  -- pointer to an I/O [Request](autodocs-3.5/intuition-library-request-2.md) Block of size
           io_ExtSerSize (see serial.i for size/definition),
           containing a valid command in io_Command to process,
           as well as the command's other required parameters.
       deviceNode -- pointer to the "serial.device", as found in
           the IO_DEVICE of the ioRequest.
```
   RESULTS

       io_Error -- if the BeginIO succeded, then Error will be null.
           If the BeginIO failed, then the Error will be non-zero.
           I/O errors won't be reported until the io completes.
   SEE ALSO
	[devices/serial.h](autodocs-3.5/include-devices-serial-h.md)

---

## See Also

- [DoIO — exec.library](../autodocs/exec.library.md#doio)
- [SendIO — exec.library](../autodocs/exec.library.md#sendio)
