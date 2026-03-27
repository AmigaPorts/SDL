# nonvolatile.library/--background--



   PURPOSE
	The nonvolatile library provides a simple means for an application
	developer to manage nonvolatile storage.

   OVERVIEW
	The nonvolatile library is meant to be used transparently across all
	configurations. Currently, nonvolatile storage may consist of NVRAM
	and/or disk devices. nonvolatile.library will automatically
	access the best nonvolatile storage available in the system. Disk
	based storage will be selected first and if not available, NVRAM
	storage will be accessed.

	* NVRAM

	On low-end diskless Amiga platforms, NVRAM may be available. This
	RAM will maintain its data contents when the system is powered down.
	This is regardless of whether batteries or battery-backed clock are
	present. The data stored in NVRAM is accessible only through the
	ROM-based nonvolatile library funtion calls. The size of NVRAM
	storage	is dependant on the system platform and is attainable through
	the [GetNVInfo()](../Includes_and_Autodocs_3._guide/node04DF.html) function.

	* Disk

	In keeping with the general configurability of the Amiga, the actual
	disk location used by nonvolatile library when storing to disk may be
	changed by the user.

	The prefs directory is used on the Amiga for storing many user
	configurable options. The location for nonvolatile disk storage
	is contained in the file prefs/env-archive/sys/nv_location. This
	file should contain a data string that specifies a lockable location.
	If the string does not specify a lockable location, the file will
	be ignored.

	When opened, the nonvolatile library will search all drives within
	the system until it finds this file and successfully accomplishes
	a [Lock](../Includes_and_Autodocs_3._guide/node0186.html) on the location specified in the file. To force a rescan of
	all drives, the library may be closed and reopened or execute the
	[GetNVInfo()](../Includes_and_Autodocs_3._guide/node04DF.html) function.

	A simple method for creating a floppy disk for saving nonvolatile
	data is the following:

	[Format](../Includes_and_Autodocs_3._guide/node016B.html) a disk with the volume name NV
	Create a file prefs/env-archive/sys/nv_location on this disk with
	  the following contents:  NV:nonvolatile
	Create a directory nonvolatile

	The following is a script file that can be used to make a floppy
	for use with nonvolatile library:

	.KEY DRIVE/A,DISK
	.BRA {
	.KET }
	format Drive {DRIVE} Name {DISK$NV} noicons ffs
	makedir {DRIVE}prefs
	makedir {DRIVE}nonvolatile
	makedir {DRIVE}prefs/env-archive
	makedir {DRIVE}prefs/env-archive/sys
	echo {DISK$NV}:nonvolatile >{DRIVE}prefs/env-archive/sys/nv_location

	!!!NOTE!!!

	Because NVRAM performs disk access, you must open and use its
	functionality from a DOS process, not an EXEC task.  Normally
	your CDGS application is invoked as a DOS process so this
	requirement generally should cause you no concern.  You just
	need to be aware of this requirement should you create an
	EXEC task and try to invoke nonvolatile.library from that task.

