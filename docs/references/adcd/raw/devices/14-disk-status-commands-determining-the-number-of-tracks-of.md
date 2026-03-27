# 14 / Disk Status Commands / Determining The Number Of Tracks Of A Drive


You determine the number of a tracks of a drive by passing an [IOExtTD](../Devices_Manual_guide/node00DE.html#line12) to
the device with [TD_GETNUMTRACKS](../Includes_and_Autodocs_2._guide/node052A.html) set in io_Command.  For quick I/O, you
must set io_Flags to IOF_QUICK.


```c
    DiskIO->iotd_Req.io_Flags = IOF_QUICK;
    DiskIO->iotd_Req.io_Command = TD_GETNUMTRACKS;
    BeginIO((struct IORequest *)DiskIO);
```
[TD_GETNUMTRACKS](../Includes_and_Autodocs_2._guide/node052A.html) returns the number of tracks on that device in io_Actual.
This is the number of tracks of TD_SECTOR * NUMSECS size. It is not the
number of cylinders. With two heads, the number of cylinders is half of
the number of tracks.  The number of cylinders is equal to the number of
tracks divided by the number of heads (surfaces).  The standard 3.5" Amiga
drive has two heads

[TD_GETGEOMETRY](../Includes_and_Autodocs_2._guide/node0529.html) is the preferred over [TD_GETNUMTRACKS](../Includes_and_Autodocs_2._guide/node052A.html) for V36 and higher
versions of the operating system especially since new drive types may have
more sectors or different sector sizes, etc., than standard Amiga drives.

