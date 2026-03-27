# 14 Trackdisk Device / Trackdisk Device Commands and Functions


Command          Operation
--------         ----------
[CMD_CLEAR](../Devices_Manual_guide/node00E6.html)        Mark track buffer as invalid. Forces the track to be
ETD_CLEAR        re-read.  ETD_CLEAR also checks for a diskchange.

[CMD_READ](../Devices_Manual_guide/node00E1.html)         Read one or more sectors from a disk.  ETD_READ also
[ETD_READ](../Devices_Manual_guide/node00E1.html#line24)         reads the sector label area and checks for a diskchange.

[CMD_UPDATE](../Devices_Manual_guide/node00E8.html)       Write out track buffer if it has been changed. ETD_UPDATE
ETD_UPDATE       also checks for a diskchange.

[CMD_WRITE](../Devices_Manual_guide/node00E2.html)        Write one or more sectors to a disk.  ETD_WRITE also
[ETD_WRITE](../Devices_Manual_guide/node00E2.html#line18)        writes the sector label area and checks for a diskchange.

[TD_ADDCHANGEINT](../Devices_Manual_guide/node00F4.html)  Add an interrupt handler to be activated on a diskchange.

[TD_CHANGENUM](../Devices_Manual_guide/node00F0.html)     Return the current value of the diskchange counter used

                 by the ETD commands to determine if a diskchange has
                 occurred.
[TD_CHANGESTATE](../Devices_Manual_guide/node00EC.html)   Return the disk present/not-present status of a drive.

[TD_EJECT](../Devices_Manual_guide/node00EA.html)         Eject a disk from a drive.  This command will only work

```c
                 on drives that support an eject command (V36).
```
[TD_FORMAT](../Devices_Manual_guide/node00E9.html)        Initialize one or more tracks with a data buffer.
ETD_FORMAT       ETD_FORMAT also initializes the sector label area.

[TD_GETDRIVETYPE](../Devices_Manual_guide/node00EE.html)  Return the type of disk drive in use by the unit.

[TD_GETGEOMETRY](../Devices_Manual_guide/node00E5.html)   Return the disk geometry table (V36).

[TD_GETNUMTRACKS](../Devices_Manual_guide/node00EF.html)  Return the number of tracks usable with the unit.

[TD_MOTOR](../Devices_Manual_guide/node00E7.html)         Turn the motor on or off.  ETD_MOTOR also checks for a
ETD_MOTOR        diskchange.

[TD_PROTSTATUS](../Devices_Manual_guide/node00ED.html)    Return the write-protect status of a disk.

[TD_RAWREAD](../Devices_Manual_guide/node00F7.html)       Read RAW sector data from disk (unencoded MFM).
[ETD_RAWREAD](../Devices_Manual_guide/node00F7.html)      ETD_RAWREAD also checks for a diskchange.

[TD_RAWWRITE](../Devices_Manual_guide/node00F8.html)      Write RAW sector data to disk.  ETD_RAWWRITE also checks
[ETD_RAWWRITE](../Devices_Manual_guide/node00F8.html)     for a diskchange.

[TD_REMCHANGEINT](../Devices_Manual_guide/node00F5.html)  Remove a diskchange interrupt handler.

[TD_SEEK](../Devices_Manual_guide/node00F2.html)          Move the head to a specific track.  ETD_SEEK also checks

                 for a
[ETD_SEEK](../Devices_Manual_guide/node00F2.html)         diskchange.


Exec Functions as Used in This Chapter
--------------------------------------
[AbortIO()](../Includes_and_Autodocs_2._guide/node0323.html)        Abort a command to the trackdisk device.

BeginIO()        Initiate a command and return immediately (asynchronous

```c
                 request).
```
[CloseDevice()](../Includes_and_Autodocs_2._guide/node033F.html)    Relinquish use of a disk unit.

[DoIO()](../Includes_and_Autodocs_2._guide/node034B.html)           Initiate a command and wait for completion (synchronous

```c
                 request).
```
[OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html)     Obtain exclusive use of a particular disk unit.


Exec Support Functions as Used in This Chapter
----------------------------------------------
[CreateExtIO()](../Includes_and_Autodocs_2._guide/node0147.html)    Create an extended I/O request structure of type [IOExtTD](../Devices_Manual_guide/node00DE.html#line12).

                 This structure will be used to communicate commands to
                 the trackdisk device.
[CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html)     Create a signal message port for reply messages from the

                 trackdisk device.  Exec will signal a task when a message
                 arrives at the reply port.
[DeleteExtIO()](../Includes_and_Autodocs_2._guide/node0152.html)    Delete an I/O request structure created by [CreateExtIO()](../Includes_and_Autodocs_2._guide/node0147.html).

[DeletePort()](../Includes_and_Autodocs_2._guide/node0153.html)     Delete the message port created by [CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html).

