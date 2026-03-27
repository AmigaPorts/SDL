---
title: 19 / / I/O Request Completion / Ending Device Access
manual: libraries
chapter: libraries
section: 19-i-o-request-completion-ending-device-access
functions: [AbortIO, AllocMem, CloseDevice, CreateIORequest, CreateMsgPort, DeleteIORequest, DeleteMsgPort, FreeMem, WaitIO]
libraries: [exec.library, timer.device]
---

# 19 / / I/O Request Completion / Ending Device Access

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

After the device is closed, you must deallocate the I/O request memory.
The exact method you use depends on how you allocated the memory in the
first place.  For [AllocMem()](libraries/20-exec-memory-allocation-memory-functions.md) you call [FreeMem()](libraries/20-exec-memory-allocation-memory-functions.md), for [CreateExtIO()](libraries/a-amiga-lib-exec-support.md) you
call [DeleteExtIO()](libraries/a-amiga-lib-exec-support.md), and for [CreateIORequest()](autodocs-2.0/exec-library-createiorequest.md) you call [DeleteIORequest()](autodocs-2.0/exec-library-deleteiorequest.md).
If you allocated the I/O request memory at compile time, you naturally
have nothing to free.

Finally, you must delete the message port you created.  You delete the
message port by calling [DeleteMsgPort()](libraries/24-message-ports-deleting-a-message-port.md) if you used [CreateMsgPort()](libraries/24-message-ports-creating-a-message-port.md), or
[DeletePort()](libraries/24-message-ports-deleting-a-message-port.md) if you used [CreatePort()](libraries/24-message-ports-creating-a-message-port.md).

Here is the checklist for gracefully exiting:

  * Abort any outstanding I/O requests with [AbortIO()](libraries/19-i-o-request-completion-closing-the-device.md).

  * Wait for the completion of any outstanding or aborted I/O

```c
    requests with [WaitIO()](libraries/19-using-a-device-synchronous-vs-asynchronous-requests.md).
```
  * Close the device with [CloseDevice()](libraries/19-i-o-request-completion-closing-the-device.md).

  * Release the I/O request memory with either [DeleteIORequest()](autodocs-2.0/exec-library-deleteiorequest.md),

```c
    [DeleteExtIO()](libraries/a-amiga-lib-exec-support.md) or [FreeMem()](libraries/20-exec-memory-allocation-memory-functions.md) (as appropriate).
```
  * Delete the message port with [DeleteMsgPort()](libraries/24-message-ports-deleting-a-message-port.md) or [DeletePort()](libraries/24-message-ports-deleting-a-message-port.md).

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
