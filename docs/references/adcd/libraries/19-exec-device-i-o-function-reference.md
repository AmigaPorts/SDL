---
title: 19 Exec Device I/O / Function Reference
manual: libraries
chapter: libraries
section: 19-exec-device-i-o-function-reference
functions: [AbortIO, CheckIO, CloseDevice, CreateIORequest, DeleteIORequest, DoIO, OpenDevice, SendIO, WaitIO]
libraries: [exec.library, timer.device]
---

# 19 Exec Device I/O / Function Reference

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following chart gives a brief description of the Exec functions that
control device I/O.  See the Amiga ROM Kernel Reference Manual: Includes
and Autodocs for details about each call.


                  Table 19-4: Exec Device I/O Functions
  ______________________________________________________________________
 |                                                                      |
 |     Exec Device                                                      |
 |     I/O Function                  Description                        |
 |======================================================================|
 |  [CreateIORequest()](autodocs-2.0/exec-library-createiorequest.md)  Create an [IORequest](libraries/19-accessing-a-device-creating-an-i-o-request.md) structure (V36).             |
 |  [DeleteIORequest()](autodocs-2.0/exec-library-deleteiorequest.md)  Delete an IORequest created by CreateIORequest() |
 |                     (V36).                                           |
 |       [OpenDevice()](autodocs-2.0/exec-library-opendevice.md)  Gain access to an Exec device.                   |
 |      [CloseDevice()](autodocs-2.0/exec-library-closedevice.md)  Close Exec device opened with OpenDevice().      |
 |             [DoIO()](autodocs-2.0/exec-library-doio.md)  Perform a device I/O command and wait for        |
 |                     completion.                                      |
 |           [SendIO()](autodocs-2.0/exec-library-sendio.md)  Initiate an I/O command.  Do not wait for it to  |
 |                     complete.                                        |
 |          [CheckIO()](autodocs-2.0/exec-library-checkio.md)  Get the status of an IORequest.                  |
 |           [WaitIO()](autodocs-2.0/exec-library-waitio.md)  Wait for completion of an I/O request.           |
 |          [AbortIO()](autodocs-2.0/exec-library-abortio.md)  Attempt to abort an I/O request that is in       |
 |                     progress.                                        |
 |______________________________________________________________________|


             Table 19-5: Exec Support Functions in amiga.lib
  ______________________________________________________________________
 |                                                                      |
 |        Function                   Description                        |
 |======================================================================|
 |          [BeginIO()](autodocs-2.0/amiga-lib-beginio.md)  Initiate an asynchronous device I/O request.     |
 |      [CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md)  Create an [IORequest](libraries/19-accessing-a-device-creating-an-i-o-request.md) data structure.              |
 |      [DeleteExtIO()](autodocs-2.0/amiga-lib-deleteextio.md)  Free an IORequest structure allocated by         |
 |                     CreateExtIO().                                   |
 |______________________________________________________________________|

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [CheckIO — exec.library](../autodocs/exec.library.md#checkio)
- [CloseDevice — exec.library](../autodocs/exec.library.md#closedevice)
- [CreateIORequest — exec.library](../autodocs/exec.library.md#createiorequest)
- [DeleteIORequest — exec.library](../autodocs/exec.library.md#deleteiorequest)
- [DoIO — exec.library](../autodocs/exec.library.md#doio)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
- [SendIO — exec.library](../autodocs/exec.library.md#sendio)
- [WaitIO — exec.library](../autodocs/exec.library.md#waitio)
