# 15 Resources / The Amiga Resources


There are currently seven standard resources in the Amiga system.  The
following lists the name of each resource and its function.

[battclock.resource](../Devices_Manual_guide/node010B.html)
   grants access to the battery-backed clock chip.

[battmem.resource](../Devices_Manual_guide/node010C.html)
   grants access to non-volatile RAM.

[cia.resource](../Devices_Manual_guide/node010D.html)
   grants access to the interrupts and timer bits of the 8520 CIA
   (Complex Interface Adapter) chips.

[disk.resource](../Devices_Manual_guide/node010E.html)
   grants temporary exclusive access to the disk hardware.

[FileSystem.resource](../Devices_Manual_guide/node010F.html)
   grants access to the file system.

[misc.resource](../Devices_Manual_guide/node0110.html)
   grants exclusive access to functional blocks of chip registers.  At
   present, definitions have been made for the serial and parallel
   hardware only.

[potgo.resource](../Devices_Manual_guide/node0112.html)
   manages the bits of the proportional I/O pins on the game controller
   ports.

The resources allow you direct access to the hardware in a way that is
compatible with multitasking.  They also allow you to temporarily bar
other tasks from using the resource.  You may then use the associated
hardware directly for your special purposes.  If applicable, you must
return the resource back to the system for other tasks to use when you are
finished with it.

See the [Amiga Hardware Reference Manual](../Hardware_Manual_guide/node0000.html) for detailed information on the
actual hardware involved.

   Look Before You Leap.
   ---------------------
   Resources are just one step above direct hardware manipulation. You
   are advised to try the higher level device and library approach
   before resorting to the hardware.

