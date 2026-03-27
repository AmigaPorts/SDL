---
title: console.device/CMD_CLEAR
manual: autodocs-3.5
chapter: autodocs-3.5
section: console-device-cmd-clear-2
functions: []
libraries: []
---

# console.device/CMD_CLEAR

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	CMD_CLEAR -- Clear console input buffer.

    FUNCTION
	[Remove](autodocs-3.5/exec-library-remove-2.md) from the console input buffer any reports waiting to
	satisfy read requests.

    IO REQUEST INPUT
	io_Message	mn_ReplyPort set if quick I/O is not possible
	io_Device	preset by the call to [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Unit		preset by the call to [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Command	CMD_CLEAR
	io_Flags	IOB_QUICK set if quick I/O is possible, else 0

    SEE ALSO
	[exec/io.h](autodocs-3.5/include-exec-io-h.md), [devices/console.h](autodocs-3.5/include-devices-console-h.md)

