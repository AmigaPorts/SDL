---
title: 14 / Commands for Low-Level Access / Reading Raw Data From A Disk
manual: devices
chapter: devices
section: 14-commands-for-low-level-access-reading-raw-data-from-a
functions: []
libraries: []
---

# 14 / Commands for Low-Level Access / Reading Raw Data From A Disk

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

ETD_RAWREAD and [TD_RAWREAD](autodocs-2.0/trackdisk-device-td-rawread.md) perform a raw read from a track on the disk.
They seek to the specified track and read it into the user's buffer.

No processing of the track is done. It will appear exactly as the bits
come off the disk - typically in some legal flux format (such as MFM, FM,
GCR, etc; if you don't know what these are, you shouldn't be using this
call). Caveat programmer.

This interface is intended for sophisticated programming only. You must
fully understand digital magnetic recording to be able to utilize this
call. It is also important that you understand that the MFM encoding
scheme used by the higher level trackdisk routines may change without
notice. Thus, this routine is only really useful for reading and decoding
other disks such as MS-DOS formatted disks.

You read raw data from a disk by passing an [IOExtTD](devices/14-trackdisk-device-device-interface.md) to the device with
[TD_RAWREAD](autodocs-2.0/trackdisk-device-td-rawread.md) or ETD_RAWREAD set in io_Command, the number of bytes to be
read set in io_Length (maximum 32K), a pointer to the read buffer set in
io_Data, and io_Offset set to the byte offset of the track where you want
to the read to begin.  For ETD_RAWREAD, you must also set iotd_Count to
the current diskchange number.

  DiskIO->iotd_Req.io_Length = 1024;          /* number of bytes to read */
  DiskIO->iotd_Req.io_Data = (APTR)Readbuffer; /* pointer to buffer */
  DiskIO->iotd_Req.io_Offset = (ULONG)(TRACK_SIZE * track); /* track no. */
  DiskIO->iotd_Req.io_Flags = IOTDF_INDEX      /* Set for index sync */
  DiskIO->iotd_Count = change_count;           /* diskchange number */
  DiskIO->iotd_Req.io_Command = ETD_RAWREAD;
  DoIO((struct IORequest *)DiskIO);

A raw read may be synched with the index pulse by setting the
IOTDF_INDEXSYNC flag or synched with a $4489 sync pattern by setting the
IOTDF_WORDSYNC flag.  See the "[trackdisk.doc](autodocs-2.0/trackdisk-doc.md)" of the Amiga ROM Kernel
Reference Manual: Includes and Autodocs for more information about these
flags.

   Forewarned is Forearmed.
   ------------------------
   Amiga, Inc. may make enhancements to the disk format in the
   future. Amiga, Inc. intends to provide compatibility within the
   trackdisk device.  Anyone who uses these raw routines is bypassing
   this upward-compatibility and does so at her own risk.

