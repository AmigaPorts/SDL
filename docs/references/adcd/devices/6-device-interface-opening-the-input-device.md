---
title: 6 / Device Interface / Opening The Input Device
manual: devices
chapter: devices
section: 6-device-interface-opening-the-input-device
functions: [OpenDevice]
libraries: [exec.library]
---

# 6 / Device Interface / Opening The Input Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Three primary steps are required to open the input device:

   *  Create a message port using [CreatePort()](autodocs-2.0/amiga-lib-createport.md). Reply messages from the

      device must be directed to a message port.
   *  Create an I/O request structure of type [IOStdReq](devices/6-input-device-device-interface.md) or [timerequest](devices/6-input-device-device-interface.md). The

```c
      I/O request created by the [CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md) function will be used to
      pass commands and data to the input device.
```
   *  Open the Input device.  Call [OpenDevice()](autodocs-2.0/exec-library-opendevice.md), passing the I/O request.

   struct MsgPort  *InputMP;   /* Message port pointer */
   struct IOStdReq *InputIO;   /* I/O request pointer */

   if (InputMP=CreatePort(0,0) )

```c
       if (InputIO=(struct IOStdReq *)
                    CreateExtIO(InputMP,sizeof(struct IOStdReq)) )
           if (OpenDevice("input.device",0L,(struct IORequest *)InputIO,0))
               printf("input.device did not open\n");
```
The above code will work for all the input device commands except for the
ones which require a time specification.  For those, the code would look
like this:

   #include <devices/timer.h>

   struct MsgPort  *InputMP;      /* Message port pointer */
   struct timerequest *InputIO;   /* I/O request pointer */

   if (InputMP=CreatePort(0,0) )

```c
       if (InputIO=(struct timerequest *)
                    CreateExtIO(InputMP,sizeof(struct timerequest)) )
           if (OpenDevice("input.device",0L,(struct IORequest *)InputIO,0))
               printf("input.device did not open\n");
```

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
