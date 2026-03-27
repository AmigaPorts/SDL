---
title: console.device/CD_SETDEFAULTKEYMAP
manual: autodocs-3.5
chapter: autodocs-3.5
section: console-device-cd-setdefaultkeymap-2
functions: []
libraries: []
---

# console.device/CD_SETDEFAULTKEYMAP

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	CD_SETDEFAULTKEYMAP -- set the current default keymap

    FUNCTION
	This console command copies/uses the keyMap structure pointed to
	by io_Data to the console device default keymap, which is used
	to initialize console units when opened, and by [RawKeyConvert](autodocs-3.5/console-device-rawkeyconvert-2.md)
	with a null keyMap parameter.

    IO REQUEST
	io_Message	mn_ReplyPort set if quick I/O is not possible
	io_Device	preset by the call to [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Unit		preset by the call to [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Command	CD_SETDEFAULTKEYMAP
	io_Flags	IOF_QUICK if quick I/O possible, else zero
	io_Length	sizeof(*keyMap)
	io_Data		struct [KeyMap](autodocs-3.5/include-devices-keymap-h.md) *keyMap
			pointer to a structure that describes
			the raw keycode to byte stream conversion.

    RESULTS
	This function sets the io_Error field in the [IOStdReq](autodocs-3.5/include-exec-io-h.md), and fills
	the current device default key map from the structure pointed to
	by io_Data.

    BUGS
	As of V36, this command no longer copies the keymap structure,
	and the keymap must remain in memory until the default key map
	is changed.  In general there is no reason for applications to
	use this command.  The default key map will generally be set by
	the user using a system provided command/tool.

    SEE ALSO
	[exec/io.h](autodocs-3.5/include-exec-io-h.md), [devices/keymap.h](autodocs-3.5/include-devices-keymap-h.md), [devices/console.h](autodocs-3.5/include-devices-console-h.md)

