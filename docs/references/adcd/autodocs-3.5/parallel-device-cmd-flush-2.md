---
title: parallel.device/CMD_FLUSH
manual: autodocs-3.5
chapter: autodocs-3.5
section: parallel-device-cmd-flush-2
functions: []
libraries: []
---

# parallel.device/CMD_FLUSH

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	[Flush](autodocs-3.5/dos-library-flush-2.md) -- clear all queued I/O requests for the parallel port

   FUNCTION
	This command purges the read and write request queues for the
	parallel device. The currently active request is not purged.

   IO REQUEST
	io_Message      mn_ReplyPort initialized
	io_Device       set by [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Unit         set by [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Command      CMD_FLUSH (08)

