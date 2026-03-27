# 15 / Misc Resource / C Example Of Allocating Misc Resources




```c
     [Allocate_Misc.c](../Devices_Manual_guide/node01A6.html) 
```
The example below will try to open the serial device and execute the
SDCMD_QUERY command.  If it cannot open the serial device, it will do an
[AllocMiscResource()](../Includes_and_Autodocs_2._guide/node054D.html) on the serial port and return the name of the owner.


```c
     [Query_Serial.c](../Devices_Manual_guide/node01A7.html) 
```
   Take Over Everything.
   ---------------------
   There are two serial.device resources to take over, MR_SERIALBITS and
   MR_SERIALPORT.  You should get both resources when you take over the
   serial port to prevent other tasks from using them.  The
   parallel.device also has two resources to take over.  See the
   resources/[misc.h](../Includes_and_Autodocs_2._guide/node010E.html) include file for the relevant definitions and
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
                    INCLUDES        resources/[misc.h](../Includes_and_Autodocs_2._guide/node010E.html)
                                    resources/[misc.i](../Includes_and_Autodocs_2._guide/node0111.html)
                                    hardware/[custom.h](../Includes_and_Autodocs_2._guide/node00CD.html)
                                    hardware/[custom.i](../Includes_and_Autodocs_2._guide/node00D0.html)
                    AUTODOCS        [misc.doc](../Includes_and_Autodocs_2._guide/node054C.html)
```
