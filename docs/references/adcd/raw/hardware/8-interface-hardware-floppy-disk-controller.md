# 8 Interface Hardware / Floppy Disk Controller


The built-in disk controller in the system can handle up to four MFM-type
devices.  Typically these are double-sided, double-density, 3.5" (90mm) or
5.25" disk drives.  One 3.5" drive is installed in the basic unit.

The controller is extremely flexible.  It can DMA an entire track of raw
MFM data into memory in a single disk revolution.  Special registers allow
the CPU to synchronize with specific data, or read input a byte at a time.
The controller can read and write virtually any double-density MFM encoded
disk, including the Amiga V1.0 format, IBM PC (MS-DOS) 5.25", IBM PC
(MS-DOS) 3.5" and most CP/M (TM) formatted disks.  The controller has
provisions for reading and writing most disk using the Group Coded
Recording (GCR) method, including Apple II (TM) disks.  With motor speed
tricks, the controller can read and write Commodore 1541/1571 format
diskettes.

 [Registers Used by the Disk Subsystem](../Hardware_Manual_guide/node018D.html) 
 [Disk Subsystem Timing](../Hardware_Manual_guide/node018E.html) 
 [Disk Interrupts](../Hardware_Manual_guide/node0196.html) 

