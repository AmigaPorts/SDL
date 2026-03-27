---
title: 1 Introduction to Amiga System Devices / Devices With Functions
manual: devices
chapter: devices
section: 1-introduction-to-amiga-system-devices-devices-with
functions: [OpenDevice]
libraries: [exec.library]
---

# 1 Introduction to Amiga System Devices / Devices With Functions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Some devices, in addition to their commands, provide functions which can
be directly called by applications.  These functions are documented in the
device specific FD files and Autodocs of the Amiga ROM Kernel Reference
Manual: [Includes and Autodocs](autodocs-2.0/includes-and-autodocs-2-0.md) and the device chapters of this manual.

Devices with functions behave much like Amiga libraries, i.e., you set up
a base address pointer and call the functions as offsets from the pointer.
(See the [Exec Libraries](libraries/exec-library.md)" chapter of the Amiga ROM Kernel Reference
Manual: Libraries.)

The procedure for accessing a device's functions is as follows:

   *  Declare the device base address variable in the global data area.

      The name of the base address can be found in the device's FD file.
   *  Create a message port using one of the previously discussed methods

      if you haven't already done so.
   *  Create an I/O request using one of the previously discussed methods

      if you haven't already done so. Remember to set the message port
      pointer in the I/O request if necessary.
   *  Call [OpenDevice()](autodocs-2.0/exec-library-opendevice.md), passing the I/O request if you haven't already

      done so.  When you do this, the device returns a pointer to its base
      address in the io_Device field of the I/O request structure.  Consult
      the include file for the structure you are using to determine the
      full name of the io_Device field.  The base address is only valid
      while the device is open.
   *  Set the device base address variable to the pointer returned in the

      io_Device field.
We will use the timer device to illustrate the above method.  The name of
the timer device base address is listed in its FD file as "TimerBase."

  #include <devices/timer.h>

  struct Library *TimerBase;    /* device base address pointer */

  struct MsgPort *TimerMP;      /* message port pointer */
  struct timerequest *TimerIO;  /* I/O request pointer */

      /* Create the message port */
  if (TimerMP=CreatePort(NULL,NULL))

```c
      {
          /* Create the I/O request */
      if (TimerIO = (struct timerequest *)
          {           CreateExtIO(TimerMP,sizeof(struct timerequest)))
              /* Open the timer device */
          if (!(OpenDevice(TIMERNAME,UNIT_MICROHZ,TimerIO,0)))
              {
              /* Set up pointer for timer functions */
              TimerBase = (struct Library *)TimerIO->tr_node.io_Device;

              ... use functions ...

              /* Close the timer device */
              CloseDevice(TimerIO);
              }

          /* Delete the I/O request */
          DeleteExtIO(TimerIO);
          }

      /* Delete the message port */
      DeletePort(TimerMP);
      }
```

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
