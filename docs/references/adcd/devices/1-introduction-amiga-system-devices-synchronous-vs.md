---
title: 1 Introduction Amiga System Devices / Synchronous vs. Asynchronous Requests
manual: devices
chapter: devices
section: 1-introduction-amiga-system-devices-synchronous-vs
functions: [CheckIO, DoIO, SendIO, Wait, WaitIO, WaitPort]
libraries: [exec.library]
---

# 1 Introduction Amiga System Devices / Synchronous vs. Asynchronous Requests

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

As stated above, you can send I/O requests to a device synchronously or
asynchronously.  The choice of which to use is largely a function of your
application.

Synchronous requests use the [DoIO()](autodocs-2.0/exec-library-doio.md) function.  [DoIO()](autodocs-2.0/exec-library-doio.md) will not return
control to your application until the I/O request has been satisfied by
the device.  The advantage of this is that you don't have to monitor the
message port for the device reply because [DoIO()](autodocs-2.0/exec-library-doio.md) takes care of all the
message handling. The disadvantage is that your application will be tied
up while the I/O request is being processed, and should the request not
complete for some reason, [DoIO()](autodocs-2.0/exec-library-doio.md) will not return and your application will
hang.

Asynchronous requests use the [SendIO()](autodocs-2.0/exec-library-sendio.md) and [BeginIO()](autodocs-2.0/amiga-lib-beginio.md) functions. Both
return to your application almost immediately after you call them.  This
allows you to do other operations, including sending more I/O requests to
the device.

   Do Not Touch!
   -------------
   When you use [SendIO()](autodocs-2.0/exec-library-sendio.md) or [BeginIO()](autodocs-2.0/amiga-lib-beginio.md), the I/O request you pass to the
   device and any associated data buffers should be considered
   read-only. Once you send it to the device, you must not modify it in
   any way until you receive the reply message from the device or abort
   the request (though you must still wait for a reply). Any exceptions
   to this rule are documented in the autodoc for the device.

Sending multiple asynchronous I/O requests to a device can be tricky
because devices require them to be unique and initialized.  This means
you can't use an I/O request that's still in the queue, but you need the
fields which were initialized in it when you opened the device.  The
solution is to copy the initialized I/O request to another I/O request(s)
before sending anything to the device.

Regardless of what you do while you are waiting for an asynchronous I/O
request to return, you need to have some mechanism for knowing when the
request has been done.  There are two basic methods for doing this.

The first involves putting your application into a wait state until the
device returns the I/O request to the message port of your application.
You can use the [WaitIO()](autodocs-2.0/exec-library-waitio.md), [Wait()](autodocs-2.0/exec-library-wait.md) or [WaitPort()](autodocs-2.0/exec-library-waitport.md) function to wait for the
return of the I/O request.

[WaitIO()](autodocs-2.0/exec-library-waitio.md) not only waits for the return of the I/O request, it also takes
care of all the message handling functions.  This is very convenient, but
you can pay for this convenience: your application will hang in the
unlikely event that the I/O request does not return.

[Wait()](autodocs-2.0/exec-library-wait.md) waits for a signal to be sent to the message port.  It will awaken
your task when the signal arrives, but you are responsible for all of the
message handling.

[WaitPort()](autodocs-2.0/exec-library-waitport.md) waits for the message port to be non-empty.  It returns a
pointer to the message in the port, but you are responsible for all of the
message handling.

The second method to detect when the request is complete involves using
the [CheckIO()](autodocs-2.0/exec-library-checkio.md) function.  CheckIO() takes an I/O request as its argument
and returns an indication of whether or not it has been completed. When
CheckIO() returns the completed indication, you will still have to remove
the I/O request from the message port.

---

## See Also

- [CheckIO — exec.library](../autodocs/exec.library.md#checkio)
- [DoIO — exec.library](../autodocs/exec.library.md#doio)
- [SendIO — exec.library](../autodocs/exec.library.md#sendio)
- [Wait — exec.library](../autodocs/exec.library.md#wait)
- [WaitIO — exec.library](../autodocs/exec.library.md#waitio)
- [WaitPort — exec.library](../autodocs/exec.library.md#waitport)
