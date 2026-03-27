---
title: 14 / Commands for Low-Level Access / Writing Raw Data To A Disk
manual: devices
chapter: devices
section: 14-commands-for-low-level-access-writing-raw-data-to-a-disk
functions: []
libraries: []
---

# 14 / Commands for Low-Level Access / Writing Raw Data To A Disk

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

ETD_RAWWRITE and [TD_RAWWRITE](autodocs-2.0/trackdisk-device-td-rawwrite.md) perform a raw write to a track on the disk.
They seek to the specified track and write it from the user's buffer.

No processing of the track is done. It will be written exactly as the bits
come out of the buffer - typically in some legal flux format (such as
MFM, FM, GCR; if you don't know what these are, you shouldn't be using
this call). Caveat Programmer.

This interface is intended for sophisticated programming only. You must
fully understand digital magnetic recording to be able to utilize this
call. It is also important that you understand that the MFM encoding
scheme used by the higher level trackdisk routines may change without
notice. Thus, this routine is only really useful for encoding and writing
other disk formats such as MS-DOS disks.

You write raw data to a disk by passing an [IOExtTD](devices/14-trackdisk-device-device-interface.md) to the device with
[TD_RAWWRITE](autodocs-2.0/trackdisk-device-td-rawwrite.md) or ETD_RAWWRITE set in io_Command, the number of bytes to be
written set in io_Length (maximum 32K), a pointer to the write buffer set
in io_Data, and io_Offset set to the byte offset of the track where you
want to the write to begin.  For ETD_RAWWRITE, you must also set
iotd_Count to the current diskchange number.

  DiskIO->iotd_Req.io_Length = 1024;         /* number of bytes to write */
  DiskIO->iotd_Req.io_Data = (APTR)Writebuffer; /* pointer to buffer */
  DiskIO->iotd_Req.io_Offset = (ULONG)(TRACK_SIZE * track); /* track no. */
  DiskIO->iotd_Req.io_Flags = IOTDF_INDEX      /* Set for index sync */
  DiskIO->iotd_Count = change_count;           /* diskchange number */
  DiskIO->iotd_Req.io_Command = ETD_RAWWRITE;
  DoIO((struct IORequest *)DiskIO);

A raw read may be synched with the index pulse by setting the
IOTDF_INDEXSYNC flag or synched with a $4489 sync pattern by setting the
IOTDF_WORDSYNC flag.  See the "[trackdisk.doc](autodocs-2.0/trackdisk-doc.md)" of the Amiga ROM Kernel
Reference Manual: Includes and Autodocs for more information about these
flags.

