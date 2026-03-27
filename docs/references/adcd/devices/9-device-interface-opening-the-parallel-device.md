---
title: 9 Device Interface / Opening The Parallel Device
manual: devices
chapter: devices
section: 9-device-interface-opening-the-parallel-device
functions: [OpenDevice]
libraries: [exec.library]
---

# 9 Device Interface / Opening The Parallel Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Three primary steps are required to open the parallel device:

   *  Create a message port using [CreatePort()](autodocs-2.0/amiga-lib-createport.md). Reply messages from the

      device must be directed to a message port.
   *  Create an extended I/O request structure of type [IOExtPar](devices/9-parallel-device-device-interface.md) using

```c
      [CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md). CreateExtIO() will initialize the I/O request to point
      to your reply port.
```
   *  Open the parallel device.  Call [OpenDevice()](autodocs-2.0/exec-library-opendevice.md),passing the I/O request.

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
into the [IOExtPar](devices/9-parallel-device-device-interface.md) block.

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
