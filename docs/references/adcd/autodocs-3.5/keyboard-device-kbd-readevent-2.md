---
title: keyboard.device/KBD_READEVENT
manual: autodocs-3.5
chapter: autodocs-3.5
section: keyboard-device-kbd-readevent-2
functions: []
libraries: []
---

# keyboard.device/KBD_READEVENT

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	KBD_READEVENT -- Return the next keyboard event.

   FUNCTION
	[Read](autodocs-3.5/dos-library-read-2.md) raw keyboard events from the keyboard and put them in the
	data area of the iORequest.  If there are no pending keyboard
	events, this command will not be satisfied, but if there are
	some events, but not as many as can fill IO_LENGTH, the
	request will be satisfied with those currently available.

   IO REQUEST
	io_Message	mn_ReplyPort set if quick I/O is not possible
	io_Device	preset by the call to [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Command	KBD_READEVENT
	io_Flags	IOB_QUICK set if quick I/O is possible
	io_Length	the size of the io_Data area in bytes: there
			are sizeof(inputEvent) bytes per input event.
	io_Data		a buffer area to fill with input events.  The
			fields of the input event are:
	    ie_NextEvent
			links the events returned
	    ie_Class
			is IECLASS_RAWKEY
	    ie_Code
			contains the next key up/down reports
	    ie_Qualifier
			only the shift and numeric pad bits are set
	    ie_SubClass, ie_X, ie_Y, ie_TimeStamp
			are not used, and set to zero

   RESULTS
	This function sets the error field in the [IORequest](autodocs-3.5/include-exec-io-h.md), and fills
	the [IORequest](autodocs-3.5/include-exec-io-h.md) with the next keyboard events (but not partial
	events).

