# 5 Gameport Device / Device Interface


The gameport device operates like the other Amiga devices.  To use it, you
must first open the gameport device, then send I/O requests to it, and
then close it when finished. See the "[Introduction to Amiga System Devices](../Devices_Manual_guide/node0006.html)"
chapter for general information on device usage.

The I/O request used by the gameport device is called IOStdReq.


```c
    struct IOStdReq
    {
        struct  Message io_Message;
        struct  Device  *io_Device; /* device node pointer  */
        struct  Unit    *io_Unit; /* unit (driver private)*/
        UWORD   io_Command;       /* device command */
        UBYTE   io_Flags;
        BYTE    io_Error;         /* error or warning num */
        ULONG   io_Actual;        /* actual number of bytes transferred */
        ULONG   io_Length;        /* requested number bytes transferred*/
        APTR    io_Data;          /* points to data area */
        ULONG   io_Offset;        /* offset for block structured devices */
    };
```
See the include file exec/[io.h](../Includes_and_Autodocs_2._guide/node0094.html) for the complete structure definition.

 [Opening The Gameport Device](../Devices_Manual_guide/node00B1.html) 
 [Gameport Device Controllers](../Devices_Manual_guide/node00B2.html) 
 [Closing The Gameport Device](../Devices_Manual_guide/node00B3.html) 

