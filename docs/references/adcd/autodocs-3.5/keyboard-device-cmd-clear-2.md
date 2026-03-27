---
title: keyboard.device/CMD_CLEAR
manual: autodocs-3.5
chapter: autodocs-3.5
section: keyboard-device-cmd-clear-2
functions: []
libraries: []
---

# keyboard.device/CMD_CLEAR

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CMD_CLEAR -- Clear the keyboard input buffer.

   FUNCTION
	[Remove](autodocs-3.5/exec-library-remove-2.md) from the input buffer any keys transitions waiting to
	satisfy read requests.

   IO REQUEST
	io_Message	mn_ReplyPort set if quick I/O is not possible
	io_Device	preset by the call to [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Command	CMD_CLEAR
	io_Flags	IOB_QUICK set if quick I/O is possible

