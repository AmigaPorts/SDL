---
title: disk.resource/GetUnit
manual: autodocs-3.5
chapter: autodocs-3.5
section: disk-resource-getunit-2
functions: []
libraries: []
---

# disk.resource/GetUnit

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       GetUnit - allocate the disk for a driver
   SYNOPSIS

```c
       lastDriver = GetUnit( unitPointer ), DRResource
       D0		      A1             A6
```
	struct [DiscResourceUnit](autodocs-3.5/include-resources-disk-h.md) *GetUnit(struct [DiscResourceUnit](autodocs-3.5/include-resources-disk-h.md) *);

   FUNCTION
	This routine allocates the disk to a driver.  It is either
	immediately available, or the request is saved until the disk
	is available.  When it is available, your unitPointer is
	sent back to you (via ReplyMsg).  You may then reattempt the
	GetUnit.

	Allocating the disk allows you to use the disk's resources.
	[Remember](autodocs-3.5/include-intuition-intuition-h.md) however that there are four units to the disk; you are
	only one of them.  Please be polite to the other units (by never
	selecting them, and by not leaving interrupts enabled, etc.).

	When you are done, please leave the disk in the following state:
	    dmacon dma bit ON
	    dsklen dma bit OFF (write a #DSKDMAOFF to dsklen)
	    adkcon disk bits -- any way you want
	    intena:disk sync and disk block interrupts -- Both DISABLED
	    [CIA](autodocs-3.5/include-hardware-cia-h.md) resource index interrupt -- DISABLED
	    8520 outputs -- doesn't matter, because all bits will be
		set to inactive by the resource.
	    8520 data direction regs -- restore to original state.

	NOTE: GetUnit() does NOT turn on the interrupts for you.
	      You must use [AbleICR](autodocs-3.5/cia-resource-ableicr-2.md) (for the index interrupt) or intena
	      (for the diskbyte and diskblock interrupts) to turn them
	      on.  You should turn them off before calling [GiveUnit](autodocs-3.5/disk-resource-giveunit-2.md),
	      as stated above.

   INPUTS
	unitPtr - a pointer you your disk resource unit structure.
		Note that the message filed of the structure MUST
		be a valid message, ready to be replied to.  Make sure
		ln_Name points to a null-terminated string, preferably
		one that identifies your program.

		You need to set up the three interrupt structures,
		in particular the IS_DATA and IS_CODE fields.  Set them
		to NULL if you don't need that interrupt.  Also, set
		the ln_Type of the interrupt structure to NT_INTERRUPT.
		WARNING: don't turn on a disk resource interrupt unless
		the IS_CODE for that interrupt points to executable code!

		IS_CODE will be called with IS_DATA in A1 when the
		interrupt occurs.  Preserve all regs but D0/D1/A0/A1.
		Do not make assumptions about A0.

   RESULTS
	lastDriver - if the disk is not busy, then the last unit
		to use the disk is returned.  This may be used to
		see if a driver needs to reset device registers.
		(If you were the last user, then no one has changed
		any of the registers.  If someone else has used it,
		then any allowable changes may have been made).  If the
		disk is busy, then a null is returned.

   EXCEPTIONS

   SEE ALSO
	[GiveUnit()](autodocs-3.5/disk-resource-giveunit-2.md)

   BUGS

