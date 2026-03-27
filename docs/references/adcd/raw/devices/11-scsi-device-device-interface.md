# 11 SCSI Device / Device Interface


The SCSI device operates like other Amiga devices.  To use it, you must
first open the SCSI device, then send I/O requests to it, and then close
it when finished.  See the "[Introduction to Amiga System Devices](../Devices_Manual_guide/node0006.html)"
chapter for general information on device usage.

The power of the SCSI device comes from its special facility for passing
SCSI and SCSI-2 command blocks to any SCSI unit on the bus.  This facility
is commonly called SCSI-direct and it allows the Amiga to perform SCSI
functions that are "non-standard" in terms of the normal Amiga I/O model.

To send SCSI-direct or other commands to the SCSI device, an extended I/O
request structure named IOStdReq is used.

   struct IOStdReq
   {
```c
       struct  Message io_Message;
       struct  Device  *io_Device;/* device node pointer  */
       struct  Unit    *io_Unit;  /* unit (driver private)*/
       UWORD   io_Command;        /* device command */
       UBYTE   io_Flags;
       BYTE    io_Error;          /* error or warning num */
       ULONG   io_Actual;         /* actual number of bytes transferred */
       ULONG   io_Length;         /* requested number bytes transferred*/
       APTR    io_Data;           /* points to data area */
       ULONG   io_Offset;         /* offset for block structured devices */
```
   };

See the include file exec/[io.h](../Includes_and_Autodocs_2._guide/node0094.html) for the complete structure definition.

 [Opening The SCSI Device](../Devices_Manual_guide/node0076.html) 
 [Closing The SCSI Device](../Devices_Manual_guide/node0077.html) 

