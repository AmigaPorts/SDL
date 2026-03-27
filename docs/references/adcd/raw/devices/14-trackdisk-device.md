# 14 Trackdisk Device


The Amiga trackdisk device directly drives the disk, controls the disk
motors, reads raw data from the tracks, and writes raw data to the tracks.
Normally, you use the AmigaDOS functions to write or read data from the
disk. The trackdisk device is the lowest-level software access to the disk
data and is used by AmigaDOS to access the disks.  The trackdisk device
supports the usual commands such as [CMD_WRITE](../Devices_Manual_guide/node00E2.html) and [CMD_READ](../Devices_Manual_guide/node00E1.html).  In addition,
it supports an extended form of these commands to allow additional control
over the trackdisk device.


```c
                    NEW FEATURES FOR VERSION 2.0

                    Feature            Description
                --------------       --------------
                [TD_GETGEOMETRY](../Devices_Manual_guide/node00E5.html)       Device Command
                [TD_EJECT](../Devices_Manual_guide/node00EA.html)             Device Command
                IOTF_INDEXSYNC       Device Command Flag
                IOTF_WORDSYNC        Device Command Flag
                Fast RAM Buffers     Now Supported
```
   Compatibility Warning:
   ----------------------
   The new features for 2.0 are not backwards compatible.

 [Trackdisk Device Commands and Functions](../Devices_Manual_guide/node00DD.html) 
 [Device Interface](../Devices_Manual_guide/node00DE.html) 
 [Advanced Commands](../Devices_Manual_guide/node00E4.html) 
 [Disk Status Commands](../Devices_Manual_guide/node00EB.html) 
 [Commands for Diagnostics and Repair](../Devices_Manual_guide/node00F1.html) 
 [Notification of Disk Changes](../Devices_Manual_guide/node00F3.html) 
 [Commands for Low-Level Access](../Devices_Manual_guide/node00F6.html) 
 [Trackdisk Device Errors](../Devices_Manual_guide/node00FA.html) 
 [Example Trackdisk Program](../Devices_Manual_guide/node019C.html) 
 [Additional Information on the Trackdisk Device](../Devices_Manual_guide/node00FB.html) 

