---
title: parallel.device/CMD_CLEAR
manual: autodocs-3.5
chapter: autodocs-3.5
section: parallel-device-cmd-clear-2
functions: []
libraries: []
---

# parallel.device/CMD_CLEAR

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	Clear -- clear the parallel port buffer

   FUNCTION
	This command just RTS's (no buffer to clear)

   IO REQUEST
	io_Message      mn_ReplyPort initialized
	io_Device       set by [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Unit         set by [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Command      CMD_CLEAR (05)

