---
title: 14 / Advanced Commands / Formatting A Track
manual: devices
chapter: devices
section: 14-advanced-commands-formatting-a-track
functions: []
libraries: []
---

# 14 / Advanced Commands / Formatting A Track

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

ETD_FORMAT and [TD_FORMAT](autodocs-2.0/trackdisk-device-td-format.md) are used to write data to a track that either has
not yet been formatted or has had a hard error on a standard write
command. TD_FORMAT completely ignores all data currently on a track and
does not check for disk change before performing the command. The device
will format the requested tracks, filling each sector with the contents of
the buffer pointed to by io_Data field. You should do a read pass to
verify the data.

If you have a hard write error during a normal write, you may find it
possible to use the [TD_FORMAT](autodocs-2.0/trackdisk-device-td-format.md) command to reformat the track as part of
your error recovery process. ETD_FORMAT will write the sector label area
if the iotd_SecLabel is non-NULL.

You format a track by passing an [IOExtTD](devices/14-trackdisk-device-device-interface.md) to the device with TD_FORMAT or
ETD_FORMAT set in io_Command, io_Data set to at least track worth of data,
io_Offset field set to the byte offset of the track you want to write and
the io_Length set to the length of a track. For ETD_FORMAT, you must also
set iotd_Count to the current diskchange number.


```c
    #define TRACK_SIZE ((LONG) (NUMSECS * TD_SECTOR))
    UBYTE *Writebuffer;

    if (WriteBuffer = AllocMem(TRACK_SIZE,MEMF_CLEAR|MEMF_CHIP))
        {
        DiskIO->iotd_Req.io_Length=TRACK_SIZE;
        DiskIO->iotd_Req.io_Data=(APTR)Writebuffer;
        DiskIO->iotd_Req.io_Offset=(ULONG)(TRACK_SIZE * track);
        DiskIO->iotd_Req.io_Command = TD_FORMAT;
        DoIO((struct IORequest *)DiskIO);
        }
```
