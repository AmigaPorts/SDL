---
title: narrator.device/CMD_RESET
manual: autodocs-3.5
chapter: autodocs-3.5
section: narrator-device-cmd-reset-2
functions: []
libraries: []
---

# narrator.device/CMD_RESET

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CMD_RESET - Reset the device to a known state


   SYNOPSIS
	Standard device command.


   FUNCTION
	Resets the device as though it has just be initialized.
	Aborts all read/write requests whether active of enqueued.
	Restarts device if it has been stopped.


   INPUTS
	Valid [IORequest](autodocs-3.5/include-exec-io-h.md) block with the io_Command field set to CMD_RESET.
	A valid [IORequest](autodocs-3.5/include-exec-io-h.md) block is one with its io_Message structure, and
	io_Device and io_Unit fields properly initialized.  The easiest
	way to insure proper initialization is to make a copy of the
	[IORequest](autodocs-3.5/include-exec-io-h.md) block after a successful [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md) call.


   RESULTS


   SEE ALSO
	Exec input/output documentation.

