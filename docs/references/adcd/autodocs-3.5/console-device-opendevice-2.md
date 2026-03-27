---
title: console.device/OpenDevice
manual: autodocs-3.5
chapter: autodocs-3.5
section: console-device-opendevice-2
functions: []
libraries: []
---

# console.device/OpenDevice

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	OpenDevice -- a request to open a Console device

    SYNOPSIS
	error = OpenDevice("console.device", unit, [IOStdReq](autodocs-3.5/include-exec-io-h.md), flags )
	d0		    a0               d0    a1        d1

    FUNCTION
	The open routine grants access to a device.  There are two
	fields in the [IOStdReq](autodocs-3.5/include-exec-io-h.md) block that will be filled in: the
	io_Device field and possibly the io_Unit field.

	As of (V37) the flags field may also be filled in with
	a value described below (see conunit.h or conunit.i).

	This open command differs from most other device open commands
	in that it requires some information to be supplied in the
	io_Data field of the [IOStdReq](autodocs-3.5/include-exec-io-h.md) block.  This initialization
	information supplies the window that is used by the console
	device for output.

	The unit number that is a standard parameter for an open call
	is used specially by this device.  See conunit.h, or conunit.i
	for defined valid unit numbers.


	unit number: -1 (CONU_LIBRARY)

		Used to get a pointer to the device library vector
	which is returned in the io_Device field of the [IOStdReq](autodocs-3.5/include-exec-io-h.md)
	block.  No actual console is opened.  You must still close
	the device when you are done with it.

	unit number: 0 (CONU_STANDARD)

		A unit number of zero binds the supplied window to
	a unique console.  Sharing a console must be done at a level
	higher than the device.


	unit number: 1 (CONU_CHARMAP) (V36)

		A unit number of one is similar to a unit number of
	zero, but a console map is also created, and maintained by
	the console.device.  The character map is used by the console
	device to restore obscured portions of windows which are
	revealed, and to redraw a window after a resize.  Character
	mapped console.device windows must be opened as SIMPLE REFRESH
	windows.

		The character map is currently for internal use
	only, and is not accessible by the programmer.  The character
	map stores characters, attributes, and style information for
	each character written with the [CMD_WRITE](autodocs-3.5/console-device-cmd-write-2.md) command.

	unit number: 3 (CONU_SNIPMAP) (V36)

		A unit number of three is similar to a unit number
	of one, but also gives the user the ability to highlight
	text with the mouse which can be copied by pressing
	RIGHT AMIGA C.  See NOTES below.


	flags: 0 (CONFLAG_DEFAULT)

		The flags field should be set to 0 under V34, or less.

	flags: 1 (CONFLAG_NODRAW_ON_NEWSIZE) (V37)

		The flags field can be set to 0, or 1 as of V37.  The
	flags field is ignored under V36, so can be set, though it
	will have no effect.  When set to 1, it means that you don't
	want the console.device to redraw the window when the window
	size is changed (assuming you have opened the console.device
	with a character map - unit numbers 1, or 3).  This flag is
	ignored if you have opened a console.device with a unit
	number of 0.  Typically you would use this flag when you
	want to perform your own window refresh on a newsize, and
	you want the benefits of a character mapped console.

    IO REQUEST
	io_Data		struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *window
			This is the window that will be used for this
			console.  It must be supplied if the unit in
			the OpenDevice call is 0 (see above).  The
			RPort of this window is potentially in use by
			the console whenever there is an outstanding
			write command.
    INPUTS
	"console.device" - a pointer to the name of the device to be opened.
	unit - the unit number to open on that device.
	[IOStdReq](autodocs-3.5/include-exec-io-h.md) - a pointer to a standard request block
	0 - a flag field of zero (CONFLAG_DEFAULT)
	1 - a flag field of one  (CONFLAG_NODRAW_ON_NEWSIZE) (V37)

    RESULTS
	error - zero if successful, else an error is returned.

    NOTES
	As noted above, opening the console.device with a unit number of 3
	allows the user to drag select text, and copy the selection with
	RIGHT AMIGA C.  The snip is copied to a private buffered managed
	by the console.device (as of V36).  The snip can be copied to
	any console.device window unless you are running a console to
	clipboard utility such as that provided with V37.

	The user pastes text into console.device windows by pressing
	RIGHT AMIGA V.  Both RIGHT AMIGA V, and RIGHT AMIGA C are swallowed
	by the console.device (unless you have asked for key presses as
	RAW INPUT EVENTS).  [Text](autodocs-3.5/graphics-library-text-2.md) pasted in this way appears in the
	console read stream as if the user had typed all of the characters
	manually.  Additional input (e.g., user input, RAW INPUT EVENTS)
	are queued up after pastes.  Pastes can theoretically be quite
	large, though they are no larger than the amount of text
	which is visible in a console.device window.

	When running the console to clipboard utility, text snips
	are copied to the clipboard.device, and RIGHT AMIGA V key
	presses are broadcast as an escape sequence as part of the
	console.device read stream ("<CSI>0 v" - $9B,$30,$20,$76).

	It is left up to the application to decide what to do when this
	escape sequence is received.  Ideally the application
	will read the contents of the clipboard, and paste the text
	by using successive writes to the console.device.

	Because the contents of the clipboard.device can be quite
	large, your program should limit the size of writes to something
	reasonable (e.g., no more than 1K characters per [CMD_WRITE](autodocs-3.5/console-device-cmd-write-2.md), and
	ideally no more than 256 characters per write).  Your program
	should continue to read events from the console.device looking
	for user input, and possibly RAW INPUT EVENTS.  How you decide
	to deal with these events is left up to the application.

	If you are using a character mapped console you should receive
	Intuition events as RAW INPUT EVENTS from the console.device.
	By doing this you will hear about these events after the console
	device does.  This allows the console.device to deal with events
	such as window resizing, and refresh before your application.

    BUGS

    SEE ALSO
	[exec/io.h](autodocs-3.5/include-exec-io-h.md), [intuition/intuition.h](autodocs-3.5/include-intuition-intuition-h.md)

