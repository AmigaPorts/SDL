---
title: console.device/CD_ASKDEFAULTKEYMAP
manual: autodocs-3.5
chapter: autodocs-3.5
section: console-device-cd-askdefaultkeymap-2
functions: []
libraries: []
---

# console.device/CD_ASKDEFAULTKEYMAP

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	CD_ASKDEFAULTKEYMAP -- get the current default keymap

    FUNCTION
	Fill the io_Data buffer with the current console device
	default keymap, which is used to initialize console unit
	keymaps when opened, and by [RawKeyConvert](autodocs-3.5/console-device-rawkeyconvert-2.md) with a null
	keyMap parameter.

   IO REQUEST
	io_Message	mn_ReplyPort set if quick I/O is not possible
	io_Device	preset by the call to [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Unit		preset by the call to [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Command	CD_ASKDEFAULTKEYMAP
	io_Flags	IOF_QUICK if quick I/O possible, else zero
	io_Length	sizeof(*keyMap)
	io_Data		struct [KeyMap](autodocs-3.5/include-devices-keymap-h.md) *keyMap
			pointer to a structure that describes
			the raw keycode to byte stream conversion.

    RESULTS
	This function sets the io_Error field in the [IOStdReq](autodocs-3.5/include-exec-io-h.md), and fills
	the structure pointed to by io_Data with the current device
	default key map.

    BUGS

    SEE ALSO
	[exec/io.h](autodocs-3.5/include-exec-io-h.md), [devices/keymap.h](autodocs-3.5/include-devices-keymap-h.md), [devices/console.h](autodocs-3.5/include-devices-console-h.md)

