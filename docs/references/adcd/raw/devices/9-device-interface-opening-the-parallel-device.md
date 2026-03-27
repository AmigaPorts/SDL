# 9 Device Interface / Opening The Parallel Device


Three primary steps are required to open the parallel device:

   *  Create a message port using [CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html). Reply messages from the

      device must be directed to a message port.
   *  Create an extended I/O request structure of type [IOExtPar](../Devices_Manual_guide/node0010.html#line7) using

```c
      [CreateExtIO()](../Includes_and_Autodocs_2._guide/node0147.html). CreateExtIO() will initialize the I/O request to point
      to your reply port.
```
   *  Open the parallel device.  Call [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html),passing the I/O request.

   struct MsgPort  *ParallelMP;         /* Pointer to reply port */
   struct IOExtPar *ParallelIO;         /* Pointer to I/O request */

   if (ParallelMP=CreatePort(0,0) )

```c
      if (ParallelIO=(struct IOExtPar *)
              CreateExtIO(ParallelMP,sizeof(struct IOExtPar)) )
         if (OpenDevice(PARALLELNAME,0L,(struct IORequest *)ParallelIO,0) )
               printf("%s did not open\n",PARALLELNAME);
```
During the open, the parallel device pays attention to just one flag;
PARF_SHARED.  For consistency, the other flag bits should also be properly
set.  Full descriptions of all flags will be given later.  When the
parallel device is opened, it fills the latest default parameter settings
into the [IOExtPar](../Devices_Manual_guide/node0010.html#line7) block.

