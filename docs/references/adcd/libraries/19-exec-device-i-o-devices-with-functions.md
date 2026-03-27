---
title: 19 Exec Device I/O / Devices With Functions
manual: libraries
chapter: libraries
section: 19-exec-device-i-o-devices-with-functions
functions: [CmpTime, OpenDevice]
libraries: [exec.library, timer.device]
---

# 19 Exec Device I/O / Devices With Functions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Some devices, in addition to their commands, provide library-style
functions which can be directly called by applications.  These functions
are documented in the device specific FD files and Autodocs of the Amiga
ROM Kernel Reference Manual: [Includes and Autodocs](autodocs-2.0/includes-and-autodocs-2-0.md), and in the [Devices](devices/contents-2.md)
volume of this manual set.

Devices with functions behave much like Amiga libraries, i.e., you set up
a base address pointer and call the functions as offsets from the pointer.
See the "[Exec Libraries](libraries/18-what-is-a-library-changing-the-contents-of-a-library.md)" chapter for more information.

The procedure for accessing a device's functions is as follows:

  * Declare the device base address variable in the global data area.

    The correct name for the base address can be found in the device's FD
    file.
  * Create a message port data structure.

  * Create an I/O request data structure.

  * Call [OpenDevice()](libraries/19-accessing-a-device-opening-a-device.md), passing the I/O request.  If OpenDevice() is

```c
    successful (returns 0), the address of the device base may be found
    in the [io_Device](autodocs-2.0/includes-exec-io-h.md) field of the I/O request structure. Consult the
    include file for the structure you are using to determine the full
    name of the io_Device field.  The base address is only valid while
    the device is open.
```
  * Set the device base address variable to the pointer returned in the

```c
    [io_Device](autodocs-2.0/includes-exec-io-h.md) field.
```
We will use the timer device to illustrate the above method.  The name of
the timer device base address is listed in its FD file as TimerBase.


#include <devices/[timer.h](autodocs-2.0/includes-devices-timer-h.md)>

struct Library *TimerBase;            /* device base address pointer */
struct MsgPort *TimerMP;              /* message port pointer        */
struct timerequest *TimerIO;          /* I/O request pointer         */

if (TimerMP=CreatePort(NULL,NULL))    /* Create the message port.    */
{
```c
    /* Create the I/O request.  */
    if ( TimerIO = (struct timerequest *)
         CreateExtIO(TimerMP,sizeof(struct timerequest)) )
    {
        /* Open the timer device.  */
        if ( !(OpenDevice(TIMERNAME,UNIT_MICROHZ,TimerIO,0)) )
        {
            /* Set up pointer for timer functions.  */
            TimerBase = (struct Library *)TimerIO->tr_node.io_Device;

            /* Use timer device library-style functions such as /*
            /* CmpTime() ...*/

            CloseDevice(TimerIO);     /* Close the timer device. */
        }
        else
            printf("Error: Could not open %s\n",TIMERNAME);
    }
    else
        printf("Error: Could not create I/O request\n");
```
}
else
```c
    printf("Error: Could not create message port\n");
```
}

---

## See Also

- [CmpTime — timer.device](../autodocs/timer.device.md#cmptime)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
