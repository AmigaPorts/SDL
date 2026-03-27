# 3 Clipboard Device / Device Interface


The clipboard device operates like the other Amiga devices.  To use it,
you must first open the clipboard device, then send I/O requests to it,
and then close it when finished. See "[Introduction to Amiga System Devices](../Devices_Manual_guide/node0006.html)"
chapter for general information on device usage.

  struct IOClipReq
  {
```c
      struct  Message io_Message;
      struct  Device  *io_Device;     /* device node pointer  */
      struct  Unit    *io_Unit;       /* unit (driver private)*/
      UWORD   io_Command;             /* device command */
      UBYTE   io_Flags;               /* including QUICK and SATISFY */
      BYTE    io_Error;               /* error or warning num */
      ULONG   io_Actual;              /* number of bytes transferred */
      ULONG   io_Length;              /* number of bytes requested */
      STRPTR  io_Data;                /* either clip stream or post port */
      ULONG   io_Offset;              /* offset in clip stream */
      LONG    io_ClipID;              /* ordinal clip identifier */
```
  };

See the include file devices/[clipboard.h](../Includes_and_Autodocs_2._guide/node0048.html) for the complete
structure definition.

The clipboard device I/O request, IOClipReq, looks like a standard
IORequest structure except for the addition of the io_ClipID field, which
is used by the device to identify clips. It must be set to zero by the
application for a post or an initial write or read, but preserved for
subsequent writes or reads, as the clipboard device uses this field
internally for bookkeeping purposes.

 [Opening The Clipboard Device](../Devices_Manual_guide/node0068.html)        [Updating The Clipboard Device](../Devices_Manual_guide/node006C.html) 
 [Clipboard Data](../Devices_Manual_guide/node0069.html) 		     [Clipboard Messages](../Devices_Manual_guide/node006D.html) 
 [Multiple Clips](../Devices_Manual_guide/node006A.html) 		     [Reading From The Clipboard Device](../Devices_Manual_guide/node006E.html) 
 [Writing To The Clipboard Device](../Devices_Manual_guide/node006B.html)     [Closing The Clipboard Device](../Devices_Manual_guide/node006F.html) 

