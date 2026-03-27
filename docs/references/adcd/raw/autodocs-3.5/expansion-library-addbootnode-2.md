# expansion.library/AddBootNode



   NAME
	AddBootNode -- Add a BOOTNODE to the system (V36)

   SYNOPSIS
	ok = AddBootNode( bootPri, flags, deviceNode, configDev )
	D0		  D0	   D1	  A0	      A1

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) AddBootNode( [BYTE](../Includes_and_Autodocs_3._guide/node0654.html#line48),ULONG,struct [DeviceNode](../Includes_and_Autodocs_3._guide/node05FD.html#line95) *,struct [ConfigDev](../Includes_and_Autodocs_3._guide/node05F1.html#line31) * );

   FUNCTION
	This function will do one of two things:

		1> If dos is running, add a new disk type device immediatly.
		2> If dos is not yet running, save information for later
		   use by the system.

   FUNCTION
	This routine makes sure that your disk device (or a device
	that wants to be treated as if it was a disk...) will be
	entered into the system.  If the dos is already up and
	running, then it will be entered immediately.  If the dos
	has not yet been run then the data will be recorded, and the
	dos will get it later.

	We try and boot off of each device in turn, based on priority.
	Floppies have a hard-coded priority.

	There is only one additional piece of magic done by AddBootNode.
	If there is no executable code specified in the deviceNode
	structure (e.g. dn_SegList, dn_Handler, and dn_Task are all
	null) then the standard dos file handler is used for your
	device.

	Documentation note: a "task" as used here is a dos-task, not
	an exec-task.  A dos-task, in the strictest sense, is the
	address of an exec-style message port.	In general, it is
	a pointer to a process's pr_MsgPort field (e.g. a constant
	number of bytes after an exec task).

	Autoboot from an expansion card before DOS is running requires
	the card's [ConfigDev](../Includes_and_Autodocs_3._guide/node05F1.html#line31) structure.

	Pass a NULL [ConfigDev](../Includes_and_Autodocs_3._guide/node05F1.html#line31) pointer to create a non-bootable node.

   INPUTS
	bootPri -- a [BYTE](../Includes_and_Autodocs_3._guide/node0654.html#line48) quantity with the boot priority for this disk.
	    This priority is only for which disks should be looked at:
	    the actual disk booted from will be the first disk with
	    a valid boot block.  If no disk is found then the "bootme"
	    hand will come up and the bootstrap code will wait for
	    a floppy to be inserted.  Recommend priority assignments are:

		+5   -- unit zero for the floppy disk.	The floppy should
			always be highest priority to allow the user to
			abort out of a hard disk boot.
		 0   -- the run of the mill hard disk
		-5   -- a "network" disk (local disks should take priority).
		-128 -- don't even bother to boot from this device.

	flags -- additional flag bits for the call:
	    ADNF_STARTPROC (bit 0) -- start a handler process immediately.
		Normally the process is started only when the device node
		is first referenced.  This bit is meaningless if you
		have already specified a handler process (non-null dn_Task).

	deviceNode -- a legal DOS device node, properly initialized.
		Typically this will be the result of a [MakeDosNode()](../Includes_and_Autodocs_3._guide/node0266.html).
		Special cases may require a custom-built device node.

	configDev -- a valid board's [ConfigDev](../Includes_and_Autodocs_3._guide/node05F1.html#line31) structure.  This is required
		for autoboot before DOS is running and if left NULL will
		result in an non-bootable node.

   RESULTS
	ok - non-zero everything went ok, zero if we ran out of memory
	    or some other weirdness happened.

   NOTE
	This function eliminates the need to manually [Enqueue](../Includes_and_Autodocs_3._guide/node0206.html) a BOOTNODE
	onto an expansion.library list.  Be sure V36 expansion.library is
	available before calling this function!

   SEE ALSO
	[AddDosNode()](../Includes_and_Autodocs_3._guide/node025E.html)

