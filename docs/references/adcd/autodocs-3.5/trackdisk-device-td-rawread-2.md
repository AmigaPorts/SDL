---
title: trackdisk.device/TD_RAWREAD
manual: autodocs-3.5
chapter: autodocs-3.5
section: trackdisk-device-td-rawread-2
functions: [OpenDevice]
libraries: [exec.library]
---

# trackdisk.device/TD_RAWREAD

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	TD_RAWREAD/ETD_RAWREAD -- read raw data from the disk.

   FUNCTION
	These commands read a track of raw data from disk and deposits it in
	the provided buffer. The data is taken straight from the disk with
	no processing done on it. It will appear exactly as the bits come out
	off the disk, hopefully in some legal MFM format.

	This interface is intended for sophisticated programmers only.
	Amiga reserves the right to make enhancements to the disk
	format in the future. We will provide compatibility via the
	[CMD_READ](autodocs-3.5/trackdisk-device-cmd-read-2.md) and ETD_READ commands, anyone using TD_RAWREAD is
	bypassing this upwards compatibility, and may thus stop working.

   IO REQUEST INPUT
	io_Device	preset by the call to [OpenDevice()](autodocs-3.5/serial-device-opendevice-2.md)
	io_Unit		preset by the call to [OpenDevice()](autodocs-3.5/serial-device-opendevice-2.md)
	io_Command      TD_RAWREAD or ETD_RAWREAD.
	io_Flags	if the IOTDB_INDEXSYNC bit is set then the driver
			will make a best effort attempt to start reading
			from the index mark.  Note that there will be at
			least some delay, and perhaps a great deal of delay
			(for example if interrupts have been disabled).
	io_Length	Length of buffer in bytes, with a maximum of 32768
			bytes.
	io_Data		Pointer to CHIP memory buffer where raw track data is
			to be deposited.
	io_Offset	The number of the track to read in.
	iotd_Count	(ETD_RAWREAD only) maximum allowable change counter
			value.

   IO REQUEST RESULT
	io_Error - 0 for success, or an error code as defined in
	           [<devices/trackdisk.h>](autodocs-3.5/include-devices-trackdisk-h.md)

   NOTES
	The track buffer provided MUST be in CHIP memory

	There is a delay between the index pulse and the start of bits
	coming in from the drive (e.g. dma started). This delay
	is in the range of 135-200 microseconds. This delay breaks
	down as follows: 55 microsecs is software interrupt overhead
	(this is the time from interrupt to the write of the DSKLEN
	register). 66 microsecs is one horizontal line delay (remember
	that disk IO is synchronized with agnus' display fetches).
	The last variable (0-65 microsecs) is an additional scan line
	since DSKLEN is poked anywhere in the horizontal line. This leaves
	15 microsecs unaccounted for...  Sigh.

	In short, You will almost never get bits within the first 135
	microseconds of the index pulse, and may not get it until 200
	microseconds. At 4 microsecs/bit, this works out to be between
	4 and 7 bytes of user data of delay.

   BUGS
	This command does not work reliably under versions of Kickstart
	earlier than V36, especially on systems with 1 floppy drive.

   SEE ALSO
	[TD_RAWWRITE](autodocs-3.5/trackdisk-device-td-rawwrite-2.md)

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
