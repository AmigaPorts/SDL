---
title: Devices/ramdev-mountlist
manual: devices
chapter: devices
section: devices-ramdev-mountlist
functions: []
libraries: []
---

# Devices/ramdev-mountlist

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/*
 * Mountlist for manually mounting the sample ramdisk driver.
 *
 * F0: and F1: are set up for the V1.3 fast file system (FFS).
 * S2: and S3: are setup for the old file system (OFS).
 *
 * After mounting, the drives must be formatted.  Be sure to
 * use the FFS flag when formatting the Fast File System
 * ramdrives:
 *
 *	;make sure "ramdev.device" is in DEVS:
 *
 *	mount f0: from mydev-mountlist
 *	format drive f0: name "Zippy" FFS
 */
F0:	   Device = ramdev.device
	   Unit   = 0
	   LowCyl = 0 ; HighCyl = 14
	   Surfaces  = 1
	   Buffers = 1
	   BlocksPerTrack = 10
	   Flags  = 0
	   Reserved = 2
	   GlobVec = -1
	   BufMemType = 0
	   DosType = 0x444F5301
	   StackSize = 4000
	   FileSystem = l:fastfilesystem
#
F1:	   Device = ramdev.device
	   Unit   = 1
	   LowCyl = 0 ; HighCyl = 14
	   Surfaces  = 1
	   Buffers = 1
	   BlocksPerTrack = 10
	   Flags  = 0
	   Reserved = 2
	   GlobVec = -1
	   BufMemType = 0
	   DosType = 0x444F5301
	   StackSize = 4000
	   FileSystem = l:fastfilesystem
#
S2:	   Device = ramdev.device
	   Unit   = 2
	   Flags  = 0
	   Surfaces  = 1
	   BlocksPerTrack = 10
	   Reserved = 1
	   Interleave = 0
	   LowCyl = 0  ;  HighCyl = 14
	   Buffers = 1
	   BufMemType = 0
#
S3:	   Device = ramdev.device
	   Unit   = 3
	   Flags  = 0
	   Surfaces  = 1
	   BlocksPerTrack = 10
	   Reserved = 1
	   Interleave = 0
	   LowCyl = 0  ;  HighCyl = 14
	   Buffers = 1
	   BufMemType = 0
#

