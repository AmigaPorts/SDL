# 9 Parallel Device / Device Interface


The parallel device operates like the other Amiga devices.  To use it, you
must first open the parallel device, then send I/O requests to it, and
then close it when finished.  See "[Introduction to Amiga System Devices](../Devices_Manual_guide/node0006.html)"
chapter for general information on device usage.

The I/O request used by the parallel device is called IOExtPar.


```c
    struct   IOExtPar
        {
        struct  IOStdReq IOPar;
        ULONG   io_PExtFlags;   /* additional parallel flags */
        UBYTE   io_Status;      /* status of parallel port and registers */
        UBYTE   io_ParFlags;    /* parallel device flags */
        struct  IOPArray io_PTermArray; /* termination character array */
        };
```
See the include file devices/[parallel.h](../Includes_and_Autodocs_2._guide/node004A.html) for the complete structure
definition.

 [Opening The Parallel Device](../Devices_Manual_guide/node0011.html) 		 [Writing To The Parallel Device](../Devices_Manual_guide/node0013.html) 
 [Reading From The Parallel Device](../Devices_Manual_guide/node0012.html) 	 [Closing The Parallel Device](../Devices_Manual_guide/node0014.html) 

