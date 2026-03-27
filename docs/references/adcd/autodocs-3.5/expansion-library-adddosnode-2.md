---
title: expansion.library/AddDosNode
manual: autodocs-3.5
chapter: autodocs-3.5
section: expansion-library-adddosnode-2
functions: [Enqueue]
libraries: [exec.library]
---

# expansion.library/AddDosNode

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AddDosNode -- mount a disk to the system

   SYNOPSIS
	ok = AddDosNode( bootPri, flags, deviceNode )
	D0		 D0	  D1	 A0

	[BOOL](autodocs-3.5/include-exec-types-h.md) AddDosNode( [BYTE](autodocs-3.5/include-exec-types-h.md),ULONG,struct [DeviceNode](autodocs-3.5/include-dos-filehandler-h.md) *);

   FUNCTION
	This is the old (pre V36) function that works just like
	[AddBootNode()](autodocs-3.5/expansion-library-addbootnode-2.md).  It should only be used if you *MUST* work
	in a 1.3 system and you don't need to autoboot.

   RESULTS
	ok - non-zero everything went ok, zero if we ran out of memory
	    or some other weirdness happened.

   EXAMPLE
	/* enter a bootable disk into the system.  Start a file handler
	** process immediately.
	*/
	if(  AddDosNode( 0, ADNF_STARTPROC, MakeDosNode( paramPacket ) )  )
		...AddDosNode ok...

   BUGS
	Before V36 Kickstart, no function existed to add BOOTNODES.
	If an older expansion.library is in use, driver code will need
	to manually construct a [BootNode](autodocs-3.5/include-libraries-expansionbase-h.md) and [Enqueue()](autodocs-3.5/exec-library-enqueue-2.md) it to eb_Mountlist.
	If you have a V36 or better expansion.library, your code should
	use [AddBootNode()](autodocs-3.5/expansion-library-addbootnode-2.md).

   SEE ALSO
	[MakeDosNode()](autodocs-3.5/expansion-library-makedosnode-2.md), [AddBootNode()](autodocs-3.5/expansion-library-addbootnode-2.md)

---

## See Also

- [Enqueue — exec.library](../autodocs/exec.library.md#enqueue)
