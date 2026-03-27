---
title: 15 Resources / The Amiga Resources
manual: devices
chapter: devices
section: 15-resources-the-amiga-resources
functions: []
libraries: []
---

# 15 Resources / The Amiga Resources

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

There are currently seven standard resources in the Amiga system.  The
following lists the name of each resource and its function.

[battclock.resource](devices/15-resources-battclock-resource.md)
   grants access to the battery-backed clock chip.

[battmem.resource](devices/15-resources-battmem-resource.md)
   grants access to non-volatile RAM.

[cia.resource](devices/15-resources-cia-resource.md)
   grants access to the interrupts and timer bits of the 8520 CIA
   (Complex Interface Adapter) chips.

[disk.resource](devices/15-resources-disk-resource.md)
   grants temporary exclusive access to the disk hardware.

[FileSystem.resource](devices/15-resources-filesystem-resource.md)
   grants access to the file system.

[misc.resource](devices/15-resources-misc-resource.md)
   grants exclusive access to functional blocks of chip registers.  At
   present, definitions have been made for the serial and parallel
   hardware only.

[potgo.resource](devices/15-resources-potgo-resource.md)
   manages the bits of the proportional I/O pins on the game controller
   ports.

The resources allow you direct access to the hardware in a way that is
compatible with multitasking.  They also allow you to temporarily bar
other tasks from using the resource.  You may then use the associated
hardware directly for your special purposes.  If applicable, you must
return the resource back to the system for other tasks to use when you are
finished with it.

See the [Amiga Hardware Reference Manual](hardware/amiga-hardware-reference-manual-contents.md) for detailed information on the
actual hardware involved.

   Look Before You Leap.
   ---------------------
   Resources are just one step above direct hardware manipulation. You
   are advised to try the higher level device and library approach
   before resorting to the hardware.

