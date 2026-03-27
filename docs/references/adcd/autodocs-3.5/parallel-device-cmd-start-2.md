---
title: parallel.device/CMD_START
manual: autodocs-3.5
chapter: autodocs-3.5
section: parallel-device-cmd-start-2
functions: []
libraries: []
---

# parallel.device/CMD_START

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	Start -- restart paused I/O over the parallel port

   FUNCTION
	This command restarts the current I/O activity on the parallel
	port by reactivating the handshaking sequence.

   IO REQUEST
	io_Message      mn_ReplyPort initialized
	io_Device       set by [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Unit         set by [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Command      CMD_START (07)

   SEE ALSO
	[parallel.device/CMD_STOP](autodocs-3.5/parallel-device-cmd-stop-2.md)

