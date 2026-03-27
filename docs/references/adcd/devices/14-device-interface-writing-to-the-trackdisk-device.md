---
title: 14 / Device Interface / Writing To The Trackdisk Device
manual: devices
chapter: devices
section: 14-device-interface-writing-to-the-trackdisk-device
functions: []
libraries: []
---

# 14 / Device Interface / Writing To The Trackdisk Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You write to the trackdisk device by passing an [IOExtTD](devices/14-trackdisk-device-device-interface.md) to the device with
[CMD_WRITE](autodocs-2.0/trackdisk-device-cmd-write.md) set in io_Command, the number of bytes to be written set in
io_Length, the address of the write buffer set in io_Data and the track
you want to write - specified as a byte offset from the start of the
disk - set in io_Offset.


```c
    #define TRACK_SIZE ((LONG) (NUMSECS * TD_SECTOR))
    UBYTE *Writebuffer;

    if (Writebuffer = AllocMem(TRACK_SIZE,MEMF_CLEAR|MEMF_PUBLIC))
        {
        DiskIO->iotd_Req.io_Length = TRACK_SIZE;
        DiskIO->iotd_Req.io_Data = (APTR)Writebuffer;
        DiskIO->iotd_Req.io_Offset = (ULONG)(TRACK_SIZE * tracknum);
        DiskIO->iotd_Req.io_Command = CMD_WRITE;
        DoIO((struct IORequest *)DiskIO);
        }
```
For writes using the enhanced write command ETD_WRITE, the [IOExtTD](devices/14-trackdisk-device-device-interface.md) is set
the same as above with the addition of setting iotd_Count to the current
diskchange number.  The diskchange number is returned by the [TD_CHANGENUM](autodocs-2.0/trackdisk-device-td-changenum.md)
command ([see below](devices/14-disk-status-commands-determining-the-current-diskchange.md)).  If you wish to also write the sector label area, you
must set iotd_SecLabel to a non-NULL value.


```c
    DiskIO->iotd_Req.io_Length = TRACK_SIZE;
    DiskIO->iotd_Req.io_Data = (APTR)Writebuffer;
    DiskIO->iotd_Req.io_Offset = (ULONG)(TRACK_SIZE * tracknum);
    DiskIO->iotd_Count = change_count;
    DiskIO->iotd_Req.io_Command = ETD_WRITE;
    DoIO((struct IORequest *)DiskIO);
```
ETD_WRITE and [CMD_WRITE](autodocs-2.0/trackdisk-device-cmd-write.md) obey all of the trackdisk device restrictions
noted above. They transfer data from the user's buffer to the track
buffer. If the track that contains this sector is already in the track
buffer, no disk activity is initiated. If the desired sector is not in the
buffer, the track containing that sector is automatically read in. If the
data in the current track buffer has been modified, it is written out to
the disk before a new track is read in for modification.

