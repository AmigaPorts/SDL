# 14 Trackdisk Device / Device Interface


The trackdisk device operates like other Amiga devices.  To use it, you
must first open the device, then send I/O requests to it, and then close
it when finished.  See the "[Introduction to Amiga System Devices](../Devices_Manual_guide/node0006.html)"
chapter for general information on device usage.

The trackdisk device uses two different types of I/O request blocks,
IOStdReq and IOExtTD and two types of commands, standard and extended.
An IOExtTD is required for the extended trackdisk commands (those
beginning with "ETD_"), but can be used for both types of commands.
Thus, the IOExtTD is the type of I/O request that will be used in this
chapter.


```c
    struct IOExtTD
    {
        struct  IOStdReq iotd_Req;
        ULONG   iotd_Count;         /* Diskchange counter */
        ULONG   iotd_SecLabel;      /* Sector label data */
    };
```
See the include file devices/[trackdisk.h](../Includes_and_Autodocs_2._guide/node005B.html) for the complete structure
definition.

The enhanced commands listed above - those beginning with "ETD_" - are
similar to their standard counterparts but have additional features: they
allow you to control whether a command will be executed if the disk has
been changed and they allow you to read or write to the sector label
portion of a sector.

Enhanced commands require a larger I/O request, IOExtTD, than the IOStdReq
request used by the standard commands.  IOExtTD contains extra information
needed by the enhanced command; since the standard form of a command
ignores the extra fields, IOExtTD requests can be used for both types. The
extra information takes the form of two extra longwords at the end of the
data structure.  These commands are performed only if the change count is
less than or equal to the value in the iotd_Count field of the command's
request block.

The iotd_Count field keeps old I/O requests from being performed when the
disk is changed.  Any request found with an iotd_Count less than the
current change counter value will be returned with a characteristic error
(TDERR_DiskChange) in the io_Error field. This allows stale I/O requests
to be returned to the user after a disk has been changed. The current
disk-change counter value can be obtained by [TD_CHANGENUM](../Includes_and_Autodocs_2._guide/node0524.html).  If the user
wants enhanced disk I/O but does not care about disk removal, then
iotd_Count may be set to the maximum unsigned long integer value
(0xFFFFFFFF).

The iotd_SecLabel field allows access to the sector identification section
of the sector header. Each sector has 16 bytes of descriptive data space
available to it; the trackdisk device does not interpret this data.  If
iotd_SecLabel is NULL, then this descriptive data is ignored.  If it is
not NULL, then iotd_SecLabel should point to a series of contiguous
16-byte chunks (one for each sector that is to be read or written).  These
chunks will be written out to the sector's label region on a write or
filled with the sector's label area on a read.  If a [CMD_WRITE](../Includes_and_Autodocs_2._guide/node0522.html) (the
standard write call) is done, then the sector label area is left unchanged.

 [About Amiga Floppy Disks](../Devices_Manual_guide/node00DF.html) 		 [Writing To The Trackdisk Device](../Devices_Manual_guide/node00E2.html) 
 [Opening The Trackdisk Device](../Devices_Manual_guide/node00E0.html) 		 [Closing The Trackdisk Device](../Devices_Manual_guide/node00E3.html) 
 [Reading From The Trackdisk Device](../Devices_Manual_guide/node00E1.html) 

