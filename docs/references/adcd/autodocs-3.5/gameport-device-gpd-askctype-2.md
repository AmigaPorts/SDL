---
title: gameport.device/GPD_ASKCTYPE
manual: autodocs-3.5
chapter: autodocs-3.5
section: gameport-device-gpd-askctype-2
functions: []
libraries: []
---

# gameport.device/GPD_ASKCTYPE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GPD_ASKCTYPE -- Acquire the current game port controller type

   FUNCTION
	This command identifies the type of controller at the game
	port, so that the signals at the port may be properly
	interpreted.  The controller type has been set by a previous
	SetCType.

	This command always executes immediately.

   IO REQUEST
	io_Message	mn_ReplyPort set if quick I/O is not possible
	io_Device	preset by the call to [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Unit		preset by the call to [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Command	GPD_ASKCTYPE
	io_Flags	IOB_QUICK set if quick I/O is possible
	io_Length	at least 1
	io_Data		the address of the byte variable for the
			result

