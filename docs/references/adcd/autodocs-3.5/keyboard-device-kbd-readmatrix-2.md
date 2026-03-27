---
title: keyboard.device/KBD_READMATRIX
manual: autodocs-3.5
chapter: autodocs-3.5
section: keyboard-device-kbd-readmatrix-2
functions: []
libraries: []
---

# keyboard.device/KBD_READMATRIX

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	KBD_READMATRIX -- [Read](autodocs-3.5/dos-library-read-2.md) the current keyboard key matrix.

   FUNCTION
	This function reads the up/down state of every key in the
	key matrix.

   IO REQUEST INPUT
	io_Message	mn_ReplyPort set if quick I/O is not possible
	io_Device	preset by the call to [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Command	KBD_READMATRIX
	io_Flags	IOB_QUICK set if quick I/O is possible
	io_Length	the size of the io_Data area in bytes: this
			must be big enough to hold the key matrix.
	io_Data		a buffer area to fill with the key matrix:
			an array of bytes whose component bits reflect
			each keys state: the state of the key for
			keycode n is at bit (n MOD 8) in byte
			(n DIV 8) of this matrix.

   IO REQUEST OUTPUT
	io_Error
	     IOERR_BADLENGTH - the io_Length was not exactly 13 bytes.
			The buffer is unchanged.  This is only returned
			by V33/V34 kickstart.
	io_Actual	the number of bytes filled in io_Data with key
			matrix data, i.e. the minimum of the supplied
			length and the internal key matrix size.

   NOTE
	For V33/V34 Kickstart, io_Length must be set to exactly 13 bytes.

   RESULTS
	This function sets the error field in the [IORequest](autodocs-3.5/include-exec-io-h.md), and sets
	matrix to the current key matrix.

