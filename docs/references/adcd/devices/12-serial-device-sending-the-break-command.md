---
title: 12 Serial Device / Sending the Break Command
manual: devices
chapter: devices
section: 12-serial-device-sending-the-break-command
functions: []
libraries: []
---

# 12 Serial Device / Sending the Break Command

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You send a break through the serial device by passing an [IOExtSer](devices/12-serial-device-device-interface.md) to the
device with [SDCMD_BREAK](autodocs-2.0/serial-device-sdcmd-break.md) set in io_Command.  The break may be immediate or
queued.  The choice is determined by the state of flag [SERF_QUEUEDBRK](devices/12-setting-serial-parameters-serial-flags-bits-for-io.md) in
io_SerFlags.

   SerialIO->IOSer.io_Command  = SDCMD_BREAK; /* send break */
   SendIO((struct IORequest *)SerialIO);

The duration of the break (in microseconds) can be set in io_BrkTime. The
default is 250,000 microseconds (.25 seconds).

