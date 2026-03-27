---
title: 11 / Device Interface / Opening The SCSI Device
manual: devices
chapter: devices
section: 11-device-interface-opening-the-scsi-device
functions: [OpenDevice]
libraries: [exec.library]
---

# 11 / Device Interface / Opening The SCSI Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Three primary steps are required to open the SCSI device:

   *  Create a message port using [CreatePort()](autodocs-2.0/amiga-lib-createport.md). Reply messages from the

      device must be directed to a message port.
   *  Create an I/O request structure of type [IOStdReq](devices/11-scsi-device-device-interface.md). The IOStdReq

```c
      structure is created by the [CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md) function. [CreateExtIO](autodocs-2.0/amiga-lib-createextio.md) will
      initialize your IOStdReq to point to your reply port.
```
   *  Open the SCSI device.  Call [OpenDevice()](autodocs-2.0/exec-library-opendevice.md) passing it the I/O request

      and the SCSI unit encoded in the unit field.
SCSI unit encoding consists of three decimal digits which refer
to the SCSI Target ID (bus address) in the 1s digit, the SCSI logical unit
(LUN) in the 10s digit, and the controller board in the 100s digit.  For
example:

   SCSI unit    Meaning
   ---------    -------
   6            drive at address 6
   12           LUN 1 on multiple drive controller at address 2
   104          second controller board, address 4
   88           not valid: both logical units and addresses range from 0-7

The Commodore 2090/2090A unit numbers are encoded differently.  The SCSI
logical unit (LUN) is in the 100s digit, and the SCSI Target ID is a
permuted 1s digit: Target ID 0-6 maps to unit 3-9 (7 is reserved for the
controller).

   2090/A unit  Meaning
   ----------   -------
   3            drive at address 0
   109          drive at address 6, logical unit 1
   1            not valid: this is not a SCSI unit.Perhaps it's an ST506

                unit.
Some controller boards generate a unique name for the second controller
board, instead of implementing the 100s digit (e.g., the 2090A's
iddisk.device).


```c
    struct MsgPort *SCSIMP;      /* Message port pointer */
    struct IOStdReq *SCSIIO;     /* IORequest pointer */

        /* Create message port */
    if (!(SCSIMP = CreatePort(NULL,NULL)))
        cleanexit("Can't create message port\n",RETURN_FAIL);

        /* Create IORequest */
    if (!(SCSIIO = CreateExtIO(SCSIMP,sizeof(struct IOStdReq))))
        cleanexit("Can't create IORequest\n",RETURN_FAIL);

        /* Open the SCSI device */
    if (error = OpenDevice("scsi.device",6L,SCSIIO,0L))
        cleanexit("Can't open scsi.device\n",RETURN_FAIL);
```
In the code above, the SCSI unit at address 6 of logical unit 0 of board 0
is opened.

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
