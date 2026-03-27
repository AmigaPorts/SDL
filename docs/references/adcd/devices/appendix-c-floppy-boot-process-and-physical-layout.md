---
title: Appendix C : Floppy Boot Process and Physical Layout
manual: devices
chapter: devices
section: appendix-c-floppy-boot-process-and-physical-layout
functions: []
libraries: []
---

# Appendix C : Floppy Boot Process and Physical Layout

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The first two sectors on each floppy disk contain special boot
information. These sectors are read into the system at an arbitrary
position; therefore, the code must be position independent.  The first
three longwords come from the include file devices/bootblock.h. The type
must be BBID_DOS; the checksum must be correct (an additive carry
wraparound sum of 0xffffffff). Execution starts at location 12 of the
first sector read in.

The code is called with an open trackdisk.device I/O request pointer in A1
(see the ``Trackdisk'' chapter for more information). The boot code is
free to use the IO request as it wishes (the code may trash A1, but must
not trash the I/O request itself).

The boot code must return values in two registers:  D0 and A0. D0 is a
failure code - if it is non-zero then a system alert will be called, and
the system will reboot.

If D0 is zero then A0 must contain the start address to jump to.  The
strap module will free the boot sector memory, free the boot picture
memory, close the trackdisk.device I/O request, do any other cleanup that
is required, then jump to the location pointed to by A0.

Boot code may allocate memory, use trackdisk.device to load relocatable
information into the memory, then return with D0=0 and A0 pointing to
code. The system will clean up, then call the code.

 [Commodore-Amiga Disk Format](devices/appendix-c-commodore-amiga-disk-format.md) 
 [MFM Track Encoding](devices/appendix-c-mfm-track-encoding.md) 

