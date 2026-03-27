---
title: 14 / / Adding A Diskchange Software Interrupt Handler
manual: devices
chapter: devices
section: 14-adding-a-diskchange-software-interrupt-handler
functions: [Cause, SendIO]
libraries: [exec.library]
---

# 14 / / Adding A Diskchange Software Interrupt Handler

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The trackdisk device lets you add a software interrupt handler that will
be Cause()'ed when a disk insert or remove occurs.   Within the handler,
you may only call the status commands that can use IOF_QUICK.

You add a software interrupt handler by passing an [IOExtTD](devices/14-trackdisk-device-device-interface.md) to the device
with a pointer to an Interrupt structure set in io_Data, the length of the
structure set in io_Length and [TD_ADDCHANGEINT](autodocs-2.0/trackdisk-device-td-addchangeint.md) set in io_Command.

   DiskIO->iotd_Req.io_Length = sizeof(struct Interrupt)
   DiskIO->iotd_Req.io_Data   = (APTR)Disk_Interrupt;
   DiskIO->iotd_Req.io_Command = TD_ADDCHANGEINT;
   SendIO((struct IORequest *)DiskIO);

   Going, going, gone.
   -------------------
   This command does not return when executed. It holds onto the
   IORequest until the [TD_REMCHANGEINT](autodocs-2.0/trackdisk-device-td-remchangeint.md) command is executed with that
   same IORequest.  Hence, you must use SendIO() with this command.

---

## See Also

- [Cause — exec.library](../autodocs/exec.library.md#cause)
- [SendIO — exec.library](../autodocs/exec.library.md#sendio)
