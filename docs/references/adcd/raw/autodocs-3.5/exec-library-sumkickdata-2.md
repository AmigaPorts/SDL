# exec.library/SumKickData



   NAME
	SumKickData -- compute the checksum for the Kickstart delta list

   SYNOPSIS
	checksum = SumKickData()
	D0

	ULONG SumKickData(void);

   FUNCTION
	The Amiga system has some ROM (or Kickstart) resident code that
	provides the basic functions for the machine.  This code is
	unchangeable by the system software.  This function is part of a
	support system to modify parts of the ROM.

	The ROM code is linked together at run time via ROMTags (also known
	as [Resident](../Includes_and_Autodocs_3._guide/node0643.html#line17) structures, defined in [exec/resident.h)](../Includes_and_Autodocs_3._guide/node0643.html).  These tags tell
	Exec's low level boot code what subsystems exist in which regions of
	memory.  The current list of ROMTags is contained in the ResModules
	field of [ExecBase](../Includes_and_Autodocs_3._guide/node0609.html#line33).  By default this list contains any ROMTags found
	in the address ranges $F80000-$FFFFFF and $F00000-$F7FFFF.

	There is also a facility to selectively add or replace modules to the
	ROMTag list.  These modules can exist in RAM, and the memory they
	occupy will be deleted from the memory free list during the boot
	process.  SumKickData() plays an important role in this run-time
	modification of the ROMTag array.

	Three variables in [ExecBase](../Includes_and_Autodocs_3._guide/node0609.html#line33) are used in changing the ROMTag array:
	KickMemPtr, KickTagPtr, and KickCheckSum. KickMemPtr points to a
	linked list of [MemEntry](../Includes_and_Autodocs_3._guide/node062D.html#line39) structures. The memory that these [MemEntry](../Includes_and_Autodocs_3._guide/node062D.html#line39)
	structures reference will be allocated (via AllocAbs) at boot time.
	The [MemEntry](../Includes_and_Autodocs_3._guide/node062D.html#line39) structure itself must also be in the list.

	KickTagPtr points to a long-word array of the same format as the
	ResModules array.  The array has a series of pointers to ROMTag
	structures.  The array is either NULL terminated, or will have an
	entry with the most significant bit (bit 31) set.  The most
	significant bit being set says that this is a link to another
	long-word array of ROMTag entries.  This new array's address can be
	found by clearing bit 31.

	KickCheckSum has the result of SumKickData().  It is the checksum of
	both the KickMemPtr structure and the KickTagPtr arrays.  If the
	checksum does not compute correctly then both KickMemPtr and
	KickTagPtr will be ignored.

	If all the memory referenced by KickMemPtr can't be allocated then
	KickTagPtr will be ignored.

	There is one more important caveat about adding ROMTags. All this
	ROMTag magic is run very early on in the system -- before expansion
	memory is added to the system. Therefore any memory in this
	additional ROMTag area must be addressable at this time. This means
	that your ROMTag code, [MemEntry](../Includes_and_Autodocs_3._guide/node062D.html#line39) structures, and resident arrays
	cannot be in expansion memory.  There are two regions of memory that
	are acceptable:  one is chip memory, and the other is "Ranger" memory
	(memory in the range between $C00000-$D80000).

	[Remember](../Includes_and_Autodocs_3._guide/node05E0.html#line1429) that changing an existing ROMTag entry falls into the
	"heavy magic" category -- be very careful when doing it.  The odd are
	that you will blow yourself out of the water.

   NOTE
	SumKickData was introduced in the 1.2 release

   RESULT
	Value to be stuffed into ExecBase->KickCheckSum.

   WARNING
	After writing to KickCheckSum, you should push the data cache.
	This prevents potential problems with large copyback style caches.
	A call to [CacheClearU](../Includes_and_Autodocs_3._guide/node01F0.html) will do fine.

   SEE ALSO
	[InitResident()](../Includes_and_Autodocs_3._guide/node0216.html), [FindResident()](../Includes_and_Autodocs_3._guide/node0209.html)

