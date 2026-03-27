---
title: 14 / Device Interface / About Amiga Floppy Disks
manual: devices
chapter: devices
section: 14-device-interface-about-amiga-floppy-disks
functions: []
libraries: []
---

# 14 / Device Interface / About Amiga Floppy Disks

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The standard 3.5 inch Amiga floppy disk consists of a number of tracks
that are NUMSECS (11) sectors of TD_SECTOR (512) usable data bytes plus
TD_LABELSIZE (16) bytes of label area. There are usually 2 tracks per
cylinder (2 heads) and 80 cylinders per disk.  The number of tracks can be
found using the [TD_GETNUMTRACKS](autodocs-2.0/trackdisk-device-td-getnumtracks.md) command.

For V36 and higher systems, the NUMSECS in some drives may be variable and
may change when a disk is inserted.  Use [TD_GETGEOMETRY](autodocs-2.0/trackdisk-device-td-getgeometry.md) to determine the
current number of sectors.

   Think Tracks not Cylinders.
   ---------------------------
   The result is given in tracks and not cylinders. On a standard 3.5"
   drive, this gives useful space of 880K bytes plus 28K bytes of sector
   label area per floppy disk.

Although the disk is logically divided up into sectors, all I/O to the
disk is done a track at a time. This allows access to the drive with no
interleaving and increases the useful storage capacity by about 20
percent.  Each disk drive on the system has its own buffer which holds the
track data going to and from the drive.

Normally, a read of a sector will only have to copy the data from the
track buffer. If the track buffer contains another track's data, then the
buffer will first be written back to the disk (if it is "dirty") and the
new track will be read in.  All track boundaries are transparent to the
programmer (except for FORMAT, SEEK, and RAWREAD/RAWWRITE commands)
because you give the device an offset into the disk in the number of bytes
from the start of the disk. The device ensures that the correct track is
brought into memory.

The performance of the disk is greatly enhanced if you make effective use
of the track buffer. The performance of sequential reads will be up to an
order of magnitude greater than reads scattered across the disk. In
addition, only full-sector writes on sector boundaries are supported.

The trackdisk device is based upon a standard device structure. It has the
following restrictions:

   *  All reads and writes must use an io_Length that is an integer

```c
      multiple of TD_SECTOR bytes (the sector size in bytes).
```
   *  The offset field must be an integer multiple of TD_SECTOR.

   *  The data buffer must be word-aligned.

   *  Under pre-V36, the data buffer must be also be in Chip RAM.

