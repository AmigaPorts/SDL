---
title: 15 / Misc Resource / C Example Of Allocating Misc Resources
manual: devices
chapter: devices
section: 15-misc-resource-c-example-of-allocating-misc-resources
functions: [Forbid, Permit]
libraries: [exec.library]
---

# 15 / Misc Resource / C Example Of Allocating Misc Resources

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
     [Allocate_Misc.c](devices/devices-dev-examples-allocate-misc-c.md) 
```
The example below will try to open the serial device and execute the
SDCMD_QUERY command.  If it cannot open the serial device, it will do an
[AllocMiscResource()](autodocs-2.0/misc-resource-allocmiscresource.md) on the serial port and return the name of the owner.


```c
     [Query_Serial.c](devices/devices-dev-examples-query-serial-c.md) 
```
   Take Over Everything.
   ---------------------
   There are two serial.device resources to take over, MR_SERIALBITS and
   MR_SERIALPORT.  You should get both resources when you take over the
   serial port to prevent other tasks from using them.  The
   parallel.device also has two resources to take over.  See the
   resources/[misc.h](autodocs-2.0/includes-resources-misc-h.md) include file for the relevant definitions and
   structures.

Under V1.3 and earlier versions of the Amiga system software the
MR_GETMISCRESOURCE routine will always fail if the serial device has been
used at all by another task (even if that task has finished using the
resource.  In other words, once a printer driver or communication package
has been activated, it will keep the associated resource locked up
preventing your task from using it. Under these conditions, you must get
the resource back from the system yourself.

You do this by calling the function FlushDevice() as follows:

/*
 * A safe way to expunge ONLY a certain device.  The serial.device holds
 * on to the misc serial resource until a general expunge occurs.
 * This code attempts to flush ONLY the named device out of memory and
 * nothing else.  If it fails, no status is returned since it would have
 * no valid use after the Permit().
 */

#include <exec/types.h>
#include <exec/execbase.h>

#include <clib/exec_protos.h>

void FlushDevice(char *);

extern struct ExecBase *SysBase;

void FlushDevice(char *name)
{
struct Device *devpoint;

Forbid();

if (devpoint=(struct Device *)FindName(&SysBase->DeviceList,name) )

```c
    RemDevice(devpoint);
```
Permit();
}

Additional programming information on the misc resource can be found in
the include files and the Autodocs for the misc resource.




```c
                       Misc Resource Information
                    ---------------------------------
                    INCLUDES        resources/[misc.h](autodocs-2.0/includes-resources-misc-h.md)
                                    resources/[misc.i](autodocs-2.0/includes-resources-misc-i.md)
                                    hardware/[custom.h](autodocs-2.0/includes-hardware-custom-h.md)
                                    hardware/[custom.i](autodocs-2.0/includes-hardware-custom-i.md)
                    AUTODOCS        [misc.doc](autodocs-2.0/misc-doc.md)
```

---

## See Also

- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [Permit — exec.library](../autodocs/exec.library.md#permit)
