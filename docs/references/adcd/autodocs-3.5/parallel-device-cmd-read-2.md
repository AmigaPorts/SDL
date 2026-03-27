---
title: parallel.device/CMD_READ
manual: autodocs-3.5
chapter: autodocs-3.5
section: parallel-device-cmd-read-2
functions: []
libraries: []
---

# parallel.device/CMD_READ

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	[Read](autodocs-3.5/dos-library-read-2.md) -- read input from parallel port

   FUNCTION
	This command causes a stream of characters to be read from the
	parallel I/O register. The number of characters is specified in
	io_Length. The EOF and EOL modes are supported, but be warned that
	using these modes can result in a buffer overflow if the proper
	EOL or EOF character is not received in time. These modes should
	be used only when the sender and receiver have been designed to
	cooperate. A safety guard can be implemented to EOF by setting
	io_Length to a maximum allowed value. That cannot be done with EOL
	since the EOL mode is identified by io_Length=-1.

	The parallel.device has no internal buffer; if no read request has
	been made, pending input (i.e. handshake request) is not
	acknowledged.

   IO REQUEST
	io_Message      mn_ReplyPort initialized
	io_Device       set by [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Unit         set by [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Command      CMD_READ (02)
	io_Flags        If IOF_QUICK is set, driver will attempt Quick IO
	io_Length       number of characters to receive.
	io_Data         pointer where to put the data.

   RESULTS
	io_Error -- if the [Read](autodocs-3.5/dos-library-read-2.md) succeded, then io_Error will be null.
	    If the [Read](autodocs-3.5/dos-library-read-2.md) failed, then io_Error will contain an error code.

   SEE ALSO
	[parallel.device/PDCMD_SETPARAMS](autodocs-3.5/parallel-device-pdcmd-setparams-2.md)

