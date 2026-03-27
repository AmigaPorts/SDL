---
title: parallel.device/CMD_STOP
manual: autodocs-3.5
chapter: autodocs-3.5
section: parallel-device-cmd-stop-2
functions: []
libraries: []
---

# parallel.device/CMD_STOP

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	Stop -- pause current activity on the parallel device

   FUNCTION
	This command halts the current I/O activity on the parallel
	device by discontinuing the handshaking sequence. The stop and
	start commands may not be nested.

   IO REQUEST
	io_Message      mn_ReplyPort initialized
	io_Device       set by [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Unit         set by [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Command      CMD_STOP (06)

   SEE ALSO
	[parallel.device/CMD_START](autodocs-3.5/parallel-device-cmd-start-2.md)

