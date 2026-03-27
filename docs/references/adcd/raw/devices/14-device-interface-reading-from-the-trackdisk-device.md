# 14 / Device Interface / Reading From The Trackdisk Device


You read from the trackdisk device by passing an [IOExtTD](../Devices_Manual_guide/node00DE.html#line12) to the device
with [CMD_READ](../Includes_and_Autodocs_2._guide/node0520.html) set in io_Command, the number of bytes to be read set in
io_Length, the address of the read buffer set in io_Data and the track you
want to read - specified as a byte offset from the start of the disk - set
in io_Offset.

The byte offset of a particular track is calculated by multiplying the
number of the track you want to read by the number of bytes in a track.
The number of bytes in a track is obtained by multiplying the number of
sectors (NUMSECS) by the number of bytes per sector (TD_SECTOR). Thus you
would multiply 11 by 512 to get 5632 bytes per track. To read track 15,
you would multiply 15 by 5632 giving 84,480 bytes offset from the
beginning of the disk.


```c
    #define TRACK_SIZE ((LONG) (NUMSECS * TD_SECTOR))
    UBYTE *Readbuffer;
    SHORT tracknum;

    if (Readbuffer = AllocMem(TRACK_SIZE,MEMF_CLEAR|MEMF_CHIP))
        {
        DiskIO->iotd_Req.io_Length = TRACK_SIZE;
        DiskIO->iotd_Req.io_Data = (APTR)Readbuffer;
        DiskIO->iotd_Req.io_Offset = (ULONG)(TRACK_SIZE * track);
        DiskIO->iotd_Req.io_Command = CMD_READ;
        DoIO((struct IORequest *)DiskIO);
        }
```
For reads using the enhanced read command ETD_READ, the [IOExtTD](../Devices_Manual_guide/node00DE.html#line12) is set the
same as above with the addition of setting iotd_Count to the current
diskchange number.  The diskchange number is returned by the [TD_CHANGENUM](../Includes_and_Autodocs_2._guide/node0524.html)
command ([see below](../Devices_Manual_guide/node00F0.html)).  If you wish to also read the sector label area, you
must set iotd_SecLabel to a non-NULL value.


```c
    DiskIO->iotd_Req.io_Length = TRACK_SIZE;
    DiskIO->iotd_Req.io_Data = (APTR)Readbuffer;
    DiskIO->iotd_Req.io_Offset = (ULONG)(TRACK_SIZE * track);
    DiskIO->iotd_Count = change_count;
    DiskIO->iotd_Req.io_Command = ETD_READ;
    DoIO((struct IORequest *)DiskIO);
```
ETD_READ and [CMD_READ](../Includes_and_Autodocs_2._guide/node0520.html) obey all of the trackdisk device restrictions noted
above. They transfer data from the track buffer to the user's buffer. If
the desired sector is already in the track buffer, no disk activity is
initiated. If the desired sector is not in the buffer, the track
containing that sector is automatically read in. If the data in the
current track buffer has been modified, it is written out to the disk
before a new track is read.

