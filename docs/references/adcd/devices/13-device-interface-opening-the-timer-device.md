---
title: 13 / Device Interface / Opening The Timer Device
manual: devices
chapter: devices
section: 13-device-interface-opening-the-timer-device
functions: [AllocMem, OpenDevice]
libraries: [exec.library]
---

# 13 / Device Interface / Opening The Timer Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Three primary steps are required to open the timer device:

   *  Create a message port using [CreatePort()](autodocs-2.0/amiga-lib-createport.md). Reply messages from the

      device must be directed to a message port.
   *  Create an I/O request structure of type [timerequest](devices/13-timer-device-device-interface.md) using

```c
      [CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md).
```
   *  Open the timer device with one of the five timer device units. Call

```c
      [OpenDevice()](autodocs-2.0/exec-library-opendevice.md) passing a pointer to the  [timerequest](devices/13-timer-device-device-interface.md).
```
   struct MsgPort *TimerMP;   /* Message port pointer */
   struct timerequest *TimerIO;  /* I/O structure pointer */

     /* Create port for timer device communications */
   if (!(TimerMP = CreatePort(0,0)))
```c
       cleanexit(" Error: Can't create port\n",RETURN_FAIL);

     /* Create message block for device IO */
```
   if (!(TimerIO = (struct timerequest *)
```c
                   CreateExtIO(TimerMP)(sizeof timerequest)) )
       cleanexit(" Error: Can't create IO request\n",RETURN_FAIL);

     /* Open the timer device with UNIT_MICROHZ */
```
   if (error=OpenDevice(TIMERNAME,UNIT_MICROHZ,TimerIO,0))

```c
       cleanexit(" Error: Can't open Timer.device\n",RETURN_FAIL);
```
The procedure for applications which only use the timer device functions
is slightly different:

   *  Declare the timer device base address variable TimerBase in the

      global data area.
   *  Allocate memory for a [timerequest](devices/13-timer-device-device-interface.md) structure and a  [timeval](devices/13-timer-device-device-interface.md) structure

```c
      using [AllocMem()](autodocs-2.0/exec-library-allocmem.md).
```
   *  Call [OpenDevice()](autodocs-2.0/exec-library-opendevice.md), passing the allocated [timerequest](devices/13-timer-device-device-interface.md) structure.

   *  Set the timer device base address variable to point to the timer

      device base.
   struct Library *TimerBase;  /* global library pointer */

   struct timerequest *TimerIO;
   struct timeval *time1;

     /* Allocate memory for timerequest and timeval structures */
   TimerIO=(struct timerequest *)AllocMem(sizeof(struct timerequest),
```c
                                  MEMF_PUBLIC | MEMF_CLEAR);
```
   time1=(struct timeval *)AllocMem(sizeof(struct timeval),
```c
                                  MEMF_PUBLIC | MEMF_CLEAR);
```
   if (!TimerIO | !time1)

```c
       cleanexit(" Error: Can't allocate memory for I/O structures\n",
                          RETURN_FAIL);
```
   if (error=OpenDevice(TIMERNAME,UNIT_MICROHZ,TimerIO,0))
```c
       cleanexit(" Error: Can't open Timer.device\n",RETURN_FAIL);

     /* Set up pointer for timer functions */
```
   TimerBase = (struct Library *)TimerIO->tr_node.io_Device;

---

## See Also

- [AllocMem — exec.library](../autodocs/exec.library.md#allocmem)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
