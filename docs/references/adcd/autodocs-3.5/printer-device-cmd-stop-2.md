---
title: printer.device/CMD_STOP
manual: autodocs-3.5
chapter: autodocs-3.5
section: printer-device-cmd-stop-2
functions: []
libraries: []
---

# printer.device/CMD_STOP

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CMD_STOP -- pause current and queued I/O requests (immediate)

   FUNCTION
	CMD_STOP pauses all queued requests for the unit, and tries to
	pause the current I/O request.  The only commands that will
	be subsequently allowed to be performed are immediate I/O
	requests, which include those to start, flush, and finish the
	I/O after the stop command.

   IO REQUEST
	io_Message	mn_ReplyPort set if quick I/O is not possible
	io_Device	preset by the call to [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Command	CMD_STOP
	io_Flags	IOB_QUICK set if quick I/O is possible

