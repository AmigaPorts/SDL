# 14 / Advanced Commands / Determining The Drive Geometry Table


The layout geometry of a disk drive can be determined by using the
[TD_GETGEOMETRY](../Includes_and_Autodocs_2._guide/node0529.html) command.  The layout can be defined three ways:

   *  TotalSectors

   *  Cylinders and CylSectors

   *  Cylinders, Heads, and TrackSectors.

Of the three, TotalSectors is the most accurate, Cylinders and CylSectors
is less so, and Cylinders, Heads and TrackSectors is the least accurate.
All are usable, though the last two may waste some portion of the
available space on some drives.

The [TD_GETGEOMETRY](../Includes_and_Autodocs_2._guide/node0529.html) commands returns the disk layout geometry in a
DriveGeometry structure:


```c
    struct DriveGeometry
    {
        ULONG dg_SectorSize;      /* in bytes */
        ULONG dg_TotalSectors;    /* total # of sectors on drive */
        ULONG dg_Cylinders;       /* number of cylinders */
        ULONG dg_CylSectors;      /* number of sectors/cylinder */
        ULONG dg_Heads;           /* number of surfaces */
        ULONG dg_TrackSectors;    /* number of sectors/track */
        ULONG dg_BufMemType;      /* preferred buffer memory type */
                                  /* (usually MEMF_PUBLIC) */
        UBYTE dg_DeviceType;      /* codes as defined in the SCSI-2 spec*/
        UBYTE dg_Flags;           /* flags, including removable */
        UWORD dg_Reserved;
    };
```
See the include file devices/[trackdisk.h](../Includes_and_Autodocs_2._guide/node005B.html) for the complete structure
definition and values for the dg_DeviceType and dg_Flags fields.

You determine the drive layout geometry by passing an [IOExtTD](../Devices_Manual_guide/node00DE.html#line12) with
[TD_GETGEOMETRY](../Includes_and_Autodocs_2._guide/node0529.html) set in io_Command and a pointer to a DriveGeometry
structure set in io_Data.

   struct DriveGeometry *Euclid;

   Euclid = (struct DriveGeometry *)

```c
             AllocMem(sizeof(struct DriveGeometry),
                      MEMF_PUBLIC | MEMF_CLEAR);
```
   DiskIO->iotd_Req.io_Data = Euclid;     /* put layout geometry here */
   DiskIO->iotd_Req.io_Command = TD_GETGEOMETRY;
   DoIO((struct IORequest *)DiskIO);

For V36 and higher versions of the operating system, [TD_GETGEOMETRY](../Includes_and_Autodocs_2._guide/node0529.html) is
preferred over [TD_GETNUMTRACKS](../Includes_and_Autodocs_2._guide/node052A.html) for determining the number of tracks on a
disk.  This is because new drive types may have more sectors or different
sector sizes, etc., than standard Amiga drives.

