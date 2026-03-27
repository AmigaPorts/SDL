---
title: 14 Trackdisk Device / Trackdisk Device Errors
manual: devices
chapter: devices
section: 14-trackdisk-device-trackdisk-device-errors
functions: []
libraries: []
---

# 14 Trackdisk Device / Trackdisk Device Errors

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The trackdisk device returns error codes whenever an operation is
attempted.


```c
    DiskIO->iotd_Req.io_Length = TRACK_SIZE;
    DiskIO->iotd_Req.io_Data = (APTR)Writebuffer;
    DiskIO->iotd_Req.io_Offset = (ULONG)(TRACK_SIZE * tracknum);
    DiskIO->iotd_Count = change_count;
    DiskIO->iotd_Req.io_Command = ETD_WRITE;
    if (DoIO((struct IORequest *)DiskIO))
        printf("ETD_WRITE failed.  Error: %ld\n",DiskIO-iotd.io_Error);
```
When an error occurs, these error numbers will be returned in the io_Error
field of your [IOExtTD](devices/14-trackdisk-device-device-interface.md) block.

              TRACKDISK DEVICE ERROR CODES

        Error       Value         Explanation
------------------  ----- -----------------------------
TDERR_NotSpecified   20   Error could not be determined
TDERR_NoSecHdr       21   Could not find sector header
TDERR_BadSecPreamble 22   Error in sector preamble
TDERR_BadSecID       23   Error in sector identifier
TDERR_BadHdrSum      24   Header field has bad checksum
TDERR_BadSecSum      25   Sector data field has bad checksum
TDERR_TooFewSecs     26   Incorrect number of sectors on track
TDERR_BadSecHdr      27   Unable to read sector header
TDERR_WriteProt      28   Disk is write-protected
TDERR_DiskChanged    29   Disk has been changed or is not currently present
TDERR_SeekError      30   While verifying seek position, found seek error
TDERR_NoMem          31   Not enough memory to do this operation
TDERR_BadUnitNum     32   Bad unit number (unit # not attached)
TDERR_BadDriveType   33   Bad drive type (not an Amiga 3 1/2 inch disk)
TDERR_DriveInUse     34   Drive already in use (only one task exclusive)
TDERR_PostReset      35   User hit reset; awaiting doom

