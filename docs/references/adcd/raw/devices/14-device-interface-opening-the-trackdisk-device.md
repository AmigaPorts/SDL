# 14 / Device Interface / Opening The Trackdisk Device


Three primary steps are required to open the trackdisk device:

   *  Create a message port by calling [CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html). Reply messages from

      the device must be directed to a message port.
   *  Create an extended I/O request structure of type [IOExtTD](../Devices_Manual_guide/node00DE.html#line12).  The

```c
      [IOExtTD](../Devices_Manual_guide/node00DE.html#line12) structure is created by the [CreateExtIO()](../Includes_and_Autodocs_2._guide/node0147.html) function.
```
   *  Open the trackdisk device.  Call [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html), passing it the

      extended I/O request.
For the trackdisk device, the flags parameter of the [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html) function
specifies whether you are opening a 3.5" drive (flags=0) or a 5.25" drive
(flags=1).  With flags set to 0 trackdisk will only open a 3.5" drive.  To
tell the device to open any drive it understands, set the flags parameter
to TDF_ALLOW_NON_3_5.  (See the include file devices/[trackdisk.h](../Includes_and_Autodocs_2._guide/node005B.html) for more
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
   The unit number - second parameter of the [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html) call - can be
   any value from 0 to 3.  Unit 0 is the built-in 3.5" disk drive.
   Units 1 through 3 represent additional disk drives that may be
   connected to an Amiga system.

