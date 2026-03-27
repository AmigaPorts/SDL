---
title: narrator.device/CMD_STOP
manual: autodocs-3.5
chapter: autodocs-3.5
section: narrator-device-cmd-stop-2
functions: []
libraries: []
---

# narrator.device/CMD_STOP

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CMD_STOP  - Stops the device.


   SYNOPSIS
	Standard device command.


   FUNCTION
	CMD_STOP halts the currently active speech (if any) and	prevents
	any queued requests from starting.


   INPUTS
	Valid [IORequest](autodocs-3.5/include-exec-io-h.md) block with the io_Command field set to CMD_STOP.
	A valid [IORequest](autodocs-3.5/include-exec-io-h.md) block is one with its io_Message structure, and
	io_Device and io_Unit fields properly initialized.  The easiest
	way to insure proper initialization is to make a copy of the
	[IORequest](autodocs-3.5/include-exec-io-h.md) block after a successful [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md) call.


   RESULTS
	io_Error set to 0.


   SEE ALSO
	Exec input/output documentation.

