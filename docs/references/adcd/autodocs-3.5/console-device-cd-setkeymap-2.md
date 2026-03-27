---
title: console.device/CD_SETKEYMAP
manual: autodocs-3.5
chapter: autodocs-3.5
section: console-device-cd-setkeymap-2
functions: []
libraries: []
---

# console.device/CD_SETKEYMAP

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	CD_SETKEYMAP -- set the current key map structure for this console

    FUNCTION
	Set the current [KeyMap](autodocs-3.5/include-devices-keymap-h.md) structure used by this console unit to
	the structure pointed to by io_Data.

    IO REQUEST
	io_Message	mn_ReplyPort set if quick I/O is not possible
	io_Device	preset by the call to [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Unit		preset by the call to [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Command	CD_SETKEYMAP
	io_Flags	IOF_QUICK if quick I/O possible, else zero
	io_Length	sizeof(*keyMap)
	io_Data		struct [KeyMap](autodocs-3.5/include-devices-keymap-h.md) *keyMap
			pointer to a structure that describes
			the raw keycode to byte stream conversion.

    RESULTS
	This function sets the io_Error field in the [IOStdReq](autodocs-3.5/include-exec-io-h.md), and fills
	the current key map from the structure pointed to by io_Data.

    BUGS

    SEE ALSO
	[exec/io.h](autodocs-3.5/include-exec-io-h.md), [devices/keymap.h](autodocs-3.5/include-devices-keymap-h.md), [devices/console.h](autodocs-3.5/include-devices-console-h.md)

