---
title: narrator.device/CMD_WRITE
manual: autodocs-3.5
chapter: autodocs-3.5
section: narrator-device-cmd-write-2
functions: []
libraries: []
---

# narrator.device/CMD_WRITE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CMD_WRITE - Send speech request to the narrator device


   SYNOPSIS
	Standard device command.


   FUNCTION
	Sends a phonetic string to the narrator device to be spoken
	and, optionally, is used to direct the narrator device to
	return mouth shape changes, and word and syllable sync events
	in response to read requests from the user.  The phonetic string
	consists of ASCII characters representing the individual phonemes.
	Refer to the narrator device chapter of the libraries and devices
	volume of the ROM Kernel Manual for detailed information.


   INPUTS
	User [IORequest](autodocs-3.5/include-exec-io-h.md) block (struct [narrator_rb](autodocs-3.5/include-devices-narrator-h.md) as defined in .h file).
	The [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md) call will initialize the [IORequest](autodocs-3.5/include-exec-io-h.md) block to a
	"standard male" voice.  If you want to change any parms, do so
	after the [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md) call and before the [DoIO](autodocs-3.5/exec-library-doio-2.md) (or SendIO/WaitIO).
	For a complete description of the [narrator_rb](autodocs-3.5/include-devices-narrator-h.md) structure, see the
	narrator.h or .i include file.  Note that the [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md) call does
	not initialize all the fields needed by the narrator device.  The
	[IORequest](autodocs-3.5/include-exec-io-h.md) fields which must be set by the user before issuing the
	write request are:

	   io_Command - Set to CMD_WRITE
	   io_Data    - Pointer to phonetic string
	   io_Length  - Length of phonetic string
	   ch_masks   - Array of audio channel selection masks (see audio
			device documentation for description of this field)
	   nm_masks   - Number of audio channel selection masks

	   ****** NEW FOR V37 NARRATOR

	   flags - The bit NDB_NEWIORB must be set in the flags field if
		   any of the new features of the V37 narrator are used


	In addition to producing synthetic speech, the narrator device
	also provides features for synchronizing the speech to animation
	or other user defined events.  There are three types of events
	that the user can request.  They are mouth shape changes, start of
	new word, and start of new syllable.  Mouth shape changes are
	requested by setting the mouths field of the [IORequest](autodocs-3.5/include-exec-io-h.md) block to a
	non-zero value.  Word and syllable sync events are requested by
	setting the NDB_WORDSYNC and/or NDB_SYLSYNC bits in the flags field
	of the [IORequest](autodocs-3.5/include-exec-io-h.md) block.  Note that word and syllable sync only work
	in V37 and later versions of the narrator device.


   RESULTS
	The narrator device range checks and performs other validity
	checks for all input parms.  If any input is in error, the device
	sets the io_Error field of the [IORequest](autodocs-3.5/include-exec-io-h.md) block to an appropriate
	value (see include files for error codes).  If everything is in
	order, the narrator device will produce the speech and clear the
	io_Error field.  The io_Actual field is set to the length of the
	input string that was actually processed.  If the return code
	indicates a phoneme error (ND_PhonErr), io_Actual is the NEGATIVE
	of the position in the input string where the error occured.


   SEE ALSO
	[Read](autodocs-3.5/dos-library-read-2.md) command.
	Audio device documentation.
	Exec input/output documentation.

