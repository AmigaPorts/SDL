# 12 Serial Device / Taking Over the Hardware


For some applications use of the device driver interface is not possible.
By following the established rules, applications may take over the serial
interface at the hardware level.  This extreme step is not, however,
encouraged.  Taking over means losing the ability to work with additional
serial ports, and will limit future compatibility.

Access to the hardware registers is controlled by the misc.resource. See
the "[Resources](../Devices_Manual_guide/node0110.html)" chapter, and exec/[misc.i](../Includes_and_Autodocs_2._guide/node0111.html) for details.  The MR_SERIALBITS
and MR_SERIALPORT units control the serial registers.

One additional complication exists.  The current serial device will not
release the misc.resource bits until after an expunge.  This code provides
a work around:

   /*
   * A safe way to expunge ONLY a certain device.
   * This code attempts to flush ONLY the named device out of memory and
   * nothing else.  If it fails, no status is returned (the information
   * would have no valid use after the Permit().
   */
   #include <exec/types.h>
   #include <exec/execbase.h>

   void FlushDevice(char *);

   extern struct ExecBase *SysBase;

   void FlushDevice(name)
   char  *name;
   {
   struct Device *devpoint;

   Forbid();   /* ugly */
   if (devpoint = (struct Device *)FindName(&SysBase->DeviceList,name) )
```c
       RemDevice(devpoint);
```
   Permit();
   }

