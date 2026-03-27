---
title: 14 / Device Interface / Opening The Trackdisk Device
manual: devices
chapter: devices
section: 14-device-interface-opening-the-trackdisk-device
functions: [OpenDevice]
libraries: [exec.library]
---

# 14 / Device Interface / Opening The Trackdisk Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Three primary steps are required to open the trackdisk device:

   *  Create a message port by calling [CreatePort()](autodocs-2.0/amiga-lib-createport.md). Reply messages from

      the device must be directed to a message port.
   *  Create an extended I/O request structure of type [IOExtTD](devices/14-trackdisk-device-device-interface.md).  The

```c
      [IOExtTD](devices/14-trackdisk-device-device-interface.md) structure is created by the [CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md) function.
```
   *  Open the trackdisk device.  Call [OpenDevice()](autodocs-2.0/exec-library-opendevice.md), passing it the

      extended I/O request.
For the trackdisk device, the flags parameter of the [OpenDevice()](autodocs-2.0/exec-library-opendevice.md) function
specifies whether you are opening a 3.5" drive (flags=0) or a 5.25" drive
(flags=1).  With flags set to 0 trackdisk will only open a 3.5" drive.  To
tell the device to open any drive it understands, set the flags parameter
to TDF_ALLOW_NON_3_5.  (See the include file devices/[trackdisk.h](autodocs-2.0/includes-devices-trackdisk-h.md) for more
information.)

   #include <devices/trackdisk.h>

   struct MsgPort *TrackMP;         /* Pointer for message port */
   struct IOExtTD *TrackIO;         /* Pointer for IORequest */

   if (TrackMP=CreatePort(0,0) )

```c
       if (TrackIO=(struct IOExtTD *)
              CreateExtIO(TrackMP,sizeof(struct IOExtTD)) )
           if (OpenDevice(TD_NAME,0L,(struct IORequest *)TrackIO,Flags) )
               printf("%s did not open\n",TD_NAME);
```
   Disk Drive Unit Numbers.
   ------------------------
   The unit number - second parameter of the [OpenDevice()](autodocs-2.0/exec-library-opendevice.md) call - can be
   any value from 0 to 3.  Unit 0 is the built-in 3.5" disk drive.
   Units 1 through 3 represent additional disk drives that may be
   connected to an Amiga system.

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
